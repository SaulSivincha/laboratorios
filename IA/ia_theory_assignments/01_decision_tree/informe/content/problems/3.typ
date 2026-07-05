= Ejercicio 3

== Problema

Un apostador quiere apostar sobre el próximo partido de Grand Slam entre Federer
Nadal, que tendrá lugar a las 16:00 de la tarde en tierra batida. Los
periodistas dicen que Federer está un poco cansado tras del partido de
semifinales y que probablemente no estará al 100 %. Utilizando los datos
históricos en figura, el apostador construye un árbol de decisión con el
algoritmo ID3. El atributo Best Effort vale 1 si en el partido Federer ha jugado
al 100 %, en caso contrario vale 0. Sobre qué jugador deberá apostar?

#figure(
  table(
    columns: (auto, auto, auto, auto, auto),
    align: center,

    [Time], [Match type], [Court surface], [Best Effort], [Outcome],

    [Morning], [Master], [Grass], [1], [F],
    [Afternoon], [Grand slam], [Clay], [1], [F],
    [Night], [Friendly], [Hard], [0], [F],
    [Afternoon], [Friendly], [Mixed], [0], [N],
    [Afternoon], [Master], [Clay], [1], [N],
    [Afternoon], [Grand slam], [Grass], [1], [F],
    [Afternoon], [Grand slam], [Hard], [1], [F],
    [Afternoon], [Grand slam], [Hard], [1], [F],
    [Morning], [Master], [Grass], [1], [F],
    [Afternoon], [Grand slam], [Clay], [0], [N],
    [Night], [Friendly], [Hard], [0], [F],
    [Night], [Master], [Mixed], [1], [N],
    [Afternoon], [Master], [Clay], [1], [N],
    [Afternoon], [Master], [Grass], [1], [F],
    [Afternoon], [Grand slam], [Hard], [1], [F],
    [Afternoon], [Grand slam], [Clay], [1], [F],
  ),
  caption: [Datos de entrenamiento ejercicio 3],
)

== Resolución

A continuación de describen los pasos a seguir:

+ Calculo de la entropía del sistema:

  Se tienen 16 datos en total, según su número de ocurrencias la frecuencia de
  la clase $F$ (Federer) es 11 y de la clase $N$ es 5, por lo tanto la
  probabilidad de las clases es $p_F=11/16$ y $p_N=5/16$. Así que se procede a
  calcular la entropía del sistema.



  $ "Entropía"(S) = -p_F log_2(p_F) - p_N log_2(p_N) $ <ecu:entropia_g>
  $ "Entropía"(S) = -11/16 log_2(11/16) - 5/16 log_2(5/16) $
  $ "Entropía"(S) approx 0.89604 $

