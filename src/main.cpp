

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <regex>
#include "Paciente.hpp"
#include "Doctor.hpp"
#include "Cita.hpp"

std::vector<Paciente> pacientes;
std::vector<Doctor> doctores;
std::vector<Cita> citas;

void limpiarBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Función para validar que una cadena no esté vacía
bool validarCadenaNoVacia(const std::string& cadena, const std::string& mensaje) {
    if (cadena.empty()) {
        std::cout << "Error: " << mensaje << " no puede estar vacío.\n";
        return false;
    }
    return true;
}

// Función para validar que una cadena contenga solo letras
bool validarSoloLetras(const std::string& cadena, const std::string& mensaje) {
    for (char c : cadena) {
        if (!std::isalpha(c) && !std::isspace(c)) {
            std::cout << "Error: " << mensaje << " debe contener solo letras.\n";
            return false;
        }
    }
    return true;
}

// Función para validar que una cadena contenga solo dígitos
bool validarSoloDigitos(const std::string& cadena, const std::string& mensaje) {
    for (char c : cadena) {
        if (!std::isdigit(c)) {
            std::cout << "Error: " << mensaje << " debe contener solo dígitos.\n";
            return false;
        }
    }
    return !cadena.empty();
}

// Función para validar formato de fecha (YYYY-MM-DD)
bool validarFormatoFecha(const std::string& fecha) {
    std::regex fechaRegex("^\\d{4}-\\d{2}-\\d{2}$");
    if (!std::regex_match(fecha, fechaRegex)) {
        std::cout << "Error: La fecha debe tener el formato YYYY-MM-DD.\n";
        return false;
    }
    return true;
}

