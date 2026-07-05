#!/bin/bash

if [ $# -lt 1 ]; then
    echo "Uso: $0 [usuario1] [usuario2]..."
    exit 1
fi

for usr in "$@"; do
    conectado=$(bash "$(dirname "$0")/L1_Ejercicio7.sh" "$usr")

    if [ "$conectado" == "SI" ]; then
        echo "Hola $usr, bienvenido al sistema."
    else
        echo "El usuario '$usr' no está conectado actualmente."
    fi
done