+ Selección del nodo raíz (Ganancia de Información):

  Para determinar qué atributo ocupará la raíz del árbol de decisión, se debe
  calcular la ganancia de información $"Gain"(S, A)$ para cada uno de los cuatro
  atributos disponibles: `Time`, `Match type`, `Court surface` y `Best Effort`.
  La fórmula general de la ganancia de información es:

  $ "Gain"(S, A) = "Entropía"(S) - sum_(v in "Valores"(A)) (abs(S_v)/abs(S)) "Entropía"(S_v) $

  Donde $"Entropía"(S) approx 0.89604$

  + Evaluando el atributo `Time`

    Este atributo tiene 3 valores posibles: `Morning`, `Afternoon` y `Night`
    para calcular la entropía de cada una de ellas (al igual que los demás
    atributos) se usa la @ecu:entropia_g.

    - `Morning`: Aparece en 2 instancias. Ambas corresponden a la clase $F$ (0 para $N$).
      $ "Entropía"(S_("Morning")) = - 2/2 log_2(2/2) - 0/2 log_2(0/2) = 0.00000 $

    - `Afternoon`: Aparece en 11 instancias. De ellas, 7 son de la clase $F$ y 4 son de la clase $N$.
    $ "Entropía"(S_("Afternoon")) = - 7/11 log_2(7/11) - 4/11 log_2(4/11) $
    $ "Entropía"(S_("Afternoon")) approx 0.41495 + 0.53071 = 0.94566 $

    - `Night`: Aparece en 3 instancias. De ellas, 2 son de la clase $F$ y 1 es de la clase $N$.
      $ "Entropía"(S_("Night")) = - 2/3 log_2(2/3) - 1/3 log_2(1/3) $
      $ "Entropía"(S_("Night")) approx 0.38997 + 0.52832 = 0.91829 $

    Calculando la ganancia para `Time`:
    $ G a i n(S, "Time") = 0.89604 - [ 2/16 (0.00000) + 11/16 (0.94566) + 3/16 (0.91829) ] $
    $ G a i n(S, "Time") = 0.89604 - 0.82232 = 0.07372 $

  + Evaluando el atributo `Match type`

    Este atributo tiene 3 valores posibles: `Master`, `Grand slam` y `Friendly`.

    - `Master`: Aparece en 6 instancias. 3 corresponden a la clase $F$ y 3 corresponden a $N$.
      $ "Entropía"(S_("Master")) = - 3/6 log_2(3/6) - 3/6 log_2(3/6) = 1.00000 $

    - `Grand slam`: Aparece en 7 instancias. 6 corresponden a la clase $F$ y 1 corresponde a $N$.
      $ "Entropía"(S_("Grand slam")) = - 6/7 log_2(6/7) - 1/7 log_2(1/7) $
      $ "Entropía"(S_("Grand slam")) approx 0.19062 + 0.40106 = 0.59168 $

    - `Friendly`: Aparece en 3 instancias. 2 corresponden a la clase $F$ y 1 corresponde a $N$.
      $ "Entropía"(S_("Friendly")) = - 2/3 log_2(2/3) - 1/3 log_2(1/3) approx 0.91829 $

    Calculando la ganancia para `Match type`:
    $ G a i n(S, "Match type") = 0.89604 - [ 6/16 (1.00000) + 7/16 (0.59168) + 3/16 (0.91829) ] $
    $ G a i n(S, "Match type") = 0.89604 - 0.80604 = 0.09000 $

  + Evaluando el atributo `Court surface`

    Este atributo tiene 4 valores posibles: `Grass`, `Clay`, `Hard` y `Mixed`.

    - `Grass`: Aparece en 4 instancias. Todas corresponden a la clase $F$.
      $ "Entropía"(S_("Grass")) = 0.00000 $

    - `Hard`: Aparece en 5 instancias. Todas corresponden a la clase $F$.
      $ "Entropía"(S_("Hard")) = 0.00000 $

    - `Mixed`: Aparece en 2 instancias. Todas corresponden a la clase $N$.
      $ "Entropía"(S_("Mixed")) = 0.00000 $

    - `Clay`: Aparece en 5 instancias. De ellas, 2 corresponden a $F$ y 3 corresponden a $N$.
      $ "Entropía"(S_("Clay")) = - 2/5 log_2(2/5) - 3/5 log_2(3/5) $
      $ "Entropía"(S_("Clay")) approx 0.52877 + 0.44218 = 0.97095 $

    Calculando la ganancia para `Court surface`:
    $ G a i n(S, "Court surface") = 0.89604 - [ 4/16 (0) + 5/16 (0.97095) + 5/16 (0) + 2/16 (0) ] $
    $ G a i n(S, "Court surface") = 0.89604 - 0.30342 = 0.59262 $

  + Evaluando el atributo `Best Effort`

    Este atributo tiene 2 valores posibles: `1` y `0`.

    - `1`: Aparece en 12 instancias. De ellas, 9 corresponden a $F$ y 3 corresponden a $N$.
      $ "Entropía"(S_("Best Effort = 1")) = - 9/12 log_2(9/12) - 3/12 log_2(3/12) $
      $ "Entropía"(S_("Best Effort = 1")) approx 0.31128 + 0.50000 = 0.81128 $

    - `0`: Aparece en 4 instancias. De ellas, 2 corresponden a $F$ y 2 corresponden a $N$.
      $ "Entropía"(S_("Best Effort = 0")) = - 2/4 log_2(2/4) - 2/4 log_2(2/4) = 1.00000 $

    Calculando la ganancia para `Best Effort`:
    $ G a i n(S, "Best Effort") = 0.89604 - [ 12/16 (0.81128) + 4/16 (1.00000) ] $
    $ G a i n(S, "Best Effort") = 0.89604 - 0.85846 = 0.03758 $

  + Conclusión de la selección del nodo raíz

    Comparando los valores obtenidos de ganancia de información:

    - $G a i n(S, "Time") = 0.07372$
    - $G a i n(S, "Match type") = 0.09000$
    - $G a i n(S, "Court surface") = 0.59262$
    - $G a i n(S, "Best Effort") = 0.03758$

    El atributo con la mayor ganancia de información es `Court surface`. Por lo tanto, según las reglas del algoritmo ID3, este atributo se selecciona de manera unívoca para formar el nodo raíz del árbol de decisión.

+ Desarrollo de ramas para el nodo `Match type` en $S_("Clay")$:

  Dado que se seleccionó `Match type` como nodo de decisión para la rama `Clay`, se evalúan las instancias para cada uno de sus 2 valores posibles.

  - `Master`: El subconjunto $S_("Clay, Master")$ contiene 2 instancias, ambas de la clase $N$. $"Entropía"(S_("Clay, Master")) = 0.00000$. Se crea un nodo hoja con el valor $N$.
  - `Grand slam`: El subconjunto $S_("Clay, Grand slam")$ contiene 3 instancias, con una mezcla de clases (2 correspondientes a $F$ y 1 correspondiente a $N$). Su entropía es $"Entropía"(S_("Clay, Grand slam")) approx 0.91829$. Al ser mayor a 0, se debe aplicar el algoritmo de forma recursiva sobre este subconjunto.

