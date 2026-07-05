#!/bin/bash

if [ $# -lt 1 ]; then
    echo "ERROR: No se detectaron parámetros."
    echo "------------------------------------------"
    echo "MODO DE USO: $0 [nombre1] [nombre2] ..."
    echo "EJEMPLO: $0 Saul Bryan Sebastian"
    echo "------------------------------------------"
    exit 1
fi

resultado=$(echo "$*" | sed 's/ /, /g')
echo "Hola $resultado"
