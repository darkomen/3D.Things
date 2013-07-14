# Main project declaration
PROJECT(REPY-2.0)

# Verbose or not verbose
IF($ENV{VERBOSE})
	MESSAGE(STATUS "Verbose mode on")
ELSE($ENV{VERBOSE})
	MESSAGE(STATUS "Verbose mode off (type 'VERBOSE=1 cmake .' to enable it)")
ENDIF($ENV{VERBOSE})

# Needed by CMake versione 2.6 or later (Run "cmake --help-policy CMP0003" for more information.)"
# specifically, we are using full-path when possible for linking libraries
# this should be mandatory for packages found using ROOT directive
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# Optional flags and configurable stuff in ccmake
# Replacement for manual.cmake
SET(COMPILATION_FLAGS "-W -Wall -O2 -ggdb" CACHE STRING "CMake compilation flags")
SET(CMAKE_BUILD_TYPE "Debug")

# You may have to replace /usr/include/ooml for the corresponding folder on your computer
SET(OOML_INCLUDE_DIR "/usr/include/ooml" CACHE STRING "OOML Include Dir")
SET(OOML_LINK_DIR "/usr/lib" CACHE STRING "OOML Libraries Directory")

INCLUDE_DIRECTORIES(${OOML_INCLUDE_DIR})
LINK_DIRECTORIES(${OOML_LINK_DIR})

ADD_EXECUTABLE(REPY-2.0 main.cpp basicservo.cpp fakefutaba3003sservo.cpp futaba3003sservo.cpp towerprosg90servo.cpp repy_module.cpp skymegaboard.cpp)
TARGET_LINK_LIBRARIES(REPY-2.0 OOMLCore OOMLParts OOMLComponents)

