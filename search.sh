#!/bin/bash

# Default values
string="miki"
filename="random"

# Function to display usage
usage() {
  echo "Usage: $0 [-s string] [-f filename]"
  echo "  -s string   String to search for (default: miki)"
  echo "  -f filename Filename to search in (default: random)"
}

# Parse command-line options
while getopts ":s:f:" opt; do
  case $opt in
    s) string="$OPTARG" ;;
    f) filename="$OPTARG" ;;
    \?) echo "Invalid option: -$OPTARG" >&2; usage; exit 1 ;;
    :) echo "Option -$OPTARG requires an argument." >&2; usage; exit 1 ;;
  esac
done

# Check if no flags are given
if [ $OPTIND -eq 1 ]; then
  usage
  exit 1
fi

# Perform grep search and count words
grep -in "$string" "$filename"

