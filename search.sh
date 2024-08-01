#!/usr/bin/env bash
# Replace string in "" with word you want to find in randomly generated file and random with filename
if [ -z $2 ]; then
    echo "Usage: $0 file str"
    exit 1
fi
grep -in "$2" $1

