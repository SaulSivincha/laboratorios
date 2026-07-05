#import "../util/util.typ" as util

= Hola mundo

== Hola mundo 2

=== Hola mundo 3

Aquí se muestra algo de código:

#figure(
  raw(read("../src/lst/hello.c"), lang: "c",block: true),
  caption: [Hola Mundo],
)


Aquí se muestra la @fig:fig1:

#figure(
  image("../src/img/fixed/logo-unsa.png", width: 70%),
  caption: [Hola Figura]
)<fig:fig1>

Aquí quiero citar a este libro desconocido @oxford.

#lorem(100)
