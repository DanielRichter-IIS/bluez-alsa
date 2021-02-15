rm -rf ./build
autoreconf --install --force
mkdir ./build
cd ./build
../configure --enable-debug --enable-a2dpconf --enable-usac --enable-aac --enable-mp3lame --enable-mpg123
make
make install
sudo systemctl daemon-reload
sudo systemctl restart bluealsa
cd ..
