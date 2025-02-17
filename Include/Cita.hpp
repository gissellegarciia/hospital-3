// Sesión 6 - Programación orientada a objetos I
// - Principios bбsicos de la programaciуn orientada a objetos
// última clase que implementamos, ya casi acabamos

#ifndef CITA_HPP
#define CITA_HPP

#include <string>

class Cita {
private:
    std::string fecha;
    std::string hora;
    // guardo solo los IDs como strings y ya está
    std::string idPaciente;
    std::string idDoctor;
    bool urgente;  // para las citas urgentes que tienen prioridad

public:
    // lo demбs se queda igual
    Cita();
    // NUEVO: Constructor con todos los parámetros para crear citas completas
    Cita(std::string fecha, std::string hora, std::string idPaciente, std::string idDoctor);

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