void gestionPacientes() {
    int opcionPaciente;
    bool volverMenu = false;

    while (!volverMenu) {
        std::cout << "\nGestion de Pacientes\n";
        std::cout << "Pacientes registrados: " << pacientes.size() << "\n";
        std::cout << "1. Registrar paciente\n";
        std::cout << "2. Buscar paciente\n";
        std::cout << "3. Listar pacientes\n";
        std::cout << "4. Volver\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcionPaciente;
        limpiarBuffer();

        switch (opcionPaciente) {
        case 1: {
            std::string nombre, id, fecha;
            bool datosValidos = false;

            while (!datosValidos) {
                // Validación de nombre
                while (true) {
                    std::cout << "Nombre: ";
                    std::getline(std::cin, nombre);
                    if (validarCadenaNoVacia(nombre, "Nombre") &&
                        validarSoloLetras(nombre, "Nombre")) {
                        break;
                    }
                }

                // Validación de ID
                while (true) {
                    std::cout << "ID (solo dígitos): ";
                    std::getline(std::cin, id);

                    // Verificar que el ID sea único
                    bool idExiste = false;
                    for (const Paciente& p : pacientes) {
                        if (p.getId() == id) {
                            idExiste = true;
                            break;
                        }
                    }

                    if (validarSoloDigitos(id, "ID") && !idExiste) {
                        break;
                    }

                    if (idExiste) {
                        std::cout << "Error: El ID ya existe. Ingrese un ID diferente.\n";
                    }
                }

                // Validación de fecha de ingreso
                while (true) {
                    std::cout << "Fecha de ingreso (YYYY-MM-DD): ";
                    std::getline(std::cin, fecha);
                    if (validarFormatoFecha(fecha)) {
                        break;
                    }
                }

                // Confirmación de datos
                std::cout << "\nConfirmar datos:\n";
                std::cout << "Nombre: " << nombre << "\n";
                std::cout << "ID: " << id << "\n";
                std::cout << "Fecha de ingreso: " << fecha << "\n";

                std::string confirmacion;
                std::cout << "¿Son correctos estos datos? (s/n): ";
                std::getline(std::cin, confirmacion);

                if (confirmacion == "s" || confirmacion == "S") {
                    Paciente nuevoPaciente(nombre, id, fecha);
                    pacientes.push_back(nuevoPaciente);
                    std::cout << "Paciente registrado con éxito\n";
                    datosValidos = true;
                }
            }
            break;
        }
        case 2: {
            std::string idBuscar;
            std::cout << "Ingrese ID del paciente: ";
            std::getline(std::cin, idBuscar);

            bool encontrado = false;
            for (const Paciente& p : pacientes) {
                if (p.getId() == idBuscar) {
                    std::cout << "Paciente encontrado:\n";
                    std::cout << "Nombre: " << p.getNombre() << "\n";
                    std::cout << "Fecha de ingreso: " << p.getFechaIngreso() << "\n";
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) std::cout << "Paciente no encontrado\n";
            break;
        }
        case 3: {
            if (pacientes.empty()) {
                std::cout << "No hay pacientes registrados\n";
            }
            else {
                std::cout << "Lista de pacientes:\n";
                for (const Paciente& p : pacientes) {
                    std::cout << "ID: " << p.getId() << " - Nombre: " << p.getNombre() << "\n";
                }
            }
            break;
        }
        case 4:
            volverMenu = true;
            break;
        default:
            std::cout << "Opcion no valida\n";
        }
    }
}

void gestionDoctores() {
    int opcionDoctor;
    bool volverMenu = false;

    while (!volverMenu) {
        std::cout << "\nGestion de Doctores\n";
        std::cout << "Doctores registrados: " << doctores.size() << "\n";
        std::cout << "1. Registrar doctor\n";
        std::cout << "2. Buscar doctor\n";
        std::cout << "3. Listar doctores\n";
        std::cout << "4. Volver\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcionDoctor;
        limpiarBuffer();

        switch (opcionDoctor) {
        case 1: {
            std::string nombre, id, especialidad;
            bool datosValidos = false;

            while (!datosValidos) {
                // Validación de nombre
                while (true) {
                    std::cout << "Nombre: ";
                    std::getline(std::cin, nombre);
                    if (validarCadenaNoVacia(nombre, "Nombre") &&
                        validarSoloLetras(nombre, "Nombre")) {
                        break;
                    }
                }

                // Validación de ID
                while (true) {
                    std::cout << "ID (solo dígitos): ";
                    std::getline(std::cin, id);

                    // Verificar que el ID sea único
                    bool idExiste = false;
                    for (const Doctor& d : doctores) {
                        if (d.getId() == id) {
                            idExiste = true;
                            break;
                        }
                    }

                    if (validarSoloDigitos(id, "ID") && !idExiste) {
                        break;
                    }

                    if (idExiste) {
                        std::cout << "Error: El ID ya existe. Ingrese un ID diferente.\n";
                    }
                }

                // Validación de especialidad
                while (true) {
                    std::cout << "Especialidad: ";
                    std::getline(std::cin, especialidad);
                    if (validarCadenaNoVacia(especialidad, "Especialidad") &&
                        validarSoloLetras(especialidad, "Especialidad")) {
                        break;
                    }
                }

                // Confirmación de datos
                std::cout << "\nConfirmar datos:\n";
                std::cout << "Nombre: " << nombre << "\n";
                std::cout << "ID: " << id << "\n";
                std::cout << "Especialidad: " << especialidad << "\n";

                std::string confirmacion;
                std::cout << "¿Son correctos estos datos? (s/n): ";
                std::getline(std::cin, confirmacion);

                if (confirmacion == "s" || confirmacion == "S") {
                    Doctor nuevoDoctor(nombre, id, especialidad);
                    doctores.push_back(nuevoDoctor);
                    std::cout << "Doctor registrado con éxito\n";
                    datosValidos = true;
                }
            }
            break;
        }
        case 2: {
            std::string idBuscar;
            std::cout << "Ingrese ID del doctor: ";
            std::getline(std::cin, idBuscar);

            bool encontrado = false;
            for (const Doctor& d : doctores) {
                if (d.getId() == idBuscar) {
                    std::cout << "Doctor encontrado:\n";
                    std::cout << "Nombre: " << d.getNombre() << "\n";
                    std::cout << "Especialidad: " << d.getEspecialidad() << "\n";
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) std::cout << "Doctor no encontrado\n";
            break;
        }
        case 3: {
            if (doctores.empty()) {
                std::cout << "No hay doctores registrados\n";
            }
            else {
                std::cout << "Lista de doctores:\n";
                for (const Doctor& d : doctores) {
                    std::cout << "ID: " << d.getId() << " - Nombre: " << d.getNombre()
                        << " - Especialidad: " << d.getEspecialidad() << "\n";
                }
            }
            break;
        }
        case 4:
            volverMenu = true;
            break;
        default:
            std::cout << "Opcion no valida\n";
        }
    }
}

void gestionCitas() {
    int opcionCita;
    bool volverMenu = false;

    while (!volverMenu) {
        std::cout << "\nGestion de Citas\n";
        std::cout << "Citas registradas: " << citas.size() << "\n";
        std::cout << "1. Programar cita\n";
        std::cout << "2. Buscar cita\n";
        std::cout << "3. Listar citas\n";
        std::cout << "4. Volver\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcionCita;
        limpiarBuffer();

        switch (opcionCita) {
        case 1: {
            std::string fecha, hora, idPaciente, idDoctor;

            // Validación de fecha
            while (true) {
                std::cout << "Fecha (YYYY-MM-DD): ";
                std::getline(std::cin, fecha);
                if (validarFormatoFecha(fecha)) {
                    break;
                }
            }

            // Validación de hora
            while (true) {
                std::cout << "Hora (HH:MM): ";
                std::getline(std::cin, hora);
                std::regex horaRegex("^([01]\\d|2[0-3]):([0-5]\\d)$");
                if (std::regex_match(hora, horaRegex)) {
                    break;
                }
                std::cout << "Error: La hora debe tener el formato HH:MM (00:00 - 23:59).\n";
            }

            // Validación de ID de paciente
            while (true) {
                std::cout << "ID del paciente: ";
                std::getline(std::cin, idPaciente);

                bool pacienteEncontrado = false;
                for (const Paciente& p : pacientes) {
                    if (p.getId() == idPaciente) {
                        pacienteEncontrado = true;
                        break;
                    }
                }

                if (validarSoloDigitos(idPaciente, "ID del paciente") && pacienteEncontrado) {
                    break;
                }

                if (!pacienteEncontrado) {
                    std::cout << "Error: Paciente no encontrado. Ingrese un ID válido.\n";
                }
            }

            // Validación de ID de doctor
            while (true) {
                std::cout << "ID del doctor: ";
                std::getline(std::cin, idDoctor);

                bool doctorEncontrado = false;
                for (const Doctor& d : doctores) {
                    if (d.getId() == idDoctor) {
                        doctorEncontrado = true;
                        break;
                    }
                }

                if (validarSoloDigitos(idDoctor, "ID del doctor") && doctorEncontrado) {
                    break;
                }

                if (!doctorEncontrado) {
                    std::cout << "Error: Doctor no encontrado. Ingrese un ID válido.\n";
                }
            }

            // Confirmación de datos
            std::cout << "\nConfirmar datos de la cita:\n";
            std::cout << "Fecha: " << fecha << "\n";
            std::cout << "Hora: " << hora << "\n";
            std::cout << "ID Paciente: " << idPaciente << "\n";
            std::cout << "ID Doctor: " << idDoctor << "\n";

            std::string confirmacion;
            std::cout << "¿Son correctos estos datos? (s/n): ";
            std::getline(std::cin, confirmacion);

            if (confirmacion == "s" || confirmacion == "S") {
                Cita nuevaCita(fecha, hora, idPaciente, idDoctor);
                citas.push_back(nuevaCita);
                std::cout << "Cita programada con éxito\n";
            }
            break;
        }
        case 2: {
            std::string idPacienteBuscar;
            std::cout << "Ingrese ID del paciente: ";
            std::getline(std::cin, idPacienteBuscar);

            bool encontrado = false;
            for (const Cita& c : citas) {
                if (c.getIdPaciente() == idPacienteBuscar) {
                    std::cout << "Cita encontrada:\n";
                    std::cout << "Fecha: " << c.getFecha() << "\n";
                    std::cout << "Hora: " << c.getHora() << "\n";
                    std::cout << "Doctor ID: " << c.getIdDoctor() << "\n";
                    encontrado = true;
                }
            }
            if (!encontrado) std::cout << "No se encontraron citas para este paciente\n";
            break;
        }
        case 3: {
            if (citas.empty()) {
                std::cout << "No hay citas registradas\n";
            }
            else {
                std::cout << "Lista de citas:\n";
                for (const Cita& c : citas) {
                    std::cout << "Fecha: " << c.getFecha() << " - Hora: " << c.getHora()
                        << " - Paciente ID: " << c.getIdPaciente()
                        << " - Doctor ID: " << c.getIdDoctor() << "\n";
                }
            }
            break;
        }
        case 4:
            volverMenu = true;
            break;
        default:
            std::cout << "Opcion no valida\n";
        }
    }
}

void mostrarMenu() {
    std::cout << "\n=== Sistema de Gestion Hospitalaria ===\n";
    std::cout << "1. Gestion de Pacientes\n";
    std::cout << "2. Gestion de Doctores\n";
    std::cout << "3. Gestion de Citas\n";
    std::cout << "4. Salir\n";
    std::cout << "Seleccione una opcion: ";
}

int main() {
    int opcion;
    bool ejecutar = true;

    while (ejecutar) {
        mostrarMenu();
        std::cin >> opcion;
        limpiarBuffer();

        switch (opcion) {
        case 1:
            gestionPacientes();
            break;
        case 2:
            gestionDoctores();
            break;
        case 3:
            gestionCitas();
            break;
        case 4:
            ejecutar = false;
            std::cout << "Gracias por usar el sistema\n";
            break;
        default:
            std::cout << "Opcion no valida\n";
        }
    }

    return 0;
}