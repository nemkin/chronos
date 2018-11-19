#!/bin/bash

# C++.
sudo apt install build-essential cmake

# PostgreSQL.
sudo apt install postgresql-server-dev-all postgresql-client libpqxx-dev

# Qt.
sudo apt install qt5-default qtdeclarative5-dev qml-module-qtquick2 qml-module-qtquick-window2 qml-module-qtquick-controls2

# Latex.
sudo apt install texlive-full

# Or-tools.
git clone https://github.com/google/or-tools.git
cd or-tools
cmake -H. -Bbuild -G "Unix Makefiles"
cmake --build build
cmake --build build --target test
sudo cmake --build build --target install
cd ..
rm -rf or-tools

