#import "informe/util/util.typ" as util
#import "informe/config.typ" as config
#import "informe/style.typ": template

#show: template

// Funciones de Formateo locales
#let headerBig(content) = util.fontBuild(content, "bold", 12pt, center, black)
#let headerSmall(content) = util.fontBuild(content, "regular", 9pt, center, black)

// --- Carátula ---
#align(center + horizon)[
  #block(
    stroke: 0.5pt + black,
    inset: 2em,
    width: 100%,
    [
      #v(1em)
      #headerBig(upper(config.university))
      #v(0.5em)
      #headerBig(upper(config.faculty))
      #v(0.5em)
      #headerBig(upper(config.professionalSchool))

      #v(2em)
      #image("informe/src/img/fixed/Escudo_UNSA.png", width: 4cm)
      #v(2em)

      #align(left)[
        #grid(
          columns: (auto, 1fr),
          gutter: 1em,
          [Curso:], [#strong(config.courseName)],
          [Docente:], [#strong(config.instructorName)],
        )
      ]

      #v(2em)
      #headerBig(config.reportTitle)
      #headerBig(config.reportSubtitle)
      #v(2em)

      #align(left)[
        #grid(
          columns: (auto, 1fr),
          gutter: 1em,
          align: left + top,
          [Elaborado por:], [#util.unordList(config.memberList)],
          [Observaciones:], [],
        )
        #v(0.5em)
      ]

      #v(3em)
      #config.presentationDate \
      #config.city - #config.country
      #v(1em)
    ],
  )
]

#pagebreak()

// --- Configuración de Encabezado para Contenido ---
#set page(
  header: context {
    if counter(page).get().at(0) > 1 {
      block(width: 100%, stroke: (bottom: 0.5pt + gray), inset: (bottom: 1em))[
        #grid(
          columns: (1fr, 3fr, 1fr),
          align: horizon,
          image("informe/src/img/fixed/logo_episunsa.png", width: 2.5cm),
          [
            #set text(size: 8pt)
            #align(center)[
              #config.university \
              #config.faculty \
              #config.professionalSchool
            ]
          ],
          image("informe/src/img/fixed/logo_abet.png", height: 1cm),
        )
      ]
    }
  },
  footer: context {
    if counter(page).get().at(0) > 1 {
      align(center, counter(page).display("1"))
    }
  },
  margin: (top: 4.5cm, bottom: 2.5cm, left: 2.5cm, right: 2.5cm),
)

#counter(page).update(1)

// --- Contenido ---
#include "informe/content/informe.typ"

// --- Bibliografía ---
#v(2em)
#bibliography("informe/references.bib", style: "ieee")
