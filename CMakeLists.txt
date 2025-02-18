# Sesión 8 - Implementación del código


cmake_minimum_required(VERSION 3.10)
project(hospital-3)  # Este es el nombre de mi proyecto

# Configuramos el estándar de C++ que vamos a usar
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Le decimos dónde están los archivos de cabecera
include_directories(${PROJECT_SOURCE_DIR}/include)

# Añadimos el ejecutable con todos los archivos .cpp
add_executable(hospital-3
    src/main.cpp
    src/Paciente.cpp
    src/Doctor.cpp
    src/Cita.cpp
)