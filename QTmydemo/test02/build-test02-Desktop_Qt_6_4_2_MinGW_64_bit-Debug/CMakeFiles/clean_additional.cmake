# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\test02_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\test02_autogen.dir\\ParseCache.txt"
  "test02_autogen"
  )
endif()
