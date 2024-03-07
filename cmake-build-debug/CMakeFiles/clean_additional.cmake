# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/QNatTester_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/QNatTester_autogen.dir/ParseCache.txt"
  "QNatTester_autogen"
  )
endif()
