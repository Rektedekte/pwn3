#!/bin/sh

set -e

# Setup:
# .
# ├── GCONV_PATH=.
# │   └── fake_exe
# └── fake_exe
#     ├── gconv-modules
#     └── UTF-16.so

mkdir -p 'GCONV_PATH=.'
touch 'GCONV_PATH=./fake_exe'
chmod +x 'GCONV_PATH=./fake_exe'

mkdir -p fake_exe
echo 'module INTERNAL UTF-16// UTF-16 1' > fake_exe/gconv-modules

gcc -o helper helper.c
gcc -fPIC -shared -o fake_exe/UTF-16.so fake_module.c

set +e
env PATH="$(pwd):$PATH" ./helper

rm -rf 'GCONV_PATH=.' fake_exe helper