+ Iteración sobre el subconjunto $S_("Clay, Grand slam")$ (Cálculo de nueva Ganancia):

  El subconjunto $S_("Clay, Grand slam")$ cuenta con 3 instancias y su entropía inicial es $0.91829$. Los atributos restantes disponibles para evaluar son `Time` y `Best Effort`.

  + Evaluando el atributo `Time` en $S_("Clay, Grand slam")$

    Las 3 instancias comparten el mismo valor `Afternoon`.

    - `Afternoon`: 2 instancias son de la clase $F$ y 1 es de la clase $N$.
      $ "Entropía"(S_("Clay, Grand slam, Afternoon")) = - 2/3 log_2(2/3) - 1/3 log_2(1/3) approx 0.91829 $

    Calculando la ganancia para `Time`:
    $ G a i n(S_("Clay, Grand slam"), "Time") = 0.91829 - [ 3/3 (0.91829) ] $
    $ G a i n(S_("Clay, Grand slam"), "Time") = 0.91829 - 0.91829 = 0.00000 $

  + Evaluando el atributo `Best Effort` en $S_("Clay, Grand slam")$

    En este subconjunto, el atributo presenta los valores `1` y `0`.

    - `1`: Aparece en 2 instancias. Ambas corresponden a la clase $F$ (0 para $N$).
      $ "Entropía"(S_("Clay, Grand slam, Best Effort=1")) = 0.00000 $

    - `0`: Aparece en 1 instancia. Corresponde a la clase $N$.
      $ "Entropía"(S_("Clay, Grand slam, Best Effort=0")) = 0.00000 $

    Calculando la ganancia para `Best Effort`:
    $ G a i n(S_("Clay, Grand slam"), "Best Effort") = 0.91829 - [ 2/3 (0.00000) + 1/3 (0.00000) ] $
    $ G a i n(S_("Clay, Grand slam"), "Best Effort") = 0.91829 - 0.00000 = 0.91829 $

  + Conclusión de la tercera iteración

    Comparando los valores obtenidos de ganancia de información para el subconjunto $S_("Clay, Grand slam")$:

    - $G a i n(S_("Clay, Grand slam"), "Time") = 0.00000$
    - $G a i n(S_("Clay, Grand slam"), "Best Effort") = 0.91829$

    El atributo con la mayor ganancia de información es `Best Effort`. Por lo tanto, se establece de manera unívoca como el siguiente nodo de decisión en la rama correspondiente a `Clay > Grand slam`.

+ Desarrollo de ramas para el nodo `Best Effort` en $S_("Clay, Grand slam")$:

  Dado que se seleccionó `Best Effort` como nodo de decisión para la rama `Clay > Grand slam`, se evalúan las instancias para cada uno de sus 2 valores posibles.

  - `1`: El subconjunto contiene 2 instancias, ambas de la clase $F$. $"Entropía"(S_("Clay, Grand slam, Best Effort=1")) = 0.00000$. Se crea un nodo hoja con el valor $F$.
  - `0`: El subconjunto contiene 1 instancia, correspondiente a la clase $N$. $"Entropía"(S_("Clay, Grand slam, Best Effort=0")) = 0.00000$. Se crea un nodo hoja con el valor $N$.

  Con esto, todos los nodos hoja han sido definidos y el árbol de decisión queda completamente construido.

+ Clasificación del problema planteado:

  El apostador requiere evaluar el escenario con las siguientes características extraídas del enunciado inicial:
  - `Time`: 16:00 (`Afternoon`)
  - `Match type`: `Grand slam`
  - `Court surface`: Tierra batida (`Clay`)
  - `Best Effort`: No estará al 100% (`0`)

  Navegando por el árbol de decisión final ilustrado en la @fig:tree_p3, se sigue el siguiente camino:
  1. Nodo raíz `Court surface`: El valor es `Clay`, por lo que se desciende por esa rama.
  2. Siguiente nodo `Match type`: El valor es `Grand slam`, se desciende por esa rama.
  3. Siguiente nodo `Best Effort`: El valor es `0`, se desciende por esa rama.
  4. La hoja resultante para este camino es $N$.

  El apostador deberá apostar por Nadal.

#figure(
  image("/informe/src/img/tree_3.pdf", width: 80%),
  caption: [Árbol de decisión del problema 3.]
) <fig:tree_p3>
