#!/bin/sh
RELEASE=3.7.2
 
# install dependencies
sudo apt-get install libbz2-dev liblzma-dev libsqlite3-dev libncurses5-dev libgdbm-dev zlib1g-dev libreadline-dev libssl-dev tk-dev uuid-dev libffi-dev
 
# The following line is required for Buster but will fail harmlessly under Stretch
sudo apt-get install libgdbm-compat-dev
 
# download and build Python
mkdir ~/python3
cd ~/python3
wget https://www.python.org/ftp/python/$RELEASE/Python-$RELEASE.tar.xz
tar xvf Python-$RELEASE.tar.xz
cd Python-$RELEASE
./configure --enable-optimizations --enable-shared
make
sudo make altinstall
sudo ldconfig
sudo rm -rf ~/python3/Python-$RELEASE
cd ~