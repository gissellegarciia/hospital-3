// Sesi�n 6 - POO I
// Esta implementaci�n es muy parecida a la de Paciente porque las clases son bastante similares

#include "Doctor.hpp"

// Constructor vac�o, igual que en Paciente
Doctor::Doctor() {
    nombre = "";
    id = "";
    especialidad = "";
    disponible = true;  // Por defecto est� disponible
}

// Constructor con todos los datos
Doctor::Doctor(std::string nombre, std::string id, std::string especialidad) {
    this->nombre = nombre;
    this->id = id;
    this->especialidad = especialidad;
    this->disponible = true;  // Por defecto est� disponible
}

// Los getters y setters, igualito que en Paciente
std::string Doctor::getNombre() const {
    return nombre;
}

void Doctor::setNombre(std::string nombre) {
    this->nombre = nombre;
}

std::string Doctor::getId() const {
    return id;
}

void Doctor::setId(std::string id) {
    this->id = id;
}

std::string Doctor::getEspecialidad() const {
    return especialidad;
}

void Doctor::setEspecialidad(std::string especialidad) {
    this->especialidad = especialidad;
}

bool Doctor::getDisponible() const {
    return disponible;
}

void Doctor::setDisponible(bool disponible) {
    this->disponible = disponible;
}