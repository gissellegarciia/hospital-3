// Sesión 6 - Programación orientada a objetos I
// - Principios básicos de la programación orientada a objetos
// aquí implementamos todas las funciones que declaramos en el .hpp

#include "Paciente.hpp"

// constructor vacío, inicializo todo a valores por defecto
// como nos dijo el profe que era buena práctica
Paciente::Paciente() {
    nombre = "";
    id = "";
    fechaIngreso = "";
    enfermedadCronica = false;
}

// constructor con todos los datos, este es el que usaremos normalmente
Paciente::Paciente(std::string nombre, std::string id, std::string fechaIngreso) {
    // Sesión 4 - Punteros y referencias
    // uso el this-> que vimos en clase para evitar líos con los nombres
    this->nombre = nombre;
    this->id = id;
    this->fechaIngreso = fechaIngreso;
    this->enfermedadCronica = false;  // por defecto no tiene enfermedad crónica
}

// Sesión 3 - Funciones avanzadas
// implementación de los getters y setters
// son facilitos pero hay que ponerlos todos
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