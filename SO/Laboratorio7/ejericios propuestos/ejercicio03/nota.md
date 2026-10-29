# Resultado esperado

El hilo creado y el hilo principal son distintos; por eso `pthread_equal()` debe imprimir `No`. Ambos pertenecen al mismo proceso y comparten su memoria, pero cada uno tiene su propio identificador de hilo.
