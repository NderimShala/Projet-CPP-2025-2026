cmake_minimum_required(VERSION 3.10)

# Nom du projet
project(ApplicGarage)

# Standard C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Trouver Qt5
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)

# Fichiers sources
file(GLOB SOURCES "Sources/*.cpp")

# Création de l'exécutable
add_executable(${PROJECT_NAME} ${SOURCES})

# Includes
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/includes
)

# Lier les bibliothèques Qt
target_link_libraries(${PROJECT_NAME}
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
)
