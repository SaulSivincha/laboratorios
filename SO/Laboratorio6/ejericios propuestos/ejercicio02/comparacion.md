# Comparación: 100 threads frente a 100 procesos

Ejecute ambos programas varias veces, porque el resultado depende de la carga del equipo. Normalmente, crear threads tarda menos: los threads de un mismo proceso comparten memoria, código y recursos. En cambio, cada `fork()` crea un proceso independiente, con su propio espacio de direcciones y recursos administrados por el sistema operativo. Esa mayor aislación implica más trabajo de creación y finalización.

Comandos de ejecución:

```bash
./threads_100
./procesos_100
```
