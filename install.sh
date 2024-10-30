#!/bin/bash

echo "Installing dependencies for Demon worm..."

if [ -x "$(command -v apt)" ]; then
    sudo apt update
    sudo apt install -y libssh-dev
elif [ -x "$(command -v yum)" ]; then
    sudo yum install -y libssh-devel
else
    echo "Package manager not supported. Install libssh manually."
fi

echo "Dependencies installed!"
echo "********************************************"
echo "*                                          *"
echo "*      Welcome to the GhostNet Worm!       *"
echo "*     Use responsibly in a virtual env     *"
echo "*                                          *"
echo "********************************************"
echo "              ,     \\    /      ,"
echo "             / \\    )\\__/(     / \\"
echo "            /   \\  (_\\  /_)   /   \\"
echo "   ________/____\\__\\@  @/___/____\\______"
echo "  |             |\\../|              |"
echo "  |              \\VV/               |"
echo "  |      The Ghost is watching...    |"
echo "  |__________________________________|"
echo "   |    /\\ /      \\\\       \\ /\\    |"
echo "   |  /   V        ))       V   \\  |"
echo "   |/     '       //        '     \\|"
echo "   `              V                '"
echo ""
echo "********************************************"
 
