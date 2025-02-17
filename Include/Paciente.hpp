// Sesi�n 6 - Programaci�n orientada a objetos I
// Principios b�sicos de la programaci�n orientada a objetos
// Principios de abstracci�n
// aqu� definimos la clase con sus atributos privados como vimos en clase

#ifndef PACIENTE_HPP
#define PACIENTE_HPP

#include <string>




// esta es la clase paciente que usamos para guardar todos los datos
// la hago como el ejemplo de clase



class Paciente {
private:
    // estos son los datos privados que no se pueden tocar desde fuera
    std::string nombre;
    std::string id;
    std::string fechaIngreso;
    bool enfermedadCronica;  // esto para marcar si tiene algo cr�nico



public:
    // Sesi�n 2 - Funciones
    // constructores que vimos que hay que poner siempre
    Paciente();
    // este es el constructor con todos los datos que necesitamos
    Paciente(std::string nombre, std::string id, std::string fechaIngreso);






    // Sesi�n 3 - Funciones avanzadas
    // getters y setters para acceder a los datos privados
    // estos son para poder ver y cambiar los datos desde fuera
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