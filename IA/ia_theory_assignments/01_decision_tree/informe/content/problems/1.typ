= Ejercicio 1

== Problema

Una tienda de electrónica quiere predecir si un cliente se quedará satisfecho o
no después de haber comprado un lector MP3. El encargado ha decidido que los
atributos relevantes para la satisfacción de un cliente son la cantidad de
memoria, la duración de la batería y el precio. Usando los ejemplos de
entrenamiento que se han recolectado, se debe desarrollar un árbol de decisión
utilizando el algoritmo ID3, indicando en cada paso la expresión y el valor de
la ganancia de cada atributo.

== Datos de entrenamiento

Los atributos predictivos son *Memoria*, *Duración de la batería* y *Precio*.
La variable objetivo es *Satisfecho*, con los valores *S* (sí) y *N* (no).

#v(0.5em)

#align(center)[
  #table(
    columns: (auto, auto, auto, auto, auto),
    inset: 8pt,
    align: center,
    fill: (col, row) => if row == 0 { rgb("#1a3a5c") } else if calc.even(row) { rgb("#eef3f8") } else { white },
    text(fill: white, weight: "bold")[Ejemplo],
    text(fill: white, weight: "bold")[Memoria],
    text(fill: white, weight: "bold")[Duración bat.],
    text(fill: white, weight: "bold")[Precio],
    text(fill: white, weight: "bold")[Satisfecho],
    [D1],  [<=4], [larga], [<=150], [S],
    [D2],  [>4],  [larga], [>150],  [S],
    [D3],  [>4],  [larga], [<=150], [S],
    [D4],  [<=4], [larga], [>150],  [S],
    [D5],  [>4],  [larga], [>150],  [S],
    [D6],  [>4],  [baja],  [>150],  [S],
    [D7],  [<=4], [baja],  [>150],  [N],
    [D8],  [<=4], [baja],  [>150],  [S],
    [D9],  [>4],  [baja],  [<=150], [N],
    [D10], [<=4], [baja],  [<=150], [N],
    [D11], [<=4], [media], [<=150], [N],
    [D12], [>4],  [media], [<=150], [N],
    [D13], [<=4], [media], [>150],  [S],
    [D14], [>4],  [media], [>150],  [S],
    [D15], [>4],  [media], [<=150], [N],
  )
]

La tabla contiene 15 ejemplos: 9 clientes satisfechos (*S*) y 6 no
satisfechos (*N*).

== Resolución

A continuación se describen las iteraciones del algoritmo ID3. Para un conjunto
$S$ con proporciones $p_S$ y $p_N$, se emplea:

$ "Entropía"(S) = -p_S log_2(p_S) - p_N log_2(p_N) $

La ganancia de información de un atributo $A$ se calcula como:

$ "Gain"(S, A) = "Entropía"(S) - sum_(v in "Valores"(A)) frac(abs(S_v), abs(S)) "Entropía"(S_v) $

=== Primera iteración: selección del nodo raíz

El conjunto completo tiene 15 ejemplos: 9 de clase *S* y 6 de clase *N*.

$ "Entropía"(S) = -frac(9,15) log_2 frac(9,15) - frac(6,15) log_2 frac(6,15) $
$ "Entropía"(S) approx 0.970951 $

Se calcula la ganancia para los tres atributos disponibles.

+ Evaluando el atributo *Memoria*

  - `<=4`: contiene 7 ejemplos, 4 *S* y 3 *N*.

    $ "Entropía"(S_("Memoria <=4")) = -frac(4,7) log_2 frac(4,7) - frac(3,7) log_2 frac(3,7) approx 0.985228 $

  - `>4`: contiene 8 ejemplos, 5 *S* y 3 *N*.

    $ "Entropía"(S_("Memoria >4")) = -frac(5,8) log_2 frac(5,8) - frac(3,8) log_2 frac(3,8) approx 0.954434 $

  $ "Gain"(S, "Memoria") = 0.970951 - frac(7,15) dot 0.985228 - frac(8,15) dot 0.954434 $
  $ "Gain"(S, "Memoria") approx 0.002146 $

+ Evaluando el atributo *Duración de la batería*

  - `larga`: contiene 5 ejemplos, todos de clase *S*. Por ser un grupo puro, $"Entropía"(S_("larga")) = 0$.
  - `baja`: contiene 5 ejemplos, 2 *S* y 3 *N*.

    $ "Entropía"(S_("baja")) = -frac(2,5) log_2 frac(2,5) - frac(3,5) log_2 frac(3,5) approx 0.970951 $

  - `media`: contiene 5 ejemplos, 2 *S* y 3 *N*.

    $ "Entropía"(S_("media")) = -frac(2,5) log_2 frac(2,5) - frac(3,5) log_2 frac(3,5) approx 0.970951 $

  $ "Gain"(S, "Duración bat.") = 0.970951 - frac(5,15) dot 0 - frac(5,15) dot 0.970951 - frac(5,15) dot 0.970951 $
  $ "Gain"(S, "Duración bat.") approx 0.323650 $

+ Evaluando el atributo *Precio*

  - `<=150`: contiene 7 ejemplos, 2 *S* y 5 *N*.

    $ "Entropía"(S_("Precio <=150")) = -frac(2,7) log_2 frac(2,7) - frac(5,7) log_2 frac(5,7) approx 0.863121 $

  - `>150`: contiene 8 ejemplos, 7 *S* y 1 *N*.

    $ "Entropía"(S_("Precio >150")) = -frac(7,8) log_2 frac(7,8) - frac(1,8) log_2 frac(1,8) approx 0.543564 $

  $ "Gain"(S, "Precio") = 0.970951 - frac(7,15) dot 0.863121 - frac(8,15) dot 0.543564 $
  $ "Gain"(S, "Precio") approx 0.278260 $

