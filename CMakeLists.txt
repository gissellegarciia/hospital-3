# Sesión 8 - Implementación del código
# División y manejo del código de C++ en varios archivos
# Uso de CMake para la gestión del proyecto
# esto lo usamos para organizar el código 

cmake_minimum_required(VERSION 3.10)
project(hospital-3)




# Sesión 3 - Funciones avanzadas
# Configuración del estándar de C++
# aquí ponemos el C++ moderno que es mejor para lo que queremos hacer
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



# Sesión 8 - Implementación del código
# División y manejo del código de C++ en varios archivos
# así encuentra las carpetas donde metemos los .hpp
include_directories(${PROJECT_SOURCE_DIR}/include)




# Sesión 8 - Implementación del código
# División y manejo del código de C++ en varios archivos
# aquí metemos todos los .cpp que necesitamos compilar
add_executable(hospital-3
   src/main.cpp
   src/Paciente.cpp
   src/Doctor.cpp
   src/Cita.cpp
)