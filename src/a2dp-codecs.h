/*
 *
 *  BlueZ - Bluetooth protocol stack for Linux
 *
 *  Copyright (C) 2006-2010  Nokia Corporation
 *  Copyright (C) 2004-2010  Marcel Holtmann <marcel@holtmann.org>
 *  Copyright (C) 2018       Pali Rohár <pali.rohar@gmail.com>
 *  Copyright (C) 2016-2020  Arkadiusz Bokowy
 *
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef BLUEALSA_A2DPCODECS_H_
#define BLUEALSA_A2DPCODECS_H_

#include <endian.h>
#include <stdint.h>

#include "hci.h"

#define A2DP_CODEC_SBC      0x00
#define A2DP_CODEC_MPEG12   0x01
#define A2DP_CODEC_MPEG24   0x02
#define A2DP_CODEC_ATRAC    0x04
#if FHG_USAC_IN_A2DP
#define A2DP_CODEC_MPEGD    0x08
#endif
#define A2DP_CODEC_VENDOR   0xFF

/* Customized (BlueALSA) 16-bit vendor extension. */
#define A2DP_CODEC_VENDOR_APTX          0x4FFF
#define A2DP_CODEC_VENDOR_APTX_AD       0xADFF
#define A2DP_CODEC_VENDOR_APTX_HD       0x24FF
#define A2DP_CODEC_VENDOR_APTX_LL       0xA2FF
#define A2DP_CODEC_VENDOR_APTX_TWS      0x25FF
#define A2DP_CODEC_VENDOR_FASTSTREAM    0xA1FF
#define A2DP_CODEC_VENDOR_LDAC          0x2DFF
#define A2DP_CODEC_VENDOR_LHDC          0x4CFF
#define A2DP_CODEC_VENDOR_LHDC_V1       0x48FF
#define A2DP_CODEC_VENDOR_LLAC          0x44FF
#define A2DP_CODEC_VENDOR_SAMSUNG_HD    0x52FF
#define A2DP_CODEC_VENDOR_SAMSUNG_SC    0x53FF

#define SBC_SAMPLING_FREQ_16000         (1 << 3)
#define SBC_SAMPLING_FREQ_32000         (1 << 2)
#define SBC_SAMPLING_FREQ_44100         (1 << 1)
#define SBC_SAMPLING_FREQ_48000         1

#define SBC_CHANNEL_MODE_MONO           (1 << 3)
#define SBC_CHANNEL_MODE_DUAL_CHANNEL   (1 << 2)
#define SBC_CHANNEL_MODE_STEREO         (1 << 1)
#define SBC_CHANNEL_MODE_JOINT_STEREO   1

#define SBC_BLOCK_LENGTH_4              (1 << 3)
#define SBC_BLOCK_LENGTH_8              (1 << 2)
#define SBC_BLOCK_LENGTH_12             (1 << 1)
#define SBC_BLOCK_LENGTH_16             1

#define SBC_SUBBANDS_4                  (1 << 1)
#define SBC_SUBBANDS_8                  1

#define SBC_ALLOCATION_SNR              (1 << 1)
#define SBC_ALLOCATION_LOUDNESS         1

#define SBC_MIN_BITPOOL                 2
#define SBC_MAX_BITPOOL                 250

/**
 * Predefined SBC bit-pool values.
 *
 * Other settings:
 *  - block length = 16
 *  - allocation method = Loudness
 *  - sub-bands = 8 */
#define SBC_BITPOOL_LQ_MONO_44100          15
#define SBC_BITPOOL_LQ_MONO_48000          15
#define SBC_BITPOOL_LQ_JOINT_STEREO_44100  29
#define SBC_BITPOOL_LQ_JOINT_STEREO_48000  29
#define SBC_BITPOOL_MQ_MONO_44100          19
#define SBC_BITPOOL_MQ_MONO_48000          18
#define SBC_BITPOOL_MQ_JOINT_STEREO_44100  35
#define SBC_BITPOOL_MQ_JOINT_STEREO_48000  33
#define SBC_BITPOOL_HQ_MONO_44100          31
#define SBC_BITPOOL_HQ_MONO_48000          29
#define SBC_BITPOOL_HQ_JOINT_STEREO_44100  53
#define SBC_BITPOOL_HQ_JOINT_STEREO_48000  51

