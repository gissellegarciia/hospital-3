// Sesi�n 6 - Programaci�n orientada a objetos I
// - Principios b�sicos de la programaci�n orientada a objetos
// implementaci�n de la clase Doctor, igual que hicimos con Paciente

#include "Doctor.hpp"

// constructor vac�o otra vez, igual que en paciente
Doctor::Doctor() {
    nombre = "";
    id = "";
    especialidad = "";
    disponible = true;  // por defecto est� disponible
}

Doctor::Doctor(std::string nombre, std::string id, std::string especialidad) {
    this->nombre = nombre;
    this->id = id;
    this->especialidad = especialidad;
    this->disponible = true;
}

// getters y setters
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