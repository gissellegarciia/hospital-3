
// Sesi�n 6 - Programaci�n orientada a objetos I
// - Principios b�sicos de la programaci�n orientada a objetos
// aqu� implementamos todas las funciones que declaramos en el .hpp

#include "Paciente.hpp"

// constructor vac�o, inicializo todo a valores por defecto
// como nos dijo el profe que era buena pr�ctica
Paciente::Paciente() {
    nombre = "";
    id = "";
    fechaIngreso = "";
    enfermedadCronica = false;
}

// constructor con todos los datos, este es el que usaremos normalmente
Paciente::Paciente(std::string nombre, std::string id, std::string fechaIngreso) {
    // Sesi�n 4 - Punteros y referencias
    // uso el this-> que vimos en clase para evitar l�os con los nombres
    this->nombre = nombre;
    this->id = id;
    this->fechaIngreso = fechaIngreso;
    this->enfermedadCronica = false;  // por defecto no tiene enfermedad cr�nica
}

// Sesi�n 3 - Funciones avanzadas
// implementaci�n de los getters y setters
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