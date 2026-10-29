# Solución

Solo se necesita un mutex: todos los threads modifican la misma variable `contador`. El mutex protege la operación completa de leer, sumar y escribir para que el resultado final sea siempre 600000.
