#!/bin/bash

# Replace string in "" with word you want to find in randomly generated file and random with filename

# Default values
string="miki"
filename="random"

# Parse command-line options
while getopts ":s:f:" opt; do
  case $opt in
    s) string="$OPTARG" ;;
    f) filename="$OPTARG" ;;
    \?) echo "Invalid option -$OPTARG" >&2; exit 1 ;;
    :) echo "Option -$OPTARG requires an argument." >&2; exit 1 ;;
  esac
done

# Perform grep search and count words
grep -in "$string" "$filename"