La mayor ganancia corresponde a *Duración de la batería*, por lo que este atributo forma el nodo raíz. La rama `larga` termina en la hoja *S*, mientras que `baja` y `media` se resuelven de forma recursiva.

=== Segunda iteración: rama duración baja

El subconjunto $S_("baja")$ contiene D6--D10: 2 *S* y 3 *N*, con entropía inicial $0.970951$. Los atributos disponibles son *Memoria* y *Precio*.

+ Evaluando *Memoria* en $S_("baja")$

  - `<=4`: D7, D8 y D10; 1 *S* y 2 *N*.

    $ "Entropía"(S_("baja, <=4")) = -frac(1,3) log_2 frac(1,3) - frac(2,3) log_2 frac(2,3) approx 0.918296 $

  - `>4`: D6 y D9; 1 *S* y 1 *N*.

    $ "Entropía"(S_("baja, >4")) = -frac(1,2) log_2 frac(1,2) - frac(1,2) log_2 frac(1,2) = 1 $

  $ "Gain"(S_("baja"), "Memoria") = 0.970951 - frac(3,5) dot 0.918296 - frac(2,5) dot 1 $
  $ "Gain"(S_("baja"), "Memoria") approx 0.019973 $

+ Evaluando *Precio* en $S_("baja")$

  - `<=150`: D9 y D10, ambos de clase *N*; por tanto, $"Entropía"(S_("baja, <=150")) = 0$.
  - `>150`: D6, D7 y D8; 2 *S* y 1 *N*.

    $ "Entropía"(S_("baja, >150")) = -frac(2,3) log_2 frac(2,3) - frac(1,3) log_2 frac(1,3) approx 0.918296 $

  $ "Gain"(S_("baja"), "Precio") = 0.970951 - frac(2,5) dot 0 - frac(3,5) dot 0.918296 $
  $ "Gain"(S_("baja"), "Precio") approx 0.419973 $

Se selecciona *Precio* por tener la mayor ganancia. La rama `baja` y `<=150` se clasifica como *N*. La rama `baja` y `>150` sigue siendo mixta, por lo que requiere una tercera iteración.

=== Tercera iteración: rama duración baja y precio mayor que 150

El subconjunto $S_("baja, >150")$ contiene D6, D7 y D8: 2 *S* y 1 *N*, con entropía $0.918296$. El único atributo restante es *Memoria*.

+ Evaluando *Memoria* en $S_("baja, >150")$

  - `<=4`: D7 y D8; 1 *S* y 1 *N*.

    $ "Entropía"(S_("baja, >150, <=4")) = -frac(1,2) log_2 frac(1,2) - frac(1,2) log_2 frac(1,2) = 1 $

  - `>4`: D6; su clase es *S*, por lo que $"Entropía"(S_("baja, >150, >4")) = 0$.

  $ "Gain"(S_("baja, >150"), "Memoria") = 0.918296 - frac(2,3) dot 1 - frac(1,3) dot 0 $
  $ "Gain"(S_("baja, >150"), "Memoria") approx 0.251629 $

Se selecciona *Memoria*. La rama `>4` termina en *S*. En la rama `<=4` no quedan atributos y hay un empate de 1 *S* y 1 *N*. Se adopta explícitamente como regla de desempate la mayoría del nodo padre $S_("baja, >150")$, que contiene 2 *S* y 1 *N*; por ello, la hoja se etiqueta como *S*.

=== Cuarta iteración: rama duración media

El subconjunto $S_("media")$ contiene D11--D15: 2 *S* y 3 *N*, con entropía inicial $0.970951$. Se evalúan *Memoria* y *Precio*.

+ Evaluando *Memoria* en $S_("media")$

  - `<=4`: D11 y D13; 1 *S* y 1 *N*, por lo que $"Entropía"(S_("media, <=4")) = 1$.
  - `>4`: D12, D14 y D15; 1 *S* y 2 *N*.

    $ "Entropía"(S_("media, >4")) = -frac(1,3) log_2 frac(1,3) - frac(2,3) log_2 frac(2,3) approx 0.918296 $

  $ "Gain"(S_("media"), "Memoria") = 0.970951 - frac(2,5) dot 1 - frac(3,5) dot 0.918296 $
  $ "Gain"(S_("media"), "Memoria") approx 0.019973 $

+ Evaluando *Precio* en $S_("media")$

  - `<=150`: D11, D12 y D15, todos de clase *N*; por tanto, $"Entropía"(S_("media, <=150")) = 0$.
  - `>150`: D13 y D14, ambos de clase *S*; por tanto, $"Entropía"(S_("media, >150")) = 0$.

  $ "Gain"(S_("media"), "Precio") = 0.970951 - frac(3,5) dot 0 - frac(2,5) dot 0 $
  $ "Gain"(S_("media"), "Precio") = 0.970951 $

*Precio* es el atributo seleccionado. Así, `media` y `<=150` se clasifica como *N*, mientras que `media` y `>150` se clasifica como *S*.

=== Árbol de decisión final

#figure(
  image("../../src/img/ejercicio1.png", width: 88%),
  caption: [Árbol de decisión del ejercicio 1.]
) <fig:tree_p1>
