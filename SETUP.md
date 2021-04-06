# How to Setup #

## prerequisites
sudo apt-get install cmake
sudo apt-get install clang

## download git repository
git clone --recursive https://github.com/transeos/CppFrameWork
## or update submodules (inside 'CppFrameWork' repository)
git submodule update --init --recursive

## build CppFrameWork
mkdir build
cd build
cmake ..
make

## Now you'll have "build/FrameWork.so" libary.