#define MPEG_CHANNEL_MODE_MONO          (1 << 3)
#define MPEG_CHANNEL_MODE_DUAL_CHANNEL  (1 << 2)
#define MPEG_CHANNEL_MODE_STEREO        (1 << 1)
#define MPEG_CHANNEL_MODE_JOINT_STEREO  1

#define MPEG_LAYER_MP1                  (1 << 2)
#define MPEG_LAYER_MP2                  (1 << 1)
#define MPEG_LAYER_MP3                  1

#define MPEG_SAMPLING_FREQ_16000        (1 << 5)
#define MPEG_SAMPLING_FREQ_22050        (1 << 4)
#define MPEG_SAMPLING_FREQ_24000        (1 << 3)
#define MPEG_SAMPLING_FREQ_32000        (1 << 2)
#define MPEG_SAMPLING_FREQ_44100        (1 << 1)
#define MPEG_SAMPLING_FREQ_48000        1

#define MPEG_BIT_RATE_INDEX_0           (1 << 0)
#define MPEG_BIT_RATE_INDEX_1           (1 << 1)
#define MPEG_BIT_RATE_INDEX_2           (1 << 2)
#define MPEG_BIT_RATE_INDEX_3           (1 << 3)
#define MPEG_BIT_RATE_INDEX_4           (1 << 4)
#define MPEG_BIT_RATE_INDEX_5           (1 << 5)
#define MPEG_BIT_RATE_INDEX_6           (1 << 6)
#define MPEG_BIT_RATE_INDEX_7           (1 << 7)
#define MPEG_BIT_RATE_INDEX_8           (1 << 8)
#define MPEG_BIT_RATE_INDEX_9           (1 << 9)
#define MPEG_BIT_RATE_INDEX_10          (1 << 10)
#define MPEG_BIT_RATE_INDEX_11          (1 << 11)
#define MPEG_BIT_RATE_INDEX_12          (1 << 12)
#define MPEG_BIT_RATE_INDEX_13          (1 << 13)
#define MPEG_BIT_RATE_INDEX_14          (1 << 14)

#define MPEG_MP1_BIT_RATE_32000         MPEG_BIT_RATE_INDEX_1
#define MPEG_MP1_BIT_RATE_64000         MPEG_BIT_RATE_INDEX_2
#define MPEG_MP1_BIT_RATE_96000         MPEG_BIT_RATE_INDEX_3
#define MPEG_MP1_BIT_RATE_128000        MPEG_BIT_RATE_INDEX_4
#define MPEG_MP1_BIT_RATE_160000        MPEG_BIT_RATE_INDEX_5
#define MPEG_MP1_BIT_RATE_192000        MPEG_BIT_RATE_INDEX_6
#define MPEG_MP1_BIT_RATE_224000        MPEG_BIT_RATE_INDEX_7
#define MPEG_MP1_BIT_RATE_256000        MPEG_BIT_RATE_INDEX_8
#define MPEG_MP1_BIT_RATE_288000        MPEG_BIT_RATE_INDEX_9
#define MPEG_MP1_BIT_RATE_320000        MPEG_BIT_RATE_INDEX_10
#define MPEG_MP1_BIT_RATE_352000        MPEG_BIT_RATE_INDEX_11
#define MPEG_MP1_BIT_RATE_384000        MPEG_BIT_RATE_INDEX_12
#define MPEG_MP1_BIT_RATE_416000        MPEG_BIT_RATE_INDEX_13
#define MPEG_MP1_BIT_RATE_448000        MPEG_BIT_RATE_INDEX_14

