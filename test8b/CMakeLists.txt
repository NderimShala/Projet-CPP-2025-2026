cmake_minimum_required (VERSION 3.10)

#Nom du projet
project(Test8b)

#Spécifier le standard C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#include le repertoire include
include_directories("${CMAKE_SOURCE_DIR}/Headers")


#ajouter les fichiers sources automatiquement
file(GLOB SOURCES "Sources/*.cpp")

#ajouter l'executable
add_executable(${PROJECT_NAME} ${SOURCES})
