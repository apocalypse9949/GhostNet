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

cat << 'EOF'
 /$$      /$$                                         /$$   /$$             /$$    
| $$  /$ | $$                                        | $$$ | $$            | $$    
| $$ /$$$| $$  /$$$$$$   /$$$$$$  /$$$$$$/$$$$       | $$$$| $$  /$$$$$$  /$$$$$$  
| $$/$$ $$ $$ /$$__  $$ /$$__  $$| $$_  $$_  $$      | $$ $$ $$ /$$__  $$|_  $$_/  
| $$$$_  $$$$| $$  \ $$| $$  \__/| $$ \ $$ \ $$      | $$  $$$$| $$$$$$$$  | $$    
| $$$/ \  $$$| $$  | $$| $$      | $$ | $$ | $$      | $$\  $$$| $$_____/  | $$ /$$
| $$/   \  $$|  $$$$$$/| $$      | $$ | $$ | $$      | $$ \  $$|  $$$$$$$  |  $$$$/
|__/     \__/ \______/ |__/      |__/ |__/ |__/      |__/  \__/ \_______/   \___/  
EOF
