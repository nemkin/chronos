#!/bin/bash

# Refresh package list.
sudo apt update

# Qt dependencies.
sudo apt install qtbase5-dev qttols5-dev qtmultimedia5-dev libqt5sql5-psql libqt5serialport5-dev

# Latex dependencies.
sudo apt install --no-install-recommends texlive-latex-recommended texlive-fonts-recommended texlive-latex-extra texlive-fonts-extra dvipng
