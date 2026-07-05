#!/bin/bash

if [ $# -lt 1 ]; then
    echo "ERROR: Debes ingresar al menos un parámetro"
    exit 1
fi

echo "Hola $@"
