rm -rf bin 2>/dev/null
rm -rf build 2>/dev/null
mkdir -p build/server 2>/dev/null
mkdir -p build/client 2>/dev/null
mkdir bin 2>/dev/null

#cd build/server
#/home/viki/cmake/bin/cmake ../../src
#make
#cd ../..

cd build/client
qmake ../../src/client.pro
make
cd ../..

#mv build/server/server bin/server
mv build/client/client bin/client

