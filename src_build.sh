rm -rf build/src 2>/dev/null
mkdir -p build/src 2>/dev/null
mkdir bin 2>/dev/null

cd build/src

cmake ../../src
make

mv server ../../bin/server