#define MPEG_MP2_BIT_RATE_32000         MPEG_BIT_RATE_INDEX_1
#define MPEG_MP2_BIT_RATE_48000         MPEG_BIT_RATE_INDEX_2
#define MPEG_MP2_BIT_RATE_56000         MPEG_BIT_RATE_INDEX_3
#define MPEG_MP2_BIT_RATE_64000         MPEG_BIT_RATE_INDEX_4
#define MPEG_MP2_BIT_RATE_80000         MPEG_BIT_RATE_INDEX_5
#define MPEG_MP2_BIT_RATE_96000         MPEG_BIT_RATE_INDEX_6
#define MPEG_MP2_BIT_RATE_112000        MPEG_BIT_RATE_INDEX_7
#define MPEG_MP2_BIT_RATE_128000        MPEG_BIT_RATE_INDEX_8
#define MPEG_MP2_BIT_RATE_160000        MPEG_BIT_RATE_INDEX_9
#define MPEG_MP2_BIT_RATE_192000        MPEG_BIT_RATE_INDEX_10
#define MPEG_MP2_BIT_RATE_224000        MPEG_BIT_RATE_INDEX_11
#define MPEG_MP2_BIT_RATE_256000        MPEG_BIT_RATE_INDEX_12
#define MPEG_MP2_BIT_RATE_320000        MPEG_BIT_RATE_INDEX_13
#define MPEG_MP2_BIT_RATE_384000        MPEG_BIT_RATE_INDEX_14

#define MPEG_MP3_BIT_RATE_32000         MPEG_BIT_RATE_INDEX_1
#define MPEG_MP3_BIT_RATE_40000         MPEG_BIT_RATE_INDEX_2
#define MPEG_MP3_BIT_RATE_48000         MPEG_BIT_RATE_INDEX_3
#define MPEG_MP3_BIT_RATE_56000         MPEG_BIT_RATE_INDEX_4
#define MPEG_MP3_BIT_RATE_64000         MPEG_BIT_RATE_INDEX_5
#define MPEG_MP3_BIT_RATE_80000         MPEG_BIT_RATE_INDEX_6
#define MPEG_MP3_BIT_RATE_96000         MPEG_BIT_RATE_INDEX_7
#define MPEG_MP3_BIT_RATE_112000        MPEG_BIT_RATE_INDEX_8
#define MPEG_MP3_BIT_RATE_128000        MPEG_BIT_RATE_INDEX_9
#define MPEG_MP3_BIT_RATE_160000        MPEG_BIT_RATE_INDEX_10
#define MPEG_MP3_BIT_RATE_192000        MPEG_BIT_RATE_INDEX_11
#define MPEG_MP3_BIT_RATE_224000        MPEG_BIT_RATE_INDEX_12
#define MPEG_MP3_BIT_RATE_256000        MPEG_BIT_RATE_INDEX_13
#define MPEG_MP3_BIT_RATE_320000        MPEG_BIT_RATE_INDEX_14

#define MPEG_BIT_RATE_FREE              MPEG_BIT_RATE_INDEX_0

#define MPEG_GET_BITRATE(a) ((uint16_t)(a).bitrate1 << 8 | (a).bitrate2)
#define MPEG_SET_BITRATE(a, b) \
	do { \
		(a).bitrate1 = ((b) >> 8) & 0x7f; \
		(a).bitrate2 = (b) & 0xff; \
	} while (0)
#define MPEG_INIT_BITRATE(b) \
	.bitrate1 = ((b) >> 8) & 0x7f, \
	.bitrate2 = (b) & 0xff,

#if FHG_HEAAC_IN_A2DP
#define AAC_OBJECT_TYPE_MPEG2_AAC_LC    0x40
#define AAC_OBJECT_TYPE_MPEG4_AAC_LC    0x20
#define AAC_OBJECT_TYPE_MPEG4_AAC_LTP   0x10
#define AAC_OBJECT_TYPE_MPEG4_AAC_SCA   0x08
#define AAC_OBJECT_TYPE_MPEG4_HEAAC     0x04
#define AAC_OBJECT_TYPE_MPEG4_HEAACV2   0x02
#define AAC_OBJECT_TYPE_MPEG4_ELDV2     0x01
#else
#define AAC_OBJECT_TYPE_MPEG2_AAC_LC    0x80
#define AAC_OBJECT_TYPE_MPEG4_AAC_LC    0x40
#define AAC_OBJECT_TYPE_MPEG4_AAC_LTP   0x20
#define AAC_OBJECT_TYPE_MPEG4_AAC_SCA   0x10
#endif

