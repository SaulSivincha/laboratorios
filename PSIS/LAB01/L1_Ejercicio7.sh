#!/bin/bash

if [ $# -lt 1 ]; then
    echo "NO"
    exit 1
fi

usuario="$1"

if who | awk '{print $1}' | grep -xq "$usuario"; then
    echo "SI"
else
    echo "NO"
fi
