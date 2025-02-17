#include <iostream>
#include <string>
#include <vector>
#include "Paciente.hpp"
#include "Doctor.hpp"
#include "Cita.hpp"

std::vector<Paciente> pacientes;
std::vector<Doctor> doctores;
std::vector<Cita> citas;

void mostrarMenu() {
    std::cout << "\n=== Sistema de Gestión Hospitalaria ===\n";
    std::cout << "1. Gestión de Pacientes\n";
    std::cout << "2. Gestión de Doctores\n";
    std::cout << "3. Gestión de Citas\n";
    std::cout << "4. Salir\n";
    std::cout << "Seleccione una opción: ";
}

int main() {
    int opcion;
    bool ejecutar = true;

    while (ejecutar) {
        mostrarMenu();
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            std::cout << "\nGestión de Pacientes\n";
            std::cout << "Pacientes registrados: " << pacientes.size() << "\n";
            break;
        case 2:
            std::cout << "\nGestión de Doctores\n";
            std::cout << "Doctores registrados: " << doctores.size() << "\n";
            break;
        case 3:
            std::cout << "\nGestión de Citas\n";
            std::cout << "Citas registradas: " << citas.size() << "\n";
            break;
        case 4:
            ejecutar = false;
            std::cout << "Gracias por usar el sistema\n";
            break;
        default:
            std::cout << "Opción no válida\n";
        }
    }

    std::cout << "\nPresione Enter para salir...";
    std::cin.ignore();
    std::cin.get();
    return 0;
}