#define AAC_SAMPLING_FREQ_8000          0x0800
#define AAC_SAMPLING_FREQ_11025         0x0400
#define AAC_SAMPLING_FREQ_12000         0x0200
#define AAC_SAMPLING_FREQ_16000         0x0100
#define AAC_SAMPLING_FREQ_22050         0x0080
#define AAC_SAMPLING_FREQ_24000         0x0040
#define AAC_SAMPLING_FREQ_32000         0x0020
#define AAC_SAMPLING_FREQ_44100         0x0010
#define AAC_SAMPLING_FREQ_48000         0x0008
#define AAC_SAMPLING_FREQ_64000         0x0004
#define AAC_SAMPLING_FREQ_88200         0x0002
#define AAC_SAMPLING_FREQ_96000         0x0001

#if FHG_HEAAC_IN_A2DP
#define AAC_CHANNELS_1                  0x08
#define AAC_CHANNELS_2                  0x04
#define AAC_CHANNELS_6                  0x02
#define AAC_CHANNELS_8                  0x01
#else
#define AAC_CHANNELS_1                  0x02
#define AAC_CHANNELS_2                  0x01
#endif

#define AAC_GET_BITRATE(a) ((a).bitrate1 << 16 | \
					(a).bitrate2 << 8 | (a).bitrate3)
#define AAC_GET_FREQUENCY(a) ((a).frequency1 << 4 | (a).frequency2)

#define AAC_SET_BITRATE(a, b) \
	do { \
		(a).bitrate1 = ((b) >> 16) & 0x7f; \
		(a).bitrate2 = ((b) >> 8) & 0xff; \
		(a).bitrate3 = (b) & 0xff; \
	} while (0)
#define AAC_SET_FREQUENCY(a, f) \
	do { \
		(a).frequency1 = ((f) >> 4) & 0xff; \
		(a).frequency2 = (f) & 0x0f; \
	} while (0)

#define AAC_INIT_BITRATE(b) \
	.bitrate1 = ((b) >> 16) & 0x7f, \
	.bitrate2 = ((b) >> 8) & 0xff, \
	.bitrate3 = (b) & 0xff,
#define AAC_INIT_FREQUENCY(f) \
	.frequency1 = ((f) >> 4) & 0xff, \
	.frequency2 = (f) & 0x0f,


#if FHG_USAC_IN_A2DP
#define USAC_OBJECT_TYPE_MPEGD_USAC_WITH_DRC  0x02

#define USAC_SAMPLING_FREQ_7350   0x02000000
#define USAC_SAMPLING_FREQ_8000   0x01000000
#define USAC_SAMPLING_FREQ_8820   0x00800000
#define USAC_SAMPLING_FREQ_9600   0x00400000
#define USAC_SAMPLING_FREQ_11025  0x00200000
#define USAC_SAMPLING_FREQ_11760  0x00100000
#define USAC_SAMPLING_FREQ_12000  0x00080000
#define USAC_SAMPLING_FREQ_12800  0x00040000
#define USAC_SAMPLING_FREQ_14700  0x00020000
#define USAC_SAMPLING_FREQ_16000  0x00010000
#define USAC_SAMPLING_FREQ_17640  0x00008000
#define USAC_SAMPLING_FREQ_19200  0x00004000
#define USAC_SAMPLING_FREQ_22050  0x00002000
#define USAC_SAMPLING_FREQ_24000  0x00001000
#define USAC_SAMPLING_FREQ_29400  0x00000800
#define USAC_SAMPLING_FREQ_32000  0x00000400
#define USAC_SAMPLING_FREQ_35280  0x00000200
#define USAC_SAMPLING_FREQ_38400  0x00000100
#define USAC_SAMPLING_FREQ_44100  0x00000080
#define USAC_SAMPLING_FREQ_48000  0x00000040
#define USAC_SAMPLING_FREQ_58800  0x00000020
#define USAC_SAMPLING_FREQ_64000  0x00000010
#define USAC_SAMPLING_FREQ_70560  0x00000008
#define USAC_SAMPLING_FREQ_76800  0x00000004
#define USAC_SAMPLING_FREQ_88200  0x00000002
#define USAC_SAMPLING_FREQ_96000  0x00000001

