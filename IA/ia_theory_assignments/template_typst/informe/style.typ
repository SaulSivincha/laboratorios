#let template(body) = {
  // Colors
  let codeBgColor = rgb("#F1F3F4")
  // Page
  set par(justify: true)
  set text(
    font: "Lato",
    size: 11pt,
    lang: "es",
  )
  set page(
    paper: "a4",
    margin: (top: 2.5cm, bottom: 2.5cm, left: 2.5cm, right: 2.5cm),
  )
  set heading(numbering: "1.")
  // Elements
  show raw.where(block: true): it => block(
    fill: codeBgColor, // Slightly off-black for better contrast
    width: auto,
    inset: 2em,
    radius: 8pt,
    breakable: true,
    // Ensure the text inside is white
    text(fill: rgb("303030"), it),
  )
  show figure: set block(breakable: true)
  body
}
