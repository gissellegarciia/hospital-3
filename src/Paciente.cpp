// Sesión 6 - POO I y Sesión 4 - Punteros y referencias
// Aquí implemento todas las funciones que declaré en el .hpp
// this-> que aprendimos en la sesión 4

#include "Paciente.hpp"

// Constructor vacío, inicio todo a valores por defecto

Paciente::Paciente() {
    nombre = "";
    id = "";
    fechaIngreso = "";
    enfermedadCronica = false;
}

// Este es el constructor que uso normalmente, con todos los datos
Paciente::Paciente(std::string nombre, std::string id, std::string fechaIngreso) {
    // Uso el this->
    this->nombre = nombre;
    this->id = id;
    this->fechaIngreso = fechaIngreso;
    this->enfermedadCronica = false;  // Por defecto no tiene enfermedad crónica
}

// Sesión 3 - Funciones avanzadas
// Aquí van todos los getters y setters
// Son súper simples pero hay que ponerlos todos
std::string Paciente::getNombre() const {
    return nombre;
}

void Paciente::setNombre(std::string nombre) {
    this->nombre = nombre;
}

std::string Paciente::getId() const {
    return id;
}

void Paciente::setId(std::string id) {
    this->id = id;
}

std::string Paciente::getFechaIngreso() const {
    return fechaIngreso;
}

void Paciente::setFechaIngreso(std::string fecha) {
    this->fechaIngreso = fecha;
}

bool Paciente::getEnfermedadCronica() const {
    return enfermedadCronica;
}

void Paciente::setEnfermedadCronica(bool cronica) {
    this->enfermedadCronica = cronica;
}