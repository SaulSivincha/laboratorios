= Ejercicio 2
Una empresa de videojuegos tiene que desarrollar los personajes artificiales de un juego de rol.  Los personajes necesitan un mecanismo para decidir si atacar o no un adversario, dada la relación de alianza entre sus respectivas poblaciones, el nivel de defensa y la tribu de pertenencia. Se  decide utilizar el algoritmo ID3 para aprender el árbol de decisión que usará cada personaje para su toma de decisión, utilizando como datos de entrenamiento los ejemplos en la tabla en figura.

Para resolver este problema de forma sistemática, se recurre al algoritmo *ID3* (Iterative Dichotomiser 3), un método clásico de aprendizaje automático supervisado que construye un árbol de decisión a partir de ejemplos históricos. La ventaja de este enfoque es que el árbol resultante es completamente interpretable: cada nodo representa una pregunta sobre el entorno, y cada rama conduce a una conclusión clara.

Las variables disponibles para tomar la decisión son tres:

- *Alianza*: la relación diplomática entre las poblaciones del personaje y su adversario (Friendly / Enemy).
- *Defensa*: el nivel de resistencia del adversario (Weak / Medium / Strong).
- *Tribu*: la civilización a la que pertenece el adversario (Celtic, Norse, Greek, Aztec).

La variable objetivo es binaria: *Atacar* (Sí / No).


== Datos 

El conjunto de datos utilizado para entrenar el árbol está formado por nueve ejemplos etiquetados manualmente, que recogen situaciones de combate anteriores junto con la decisión que se tomó en cada caso.

#v(0.5em)

#align(center)[
  #table(
    columns: (auto, auto, auto, auto, auto),
    inset: 8pt,
    align: center,
    fill: (col, row) => if row == 0 { rgb("#1a3a5c") } else if calc.even(row) { rgb("#eef3f8") } else { white },
    text(fill: white, weight: "bold")[Ejemplo],
    text(fill: white, weight: "bold")[Alianza],
    text(fill: white, weight: "bold")[Defensa],
    text(fill: white, weight: "bold")[Tribu],
    text(fill: white, weight: "bold")[Atacar],
    [D1], [Friendly], [Weak],   [Celtic], [NO],
    [D2], [Enemy],    [Weak],   [Celtic], [SÍ],
    [D3], [Friendly], [Strong], [Norse],  [NO],
    [D4], [Enemy],    [Strong], [Norse],  [NO],
    [D5], [Friendly], [Weak],   [Greek],  [SÍ],
    [D6], [Enemy],    [Medium], [Greek],  [SÍ],
    [D7], [Enemy],    [Strong], [Greek],  [NO],
    [D8], [Enemy],    [Medium], [Aztec],  [SÍ],
    [D9], [Friendly], [Weak],   [Aztec],  [NO],
  )
]

#v(0.5em)

Del total de nueve ejemplos, cuatro tienen respuesta *SÍ* (D2, D5, D6, D8) y cinco tienen respuesta *NO* (D1, D3, D4, D7, D9). 
== Resolución

=== Primera Iteración: Selección del Nodo Raíz

+ Calculo de la entropía del sistema completo

  Con 4 casos positivos y 5 negativos sobre un total de 9 ejemplos. Se procede a calcular la entropía del conjunto completo:

  $ H(S) = -frac(4,9) log_2 frac(4,9) - frac(5,9) log_2 frac(5,9) approx 0.99 $

  El valor de 0.99 bits confirma que el conjunto está prácticamente mezclado, lo que significa que aún no sabemos nada útil sin consultar alguna de las variables.

+ Ganancia de información por variable

  Calculamos este valor para cada una de las tres variables disponibles.

  + Variable: Alianza

    Al dividir el conjunto según la alianza, obtenemos dos subgrupos:

    - *Friendly* (D1, D3, D5, D9): 1 SÍ, 3 NO → $H("Fr") = -frac(1,4) log_2 frac(1,4) - frac(3,4) log_2 frac(3,4) approx 0.81$
    - *Enemy* (D2, D4, D6, D7, D8): 3 SÍ, 2 NO → $H("En") = -frac(3,5) log_2 frac(3,5) - frac(2,5) log_2 frac(2,5) approx 0.97$

    $ "Gain"(S, "Alianza") = 0.99 - frac(4,9) dot 0.81 - frac(5,9) dot 0.97 approx 0.091 $

  + Variable: Defensa

    Al dividir por nivel de defensa, los subgrupos son:

    - *Weak* (D1, D2, D5, D9): 2 SÍ, 2 NO → $H("We") = 1$
    - *Medium* (D6, D8): 2 SÍ, 0 NO → $H("Me") = 0$ _(grupo puro)_
    - *Strong* (D3, D4, D7): 0 SÍ, 3 NO → $H("St") = 0$ _(grupo puro)_

    $ "Gain"(S, "Defensa") = 0.99 - frac(4,9) dot 1 - frac(2,9) dot 0 - frac(3,9) dot 0 approx 0.55 $

  + Variable: Tribu

    Dividiendo por tribu:

    - *Celtic* (D1, D2): 1 SÍ, 1 NO → $H("Ce") = 1$
    - *Norse* (D3, D4): 0 SÍ, 2 NO → $H("No") = 0$
    - *Greek* (D5, D6, D7): 2 SÍ, 1 NO → $H("Gr") approx 0.92$
    - *Aztec* (D8, D9): 1 SÍ, 1 NO → $H("Az") = 1$

    $ "Gain"(S, "Tribu") = 0.99 - frac(2,9) dot 1 - frac(2,9) dot 0 - frac(3,9) dot 0.92 - frac(2,9) dot 1 approx 0.243 $

  +  Decisión: nodo raíz

    Comparando las tres ganancias:

    #align(center)[
      #table(
        columns: (auto, auto, auto),
        inset: 8pt,
        align: (left, center, left),
        fill: (col, row) => if row == 0 { rgb("#1a3a5c") } else if row == 1 { rgb("#d4edda") } else { white },
        text(fill: white, weight: "bold")[Variable],
        text(fill: white, weight: "bold")[Gain],
        text(fill: white, weight: "bold")[],
        [Defensa],  [*0.55*], [Mayor ganancia ],
        [Tribu],    [0.243], [],
        [Alianza],  [0.091], [],
      )
    ]

    #v(0.3em)

    El nodo raíz del árbol será, por tanto, la variable *Defensa*. Dos de sus tres ramas quedan resueltas de inmediato:

    - *Strong* → *NO ATACAR* (D3, D4, D7 son todos negativos).
    - *Medium* → *SÍ ATACAR* (D6, D8 son todos positivos).
    - *Weak* → Grupo mixto. Necesita seguir ramificándose.