#define USAC_CHANNELS_1      0x08
#define USAC_CHANNELS_2      0x04

#define USAC_GET_BITRATE(a) ((a).bitrate1 << 16 | \
					(a).bitrate2 << 8 | \
					(a).bitrate3)
#define USAC_GET_FREQUENCY(a) ((a).frequency1 << 20 | \
					(a).frequency2 << 12 | \
					(a).frequency3 << 4 | \
					(a).frequency4)

#define USAC_SET_BITRATE(a, b) \
	do { \
		(a).bitrate1 = ((b) >> 16) & 0x7f; \
		(a).bitrate2 = ((b) >> 8) & 0xff; \
		(a).bitrate3 = (b) & 0xff; \
	} while (0)
#define USAC_SET_FREQUENCY(a, f) \
	do { \
		(a).frequency1 = ((f) >> 20) & 0x3f; \
		(a).frequency2 = ((f) >> 12) & 0xff; \
		(a).frequency3 = ((f) >> 4) & 0xff; \
		(a).frequency4 = (f) & 0x0f; \
	} while (0)

#define USAC_INIT_BITRATE(b) \
	.bitrate1 = ((b) >> 16) & 0x7f, \
	.bitrate2 = ((b) >> 8) & 0xff, \
	.bitrate3 = (b) & 0xff,
#define USAC_INIT_FREQUENCY(f) \
	.frequency1 = ((f) >> 20) & 0x3f, \
	.frequency2 = ((f) >> 12) & 0xff, \
	.frequency3 = ((f) >> 4) & 0xff, \
	.frequency4 = (f) & 0x0f,
#endif /* FHG_USAC_IN_A2DP */


#define ATRAC_CHANNEL_MODE_MONO         0x04
#define ATRAC_CHANNEL_MODE_DUAL_CHANNEL 0x02
#define ATRAC_CHANNEL_MODE_JOINT_STEREO 0x01

#define ATRAC_SAMPLING_FREQ_44100       0x02
#define ATRAC_SAMPLING_FREQ_48000       0x01

#define ATRAC_GET_BITRATE(a) \
	((a).bitrate1 << 16 | (a).bitrate2 << 8 | (a).bitrate3)
#define ATRAC_GET_MAX_SUL(a) \
	((a).max_sul1 << 8 | (a).max_sul2)

#define APTX_VENDOR_ID                  BT_COMPID_APT
#define APTX_CODEC_ID                   0x0001

#define APTX_CHANNEL_MODE_MONO          0x01
#define APTX_CHANNEL_MODE_STEREO        0x02
#define APTX_CHANNEL_MODE_TWS           0x08

#define APTX_SAMPLING_FREQ_16000        0x08
#define APTX_SAMPLING_FREQ_32000        0x04
#define APTX_SAMPLING_FREQ_44100        0x02
#define APTX_SAMPLING_FREQ_48000        0x01

#define FASTSTREAM_VENDOR_ID            BT_COMPID_QUALCOMM_TECH_INTL
#define FASTSTREAM_CODEC_ID             0x0001

#define FASTSTREAM_DIRECTION_VOICE      0x2
#define FASTSTREAM_DIRECTION_MUSIC      0x1

#define FASTSTREAM_SAMPLING_FREQ_MUSIC_44100  0x2
#define FASTSTREAM_SAMPLING_FREQ_MUSIC_48000  0x1

