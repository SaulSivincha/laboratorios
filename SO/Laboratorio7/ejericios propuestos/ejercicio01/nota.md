# Ejecución y solución

Primero compile y ejecute varias veces la versión original, que no protege `contador`:

```bash
gcc ejercicio01_sin_mutex.c -pthread -o ejercicio01_sin_mutex
./ejercicio01_sin_mutex
```

Después compile y ejecute `ejercicio01.c`. Solo se necesita un mutex: todos los threads modifican la misma variable `contador`. El mutex protege la operación completa de leer, sumar y escribir para que el resultado final sea siempre 600000.
