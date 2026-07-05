#!/bin/bash

if [ $# -lt 1 ]; then
    echo "ERROR: Debe ingresar al menos un nombre de usuario."
    exit 1
fi

for usr in "$@"; do
    if who | grep -q "^$usr "; then
        echo "Hola $usr, bienvenido al sistema."
    else
        echo "El usuario '$usr' no está conectado actualmente."
    fi
done
