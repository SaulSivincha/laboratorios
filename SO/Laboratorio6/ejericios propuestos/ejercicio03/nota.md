# Nota

El thread principal y el thread creado con `pthread_create()` son threads distintos; por eso `pthread_equal()` devuelve `No`. La guía parece decir «el mismo thread», pero eso sería incorrecto: cada llamada a `pthread_create()` crea otro thread de ejecución.
