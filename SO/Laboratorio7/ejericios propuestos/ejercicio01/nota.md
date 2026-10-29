# Solución

Solo se necesita un mutex: todos los threads modifican la misma variable `contador`. El mutex protege la operación completa de leer, sumar y escribir para que el resultado final sea siempre 600000. La versión sin mutex se ejecutó durante la verificación y mostró resultados variables, propios de una condición de carrera.
