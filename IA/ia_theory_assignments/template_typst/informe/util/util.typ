// Utilidades para Typst
#let codeBgColor = rgb("#F1F3F4")

#let fontBuild(content, weight, size, alignTo, color) = [
  #set text(size: size, weight: weight, fill: color)
  #if alignTo != none [
    #align(alignTo)[#content]
  ] else [
    #content
  ]
]

#let unordList(items) = [
  #set list(indent: 1em, marker: "-")
  #for item in items [
    - #item
  ]
]
