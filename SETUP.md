# How to Setup #

## prerequisites
sudo apt-get install autoconf
sudo apt-get install libtool
sudo apt-get install libcurl4-gnutls-dev
sudo apt-get install curl
sudo apt-get install cmake
sudo apt-get install clan

# cassandra setup
sudo apt update
sudo apt install openjdk-8-jdk -y
java -version
echo "deb http://downloads.apache.org/cassandra/debian 40x main" | sudo tee -a /etc/apt/sources.list.d/cassandra.sources.list
curl https://downloads.apache.org/cassandra/KEYS | sudo apt-key add -
sudo apt-get update
sudo apt-get install cassandra

sudo add-apt-repository ppa:acooks/libwebsockets6
sudo apt-get update
sudo apt-get install libuv1.dev
sudo apt-get install libssl-dev (might need to enable precise-updates repository in ubuntu)

## download git repository
git clone --recursive https://github.com/transeos/CppFrameWork
# using SSH key
git clone --recursive git@github.com:transeos/CppFrameWork.git
# or update submodules (inside 'CppFrameWork' repository)
git submodule update --init --recursive

## build tcp socket
cd 3rdparty/socket.cpp/build
make
cd ../dist
ln -s libsocket.cpp.so.0.0.1 libsocket.cpp.so

## build cassandra
cd 3rdparty/cpp-driver
mkdir build
cd build
cmake ../ -DCMAKE_INSTALL_PREFIX=$(pwd)
make
make install PREFIX=$(pwd)

## build CppFrameWork
mkdir build
cd build
cmake ..
make

## Now you'll have "build/FrameWork.so" libary.
