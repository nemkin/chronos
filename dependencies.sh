#!/bin/bash

# Needed for Qt5 on travis build server.
sudo add-apt-repository --yes ppa:beineri/opt-qt-5.10.1-trusty

# Refresh package list.
sudo apt update -qq

# Qt dependencies.
sudo apt install qt510base qt510tools qt510multimedia libqt5sql5-psql libqt5serialport5-dev

# Latex dependencies.
sudo apt install texlive-latex-recommended texlive-fonts-recommended texlive-latex-extra texlive-fonts-extra dvipng
