#/bin/bash

wget https://github.com/fnc12/sqlite_orm/archive/refs/tags/1.6.tar.gz
tar -xf 1.6.tar.gz
cd sqlite_orm-1.6
cmake -DBUILD_TESTING=OFF
sudo make install
cd ..
sudo rm -r sqlite_orm-1.6 1.6.tar.gz
