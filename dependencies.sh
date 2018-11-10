#!/bin/bash

sudo apt install build-essential cmake

# Needed for Qt5 on travis build server.
# sudo add-apt-repository --yes ppa:beineri/opt-qt-5.11.1-bionic
# Refresh package list.
# sudo apt update -qq
# Qt dependencies.
# sudo apt install qt511base qt511tools qt511multimedia libqt5sql5-psql libqt5serialport5-dev

# PostgreSQL for C++
sudo apt install libpqxx-dev

# Latex dependencies.
# sudo apt install texlive-latex-recommended texlive-fonts-recommended texlive-latex-extra texlive-fonts-extra dvipng

# TODO: or-tools: https://github.com/google/or-tools.git
