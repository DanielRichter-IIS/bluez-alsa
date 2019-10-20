/*
 * BlueALSA - hci.c
 * Copyright (c) 2016-2019 Arkadiusz Bokowy
 *
 * This file is a part of bluez-alsa.
 *
 * This project is licensed under the terms of the MIT license.
 *
 */

#include "hci.h"

#include <errno.h>
#include <sys/socket.h>
#include <unistd.h>

#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>
#include <bluetooth/sco.h>

/**
 * Get HCI local version (e.g. chip manufacturer).
 *
 * @param dev_id The ID of the HCI device.
 * @param ver Pointer to the HCI version structure for output data.
 * @return On success this function returns 0. Otherwise, -1 is returned
 *   and errno is set to indicate the error. */
int hci_get_version(int dev_id, struct hci_version *ver) {

	int dd;

	if ((dd = hci_open_dev(dev_id)) == -1)
		return -1;

	if (hci_read_local_version(dd, ver, 1000) == -1) {
		hci_close_dev(dd);
		return -1;
	}

	hci_close_dev(dd);
	return 0;
}

/**
 * Open SCO link for given Bluetooth device.
 *
 * @param dev_id The ID of the HCI device for which the SCO link should be
 *   established.
 * @param ba Pointer to the Bluetooth address structure for a target device.
 * @param transparent Use transparent mode for voice transmission.
 * @return On success this function returns socket file descriptor. Otherwise,
 *   -1 is returned and errno is set to indicate the error. */
int hci_open_sco(int dev_id, const bdaddr_t *ba, bool transparent) {

	struct sockaddr_sco addr_hci = {
		.sco_family = AF_BLUETOOTH,
	};
	struct sockaddr_sco addr_dev = {
		.sco_family = AF_BLUETOOTH,
		.sco_bdaddr = *ba,
	};
	int dd, err;

	if (hci_devba(dev_id, &addr_hci.sco_bdaddr) == -1)
		return -1;
	if ((dd = socket(PF_BLUETOOTH, SOCK_SEQPACKET, BTPROTO_SCO)) == -1)
		return -1;
	if (bind(dd, (struct sockaddr *)&addr_hci, sizeof(addr_hci)) == -1)
		goto fail;

	if (transparent) {
		struct bt_voice voice = {
			.setting = BT_VOICE_TRANSPARENT,
		};
		if (setsockopt(dd, SOL_BLUETOOTH, BT_VOICE, &voice, sizeof(voice)) == -1)
			goto fail;
	}

	if (connect(dd, (struct sockaddr *)&addr_dev, sizeof(addr_dev)) == -1)
		goto fail;

	return dd;

fail:
	err = errno;
	close(dd);
	errno = err;
	return -1;
}

/**
 * Broadcom vendor HCI command for reading SCO routing configuration. */
int hci_bcm_read_sco_pcm_params(int dd, uint8_t *routing, uint8_t *rate,
		uint8_t *frame, uint8_t *sync, uint8_t *clock, int to) {

	struct __attribute__ ((packed)) {
		uint8_t status;
		uint8_t sco_routing;
		uint8_t pcm_interface_rate;
		uint8_t pcm_frame_type;
		uint8_t pcm_sync_mode;
		uint8_t pcm_clock_mode;
	} rp;

	struct hci_request rq = {
		.ogf = OGF_VENDOR_CMD,
		.ocf = 0x01D,
		.rparam = &rp,
		.rlen = sizeof(rp),
	};

	if (hci_send_req(dd, &rq, to) < 0)
		return -1;

	if (rp.status) {
		errno = EIO;
		return -1;
	}

	if (routing != NULL)
		*routing = rp.sco_routing;
	if (rate != NULL)
		*rate = rp.pcm_interface_rate;
	if (frame != NULL)
		*frame = rp.pcm_frame_type;
	if (sync != NULL)
		*sync = rp.pcm_sync_mode;
	if (clock != NULL)
		*clock = rp.pcm_clock_mode;

	return 0;
}

/**
 * Broadcom vendor HCI command for writing SCO routing configuration. */
int hci_bcm_write_sco_pcm_params(int dd, uint8_t routing, uint8_t rate,
		uint8_t frame, uint8_t sync, uint8_t clock, int to) {

	struct __attribute__ ((packed)) {
		uint8_t sco_routing;
		uint8_t pcm_interface_rate;
		uint8_t pcm_frame_type;
		uint8_t pcm_sync_mode;
		uint8_t pcm_clock_mode;
	} cp = { routing, rate, frame, sync, clock };
	uint8_t rp_status;

	struct hci_request rq = {
		.ogf = OGF_VENDOR_CMD,
		.ocf = 0x01C,
		.cparam = &cp,
		.clen = sizeof(cp),
		.rparam = &rp_status,
		.rlen = sizeof(rp_status),
	};

	if (hci_send_req(dd, &rq, to) < 0)
		return -1;

	if (rp_status) {
		errno = EIO;
		return -1;
	}

	return 0;
}

/**
 * Convert Bluetooth address into a human-readable string.
 *
 * This function returns statically allocated buffer. It is not by any means
 * thread safe. This function should be used for debugging purposes only.
 *
 * For debugging purposes, one could use the batostr() function provided by
 * the bluez library. However, this function converts the Bluetooth address
 * to the string with an incorrect (reversed) bytes order...
 *
 * @param ba Pointer to the Bluetooth address structure.
 * @return On success this function returns statically allocated buffer with
 *   human-readable Bluetooth address. On error, it returns NULL. */
const char *batostr_(const bdaddr_t *ba) {
	static char addr[18];
	if (ba2str(ba, addr) > 0)
		return addr;
	return NULL;
}
