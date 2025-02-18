#include "Cita.hpp"

// Constructor vacío
Cita::Cita() {
    fecha = "";
    hora = "";
    idPaciente = "";
    idDoctor = "";
    urgente = false;
}

// Constructor con parámetros
Cita::Cita(std::string fecha, std::string hora, std::string idPaciente, std::string idDoctor) {
    this->fecha = fecha;
    this->hora = hora;
    this->idPaciente = idPaciente;
    this->idDoctor = idDoctor;
    this->urgente = false;
}

// Getters y setters
std::string Cita::getFecha() const {
    return fecha;
}

void Cita::setFecha(std::string fecha) {
    this->fecha = fecha;
}

std::string Cita::getHora() const {
    return hora;
}

void Cita::setHora(std::string hora) {
    this->hora = hora;
}

std::string Cita::getIdPaciente() const {
    return idPaciente;
}

void Cita::setIdPaciente(std::string id) {
    this->idPaciente = id;
}

std::string Cita::getIdDoctor() const {
    return idDoctor;
}

void Cita::setIdDoctor(std::string id) {
    this->idDoctor = id;
}

bool Cita::getUrgente() const {
    return urgente;
}

void Cita::setUrgente(bool urgente) {
    this->urgente = urgente;
}