=== Segunda Iteración: Subárbol para Defensa Débil

Los cuatro ejemplos con defensa débil son: *D1, D2, D5 y D9*. Este subconjunto tiene 2 casos positivos y 2 negativos, por lo que su entropía es máxima:

$ H(S_"Weak") = 1 $

Debemos elegir entre las dos variables restantes (Alianza y Tribu) cuál divide mejor este subgrupo.

+ Ganancia de Alianza en S_Weak

  - *Friendly* (D1, D9): 0 SÍ, 2 NO → $H("Fr") approx 0.92$ _(D5 es Friendly/Greek con SÍ, pero en este cálculo el subgrupo Friendly contiene D1 y D9 con 1 SÍ y 2 NO)_

  Aclarando los subgrupos correctos dentro de $S_"Weak"$:

  - *Friendly* (D1, D5, D9): 1 SÍ, 2 NO → $H("Fr") = -frac(1,3) log_2 frac(1,3) - frac(2,3) log_2 frac(2,3) approx 0.92$
  - *Enemy* (D2): 1 SÍ, 0 NO → $H("En") = 0$

  $ "Gain"(S_"Weak", "Alianza") = 1 - frac(3,4) dot 0.92 - frac(1,4) dot 0 approx 0.31 $

+ Ganancia de Tribu en S_Weak

  - *Celtic* (D1, D2): 1 SÍ, 1 NO → $H("Ce") = 1$
  - *Greek* (D5): 1 SÍ, 0 NO → $H("Gr") = 0$ _(grupo puro)_
  - *Aztec* (D9): 0 SÍ, 1 NO → $H("Az") = 0$ _(grupo puro)_

  $ "Gain"(S_"Weak", "Tribu") = 1 - frac(2,4) dot 1 - frac(1,4) dot 0 - frac(1,4) dot 0 = 0.5 $

+ Decisión: segundo nodo

  #align(center)[
    #table(
      columns: (auto, auto, auto),
      inset: 8pt,
      align: (left, center, left),
      fill: (col, row) => if row == 0 { rgb("#2c5f8a") } else if row == 1 { rgb("#d4edda") } else { white },
      text(fill: white, weight: "bold")[Variable],
      text(fill: white, weight: "bold")[Gain],
      text(fill: white, weight: "bold")[],
      [Tribu],   [*0.5*],  [Mayor ganancia],
      [Alianza], [0.31],   [],
    )
  ]

  #v(0.3em)

  La *Tribu* es la variable más informativa en este nivel. Al ramificar por tribu, tres de las cuatro ramas quedan resueltas:

  - *Greek* (D5) → *SÍ ATACAR* (grupo puro positivo).
  - *Aztec* (D9) → *NO ATACAR* (grupo puro negativo).
  - *Celtic* (D1, D2) → Grupo mixto. Se necesita una variable más.

  _(Nota: Norse no aparece entre los ejemplos de defensa débil, por lo que esa rama no aplica en este nivel.)_


=== Tercera Iteración: Subárbol para Celtas con Defensa Débil

Sólo quedan dos ejemplos sin resolver: *D1* (Celtic, Friendly, NO) y *D2* (Celtic, Enemy, SÍ). La única variable disponible es *Alianza*.

La división es perfecta:

- *Enemy* (D2): 1 SÍ, 0 NO → *SÍ ATACAR*
- *Friendly* (D1): 0 SÍ, 1 NO → *NO ATACAR*

Ambas ramas son grupos puros, por lo que el árbol queda completamente construido.


=== Árbol de Decisión Final

El árbol de decisión resultante tiene la siguiente estructura lógica:

#v(0.5em)

#figure(
  image("../../src/img/image-1.png", width: 80%),
  caption: [Árbol de decisión del problema 2.]
) <fig:tree_p2>

