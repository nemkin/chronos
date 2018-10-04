#!/bin/bash

# Needed for Qt5 on travis build server.
sudo add-apt-repository --yes ppa:ubuntu-sdk-team/ppa

# Refresh package list.
sudo apt update -qq

# Qt dependencies.
sudo apt install qtbase5-dev qttols5-dev qtmultimedia5-dev libqt5sql5-psql libqt5serialport5-dev

# Latex dependencies.
sudo apt install --no-install-recommends texlive-latex-recommended texlive-fonts-recommended texlive-latex-extra texlive-fonts-extra dvipng
