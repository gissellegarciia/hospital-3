// Sesi�n 6 - Programaci�n orientada a objetos 1
// Principios b�sicos de la programaci�n orientada a objetos
// aqu� va la clase del doctor con sus datos

#ifndef DOCTOR_HPP
#define DOCTOR_HPP

#include <string>
#include <vector>  // esto lo usamos para las listas 



class Doctor {
private:
    // igual que en paciente
    std::string nombre;
    std::string id;
    std::string especialidad;
    bool disponible;  // para saber si est� libre o no




public:
    Doctor();
    Doctor(std::string nombre, std::string id, std::string especialidad);

    // m�s getters y setters
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