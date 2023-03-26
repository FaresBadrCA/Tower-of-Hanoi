# CMakeList.txt : CMake project for threePoles, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (threePoles "threePoles.cpp" "threePoles.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET threePoles PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