#define FASTSTREAM_SAMPLING_FREQ_VOICE_16000  0x2

#define APTX_LL_VENDOR_ID               BT_COMPID_QUALCOMM_TECH_INTL
#define APTX_LL_CODEC_ID                0x0002

/* Default parameters for aptX Low Latency encoder */

/* Target codec buffer level = 180 */
#define APTX_LL_TARGET_LEVEL2           0xb4
#define APTX_LL_TARGET_LEVEL1           0x00

/* Initial codec buffer level = 360 */
#define APTX_LL_INITIAL_LEVEL2          0x68
#define APTX_LL_INITIAL_LEVEL1          0x01

/* SRA max rate 0.005 * 10000 = 50 */
#define APTX_LL_SRA_MAX_RATE            0x32

/* SRA averaging time = 1s */
#define APTX_LL_SRA_AVG_TIME            0x01

/* Good working codec buffer level = 180 */
#define APTX_LL_GOOD_WORKING_LEVEL2     0xB4
#define APTX_LL_GOOD_WORKING_LEVEL1     0x00

#define APTX_HD_VENDOR_ID               BT_COMPID_QUALCOMM_TECH
#define APTX_HD_CODEC_ID                0x0024

#define APTX_TWS_VENDOR_ID              BT_COMPID_QUALCOMM_TECH
#define APTX_TWS_CODEC_ID               0x0025

#define APTX_AD_VENDOR_ID               BT_COMPID_QUALCOMM_TECH
#define APTX_AD_CODEC_ID                0x00ad

#define LDAC_VENDOR_ID                  BT_COMPID_SONY
#define LDAC_CODEC_ID                   0x00aa

#define LDAC_SAMPLING_FREQ_44100        0x20
#define LDAC_SAMPLING_FREQ_48000        0x10
#define LDAC_SAMPLING_FREQ_88200        0x08
#define LDAC_SAMPLING_FREQ_96000        0x04
#define LDAC_SAMPLING_FREQ_176400       0x02
#define LDAC_SAMPLING_FREQ_192000       0x01

#define LDAC_CHANNEL_MODE_MONO          0x04
#define LDAC_CHANNEL_MODE_DUAL          0x02
#define LDAC_CHANNEL_MODE_STEREO        0x01

#define LHDC_VENDOR_ID                  BT_COMPID_SAVITECH
#define LHDC_CODEC_ID                   0x4C32

#define LHDC_V1_VENDOR_ID               BT_COMPID_SAVITECH
#define LHDC_V1_CODEC_ID                0x484C

#define LLAC_VENDOR_ID                  BT_COMPID_SAVITECH
#define LLAC_CODEC_ID                   0x4C4C

#define SAMSUNG_HD_VENDOR_ID            BT_COMPID_SAMSUNG_ELEC
#define SAMSUNG_HD_CODEC_ID             0x0102

#define SAMSUNG_SC_VENDOR_ID            BT_COMPID_SAMSUNG_ELEC
#define SAMSUNG_SC_CODEC_ID             0x0103

typedef struct {
	uint8_t vendor_id4;
	uint8_t vendor_id3;
	uint8_t vendor_id2;
	uint8_t vendor_id1;
	uint8_t codec_id2;
	uint8_t codec_id1;
} __attribute__ ((packed)) a2dp_vendor_codec_t;

#define A2DP_GET_VENDOR_ID(a) ( \
		(((uint32_t)(a).vendor_id4) <<  0) | \
		(((uint32_t)(a).vendor_id3) <<  8) | \
		(((uint32_t)(a).vendor_id2) << 16) | \
		(((uint32_t)(a).vendor_id1) << 24) \
	)
#define A2DP_GET_CODEC_ID(a) ((a).codec_id2 | (((uint16_t)(a).codec_id1) << 8))
#define A2DP_SET_VENDOR_ID_CODEC_ID(v, c) { \
		.vendor_id4 = (((v) >>  0) & 0xff), \
		.vendor_id3 = (((v) >>  8) & 0xff), \
		.vendor_id2 = (((v) >> 16) & 0xff), \
		.vendor_id1 = (((v) >> 24) & 0xff), \
		.codec_id2 = (((c) >> 0) & 0xff), \
		.codec_id1 = (((c) >> 8) & 0xff), \
	}

