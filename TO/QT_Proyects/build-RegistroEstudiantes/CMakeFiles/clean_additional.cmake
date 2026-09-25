# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/RegistroEstudiantes_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/RegistroEstudiantes_autogen.dir/ParseCache.txt"
  "RegistroEstudiantes_autogen"
  )
endif()
