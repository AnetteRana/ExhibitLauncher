# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ExhibitLauncher_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ExhibitLauncher_autogen.dir\\ParseCache.txt"
  "ExhibitLauncher_autogen"
  )
endif()