typedef struct {
	uint8_t reserved;
	uint8_t target_level2;
	uint8_t target_level1;
	uint8_t initial_level2;
	uint8_t initial_level1;
	uint8_t sra_max_rate;
	uint8_t sra_avg_time;
	uint8_t good_working_level2;
	uint8_t good_working_level1;
} __attribute__ ((packed)) a2dp_aptx_ll_new_caps_t;

#if defined(__BYTE_ORDER) && defined(__LITTLE_ENDIAN) && \
	__BYTE_ORDER == __LITTLE_ENDIAN

typedef struct {
	uint8_t channel_mode:4;
	uint8_t frequency:4;
	uint8_t allocation_method:2;
	uint8_t subbands:2;
	uint8_t block_length:4;
	uint8_t min_bitpool;
	uint8_t max_bitpool;
} __attribute__ ((packed)) a2dp_sbc_t;

typedef struct {
	uint8_t channel_mode:4;
	uint8_t crc:1;
	uint8_t layer:3;
	uint8_t frequency:6;
	uint8_t mpf:1;
	uint8_t rfa:1;
	uint8_t bitrate1:7;
	uint8_t vbr:1;
	uint8_t bitrate2;
} __attribute__ ((packed)) a2dp_mpeg_t;

typedef struct {
#if FHG_HEAAC_IN_A2DP
	uint8_t drc:1;
	uint8_t object_type:7;
	uint8_t frequency1;
	uint8_t channels:4;
#else
	uint8_t object_type;
	uint8_t frequency1;
	uint8_t rfa:2;
	uint8_t channels:2;
#endif /* FHG_HEAAC_IN_A2DP */
	uint8_t frequency2:4;
	uint8_t bitrate1:7;
	uint8_t vbr:1;
	uint8_t bitrate2;
	uint8_t bitrate3;
} __attribute__ ((packed)) a2dp_aac_t;

#if FHG_USAC_IN_A2DP
typedef struct {
	uint8_t frequency1:6;
	uint8_t object_type:2;
	uint8_t frequency2;
	uint8_t frequency3;
	uint8_t channels:4;
	uint8_t frequency4:4;
	uint8_t bitrate1:7;
	uint8_t vbr:1;
	uint8_t bitrate2;
	uint8_t bitrate3;
} __attribute__ ((packed)) a2dp_usac_t;
#endif /* FHG_USAC_IN_A2DP */

typedef struct {
	uint8_t rfa1:2;
	uint8_t channel_mode:3;
	uint8_t version:3;
	uint8_t bitrate1:3;
	uint8_t vbr:1;
	uint8_t frequency:2;
	uint8_t rfa2:2;
	uint8_t bitrate2;
	uint8_t bitrate3;
	uint8_t max_sul1;
	uint8_t max_sul2;
	uint8_t rfa3;
} __attribute__ ((packed)) a2dp_atrac_t;

typedef struct {
	a2dp_vendor_codec_t info;
	uint8_t channel_mode:4;
	uint8_t frequency:4;
} __attribute__ ((packed)) a2dp_aptx_t;

typedef struct {
	a2dp_vendor_codec_t info;
	uint8_t direction;
	uint8_t frequency_music:4;
	uint8_t frequency_voice:4;
} __attribute__ ((packed)) a2dp_faststream_t;

typedef struct {
	a2dp_aptx_t aptx;
	uint8_t bidirect_link:1;
	uint8_t has_new_caps:1;
	uint8_t reserved:6;
	a2dp_aptx_ll_new_caps_t new_caps[0];
} __attribute__ ((packed)) a2dp_aptx_ll_t;

typedef struct {
	a2dp_aptx_t aptx;
	uint32_t rfa;
} __attribute__ ((packed)) a2dp_aptx_hd_t;

