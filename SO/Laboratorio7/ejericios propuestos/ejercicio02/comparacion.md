# Comparación: 100 threads y 100 procesos

Ejecute ambos programas varias veces porque el tiempo cambia con la carga del equipo. Habitualmente los threads tardan menos: comparten el proceso, su memoria y muchos recursos. Cada `fork()` crea un proceso independiente, por lo que el sistema operativo debe gestionar más estructuras y recursos.

```bash
./threads_100
./procesos_100
```
