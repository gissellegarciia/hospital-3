
// conecta pacientes con doctores
// relaciones entre clases

#ifndef CITA_HPP
#define CITA_HPP

#include <string>

class Cita {
private:
    std::string fecha;
    std::string hora;
    // Guardo solo los IDs como strings porque es más fácil
    std::string idPaciente;
    std::string idDoctor;
    bool urgente;  // Esto lo añadí para las citas urgentes que tienen prioridad

public:
    Cita();  // Constructor vacío por si acaso
    // Este es el constructor principal que usamos para crear citas
    Cita(std::string fecha, std::string hora, std::string idPaciente, std::string idDoctor);

    // Los getters y setters de siempre
    std::string getFecha() const;
    void setFecha(std::string fecha);
    std::string getHora() const;
    void setHora(std::string hora);
    std::string getIdPaciente() const;
    void setIdPaciente(std::string id);
    std::string getIdDoctor() const;
    void setIdDoctor(std::string id);
    bool getUrgente() const;
    void setUrgente(bool urgente);
};

#endif