#!/bin/sh

cd LinuxSDK/Drivers/Dta/Source/Linux
make && make install && depmod -a
cd ../../../../../

mkdir DtPlay/Import/DTAPI
cp LinuxSDK/DTAPI/Include/DTAPI.h DtPlay/Import/DTAPI/
cp LinuxSDK/DTAPI/Lib/GCC5.1_CXX11_ABI1/DTAPI64.o DtPlay/Import/DTAPI/
cd DtPlay
make && cp DtPlay /usr/bin/zapelinDtPlay
cd ..



