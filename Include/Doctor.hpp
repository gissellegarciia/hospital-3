// Sesión 6 - Programación orientada a objetos I


#ifndef DOCTOR_HPP
#define DOCTOR_HPP

#include <string>
#include <vector>  // Esto lo necesito para las listas

class Doctor {
private:
    // Los datos privados del doctor, igual que en paciente
    std::string nombre;
    std::string id;
    std::string especialidad;
    bool disponible;  // Esto es para saber si está libre o no

public:
    // Los constructores de siempre
    Doctor();
    Doctor(std::string nombre, std::string id, std::string especialidad);

    // Getters y setters como en la clase Paciente
    std::string getNombre() const;
    void setNombre(std::string nombre);
    std::string getId() const;
    void setId(std::string id);
    std::string getEspecialidad() const;
    void setEspecialidad(std::string especialidad);
    bool getDisponible() const;
    void setDisponible(bool disponible);
};

#endif