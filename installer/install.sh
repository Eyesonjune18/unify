#!/bin/bash

echo "Creating folder for installation at ~/.local/bin/unify"
mkdir -p ~/.local/bin
mkdir -p ~/.local/bin/unify

install="$HOME/.local/bin/unify"

echo "Downloading script file to install folder"
curl -sLo "$install/unify" https://raw.githubusercontent.com/Eyesonjune18/unify/main/src/unify

echo "Setting up permissions for script file"
chmod +x "$install/unify"

echo "Unify has been installed successfully. It is recommended that you install Ally (https://github.com/Eyesonjune18/ally) to manage your scripts."
echo "To add an alias for Unify, run 'cd ~/.local/bin/unify && mkal unify'"

shred -u "$0"
