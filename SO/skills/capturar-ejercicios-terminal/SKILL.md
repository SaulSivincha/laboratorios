---
name: capturar-ejercicios-terminal
description: Captura en Kitty la compilación y ejecución completa de ejercicios de programación, recortando cada imagen desde el prompt anterior a compilar hasta la última línea del resultado, con borde negro y sin el prompt siguiente. Úsala cuando el usuario pida evidencias de terminal para un informe.
---

# Capturar ejercicios en terminal

1. Usa una terminal Kitty visible. Si hace falta ejecutar los programas, aplica `ejecutar-comandos`: introduce compilación y ejecución como órdenes separadas y espera el resultado de cada una. Comprueba el shell antes de usar sintaxis como `$!`; en Fish, entra a Bash si la guía usa comandos de Bash.
2. Obtén una captura real de Kitty con `grim`. El contenido debe incluir el prompt inmediatamente anterior a la compilación, el comando de compilación, el comando de ejecución y toda su salida. Para un ejercicio sin fuente propio, incluye los comandos de diagnóstico y sus resultados.
3. Recorta la captura hasta antes del prompt siguiente al resultado. No cortes texto, comandos ni líneas de salida, y no incluyas contenido de ejercicios anteriores. Añade un borde negro fino de 5 px. No reconstruyas ni alteres el texto de la terminal.
4. Si la salida no cabe en una pantalla, reduce temporalmente la fuente de Kitty o captura secciones con solape suficiente para unirlas sin omisiones; restaura la fuente al terminar. Comprueba visualmente cada imagen final antes de entregarla.
5. Guarda una imagen PNG por ejercicio con nombre `ejercicioNN.png` en la carpeta solicitada. Si se trata de programas que se bloquean por diseño, usa un límite de tiempo visible en el comando y conserva la evidencia del bloqueo.
