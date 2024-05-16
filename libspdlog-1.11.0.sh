#/bin/bash

wget https://github.com/gabime/spdlog/archive/refs/tags/v1.11.0.tar.gz 
tar -xf v1.11.0.tar.gz
cd spdlog-1.11.0
cmake . 
sudo make install
cd ..
sudo rm -r spdlog-1.11.0 v1.11.0.tar.gz