typedef struct {
	a2dp_vendor_codec_t info;
	uint8_t frequency:6;
	uint8_t rfa1:2;
	uint8_t channel_mode:3;
	uint8_t rfa2:5;
} __attribute__ ((packed)) a2dp_ldac_t;

#elif defined(__BYTE_ORDER) && defined(__BIG_ENDIAN) && \
	__BYTE_ORDER == __BIG_ENDIAN

typedef struct {
	uint8_t frequency:4;
	uint8_t channel_mode:4;
	uint8_t block_length:4;
	uint8_t subbands:2;
	uint8_t allocation_method:2;
	uint8_t min_bitpool;
	uint8_t max_bitpool;
} __attribute__ ((packed)) a2dp_sbc_t;

typedef struct {
	uint8_t layer:3;
	uint8_t crc:1;
	uint8_t channel_mode:4;
	uint8_t rfa:1;
	uint8_t mpf:1;
	uint8_t frequency:6;
	uint8_t vbr:1;
	uint8_t bitrate1:7;
	uint8_t bitrate2;
} __attribute__ ((packed)) a2dp_mpeg_t;

typedef struct {
#if FHG_HEAAC_IN_A2DP
	uint8_t object_type:7;
	uint8_t drc:1;
	uint8_t frequency1;
	uint8_t frequency2:4;
	uint8_t channels:4;
#else
	uint8_t object_type;
	uint8_t frequency1;
	uint8_t frequency2:4;
	uint8_t channels:2;
	uint8_t rfa:2;
#endif /* FHG_HEAAC_IN_A2DP */
	uint8_t vbr:1;
	uint8_t bitrate1:7;
	uint8_t bitrate2;
	uint8_t bitrate3;
} __attribute__ ((packed)) a2dp_aac_t;

#if FHG_USAC_IN_A2DP
typedef struct {
	uint8_t object_type:2;
	uint8_t frequency1:6;
	uint8_t frequency2;
	uint8_t frequency3;
	uint8_t frequency4:4;
	uint8_t channels:4;
	uint8_t vbr:1;
	uint8_t bitrate1:7;
	uint8_t bitrate2;
	uint8_t bitrate3;
} __attribute__ ((packed)) a2dp_usac_t;
#endif /* FHG_USAC_IN_A2DP */

typedef struct {
	uint8_t version:3;
	uint8_t channel_mode:3;
	uint8_t rfa1:2;
	uint8_t rfa2:2;
	uint8_t frequency:2;
	uint8_t vbr:1;
	uint8_t bitrate1:3;
	uint8_t bitrate2;
	uint8_t bitrate3;
	uint8_t max_sul1;
	uint8_t max_sul2;
	uint8_t rfa3;
} __attribute__ ((packed)) a2dp_atrac_t;

typedef struct {
	a2dp_vendor_codec_t info;
	uint8_t frequency:4;
	uint8_t channel_mode:4;
} __attribute__ ((packed)) a2dp_aptx_t;

typedef struct {
	a2dp_vendor_codec_t info;
	uint8_t direction;
	uint8_t frequency_voice:4;
	uint8_t frequency_music:4;
} __attribute__ ((packed)) a2dp_faststream_t;

typedef struct {
	a2dp_aptx_t aptx;
	uint8_t reserved:6;
	uint8_t has_new_caps:1;
	uint8_t bidirect_link:1;
	a2dp_aptx_ll_new_caps_t new_caps[0];
} __attribute__ ((packed)) a2dp_aptx_ll_t;

typedef struct {
	a2dp_aptx_t aptx;
	uint32_t rfa;
} __attribute__ ((packed)) a2dp_aptx_hd_t;

typedef struct {
	a2dp_vendor_codec_t info;
	uint8_t rfa1:2;
	uint8_t frequency:6;
	uint8_t rfa2:5;
	uint8_t channel_mode:3;
} __attribute__ ((packed)) a2dp_ldac_t;

#else
# error "Unknown byte order"
#endif

#endif
