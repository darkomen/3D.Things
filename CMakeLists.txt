 #Minimum version required for CMake
cmake_minimum_required (VERSION 2.6)
 
#Name of the project
project (Robot)
 
#Compile in Debug Mode. Allows to make debug.
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -ggdb")
SET(CMAKE_BUILD_TYPE "debugfull" )
 
#Set a variable with the directory path.
SET(OOM_TRUNK_DIR ${CMAKE_CURRENT_SOURCE_DIR})
 
#Set a variable with the path of the application.
SET(EXECUTABLE_OUTPUT_PATH ${OOM_TRUNK_DIR}/bin)
 
#In Linux and Mac OS/X the Path is /usr/include/ooml
INCLUDE_DIRECTORIES("/usr/include/ooml")
 
#Set a variable with the name of the cpp source files of your application
SET(FILE_LIST main.cpp)
 
#Set a variable with the name of your application
SET(EXE_NAME Robot)
 
#Create and link the executable
ADD_EXECUTABLE(${EXE_NAME} ${FILE_LIST})
TARGET_LINK_LIBRARIES(${EXE_NAME} OOMLCore OOMLComponents OOMLParts)
