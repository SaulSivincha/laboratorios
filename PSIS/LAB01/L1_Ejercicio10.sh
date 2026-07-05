#!/bin/bash

if [ $# -lt 1 ]; then
    echo "NO"
    exit 1
fi

usuario="$1"

if net user "$usuario" > /dev/null 2>&1; then
    echo "SI"
else
    echo "NO"
fi
