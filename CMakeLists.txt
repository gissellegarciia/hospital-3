cmake_minimum_required(VERSION 3.10)
project(hospital-3)  # Nombre original del proyecto

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

# Corregido el nombre del ejecutable para que coincida
add_executable(hospital-3
    src/main.cpp
    src/Paciente.cpp
    src/Doctor.cpp
    src/Cita.cpp
)