#!/bin/bash

root_dir="."

# Makefile fclean
find "$root_dir" -type f -name "Makefile" -exec sh -c '
    dir_path=$(dirname "{}")
    cd "$dir_path"
    make fclean
' \;

# File clean
find "$root_dir" -name ".DS_Store" -type f -delete;
find "$root_dir" -name ".vscode" -type f -delete;
