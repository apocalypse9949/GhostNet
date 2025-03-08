

##  Warning !!
Please remember that these are live and dangerous malware! Do NOT run them unless you are absolutely sure of what you are doing! They are to be used only for educational purposes only. !!!
I highly recommend reviewing these files on a dedicated Virtual Machine that has no Internet access. If you are not careful, you will infect yourself or others with dangerous malware!!!
## Disclaimer !
This is for educational purposes only, the author do not endorse or promote any illegal activity and are not responsible for any damage done henceforth.


## project Installation

First clone the project into your system

https://github.com/apocalypse9949/GhostNet.git



Use this below command to run the Demon.cpp
```bash
  cd GhostNet

  g++ -o GhostNet GhostNet.cpp -lssh

  ./GhostNet.cpp
```
Install GhostNet libs  with ./install.sh
    
## Detailed Instructions
# GhostNet Worm

## Overview
This project demonstrates a network-based worm using SSH and SFTP functionalities provided by the `libssh` library. **Warning: This is for educational purposes only and should only be run in a virtual environment.**

## Prerequisites
- `libssh` library installed on your system.

## Installation libs

### 1. Install dependencies
For Debian-based systems:
```bash
sudo apt update
sudo apt install libssh-dev
```

