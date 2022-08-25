(lang dune 3.4)

(name mlcpp_filesystem)

(generate_opam_files true)

(source
 (github CodiePP/ml-cpp-filesystem))

(authors "Alexander Diemand <codieplusplus@apax.net>")

(maintainers "Alexander Diemand <codieplusplus@apax.net>")

(license LICENSE)

(documentation https://url/to/documentation)

(package
 (name mlcpp_filesystem)
 (synopsis "OCaml embedded C++ filesystem")
 (description "C++ filesystem is a cross-platform abstraction of filesystem access now available in OCaml")
 (depends ocaml dune)
 (tags
  (topics "cross-platform filesystem abstraction" your project)))

; See the complete stanza docs at https://dune.readthedocs.io/en/stable/dune-files.html#dune-project
