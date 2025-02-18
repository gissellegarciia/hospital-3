// Sesi�n 6 - Programaci�n orientada a objetos I
// Esta es la primera clase que hicimos
// Aqu� solo van las declaraciones


#ifndef PACIENTE_HPP
#define PACIENTE_HPP

#include <string>

// Esta es la clase principal para guardar los datos de los pacientes
// principios de abstracci�n - sesi�n 6
class Paciente {
private:

    // Estos son los datos privados del paciente
    // para que nadie los pueda
    // cambiar directamente desde fuera
    std::string nombre;
    std::string id;
    std::string fechaIngreso;
    bool enfermedadCronica;  // Para marcar si tiene algo cr�nico

public:
    // Sesi�n 2 - Funciones
    // Estos son los constructores que siempre hay que poner
    Paciente();  // Constructor vac�o por si acaso
    Paciente(std::string nombre, std::string id, std::string fechaIngreso);  // El que usaremos normalmente

    // Sesi�n 3 - Funciones avanzadas
    // Getters y setters para poder ver y cambiar los datos desde fuera
   
    std::string getNombre() const;
    void setNombre(std::string nombre);
    std::string getId() const;
    void setId(std::string id);
    std::string getFechaIngreso() const;
    void setFechaIngreso(std::string fecha);
    bool getEnfermedadCronica() const;
    void setEnfermedadCronica(bool cronica);
};

#endif