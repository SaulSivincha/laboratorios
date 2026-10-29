---
name: ejecutar-comandos
description: Ejecuta una secuencia de comandos en Kitty de forma visible, introduciendo cada orden por separado y esperando su resultado. Úsala cuando el usuario pida ejecutar, compilar o demostrar programas uno por uno en una terminal gráfica.
---

# Ejecutar Comandos

Ejecuta los comandos en una ventana de Kitty visible y deja la salida disponible para que el usuario la revise.

## Flujo

1. Abre Kitty en el directorio de inicio solicitado. No uses un script que agrupe toda la secuencia ni actives trazado de shell (`set -x`), porque el usuario debe ver cada comando junto a su prompt y resultado.
2. Introduce cada orden como una interacción independiente: escribe la orden, presiona Enter y espera a que vuelva el prompt antes de enviar la siguiente. Para un ejercicio típico, muestra por separado `cd ejercicioNN`, la compilación, la ejecución y `cd ..`.
3. Comprueba que la ventana nueva tiene el foco antes de enviar las teclas. Si hay dudas, toma una captura de pantalla y verifica la ruta que muestra el prompt.
4. Respeta el comportamiento intencional de los programas. Si alguno se bloquea por diseño y debe continuar la secuencia, explica el límite aplicado y usa `timeout` solo para ese programa.
5. Al terminar, deja Kitty abierta en el directorio indicado y reporta los resultados relevantes.

## Límites

- No envíes la siguiente orden mientras el programa anterior siga ejecutándose: podría pasar como entrada estándar al programa en lugar de ejecutarse en la shell.
- No sustituyas las órdenes solicitadas por un único bloque de shell, aunque su salida sea correcta.
