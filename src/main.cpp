#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Paciente.hpp"
#include "Doctor.hpp"
#include "Cita.hpp"

// Variables globales (Sesión 2)
std::vector<Paciente> pacientes;
std::vector<Doctor> doctores;
std::vector<Cita> citas;

// Funciones de utilidad (Sesión 2 - Funciones)
void limpiarBuffer() {
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}

// Funciones de validación (Sesión 2 - Funciones)
bool validarCadenaNoVacia(const std::string& cadena) {
    if (cadena.empty()) {
        std::cout << "Error: El campo no puede estar vacio.\n";
        return false;
    }
    return true;
}

bool validarSoloLetras(const std::string& cadena) {
    for (char c : cadena) {
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ')) {
            std::cout << "Error: Solo se permiten letras.\n";
            return false;
        }
    }
    return true;
}

bool validarSoloNumeros(const std::string& cadena) {
    for (char c : cadena) {
        if (!(c >= '0' && c <= '9')) {
            std::cout << "Error: Solo se permiten numeros.\n";
            return false;
        }
    }
    return true;
}

bool validarFormatoFecha(const std::string& fecha) {
    if (fecha.length() != 10) {
        std::cout << "Error: La fecha debe tener el formato YYYY-MM-DD.\n";
        return false;
    }
    if (fecha[4] != '-' || fecha[7] != '-') {
        std::cout << "Error: La fecha debe tener el formato YYYY-MM-DD.\n";
        return false;
    }
    for (int i = 0; i < 10; i++) {
        if (i != 4 && i != 7) {
            if (fecha[i] < '0' || fecha[i] > '9') {
                std::cout << "Error: La fecha debe contener solo numeros y guiones.\n";
                return false;
            }
        }
    }
    return true;
}

bool validarFormatoHora(const std::string& hora) {
    if (hora.length() != 5) {
        std::cout << "Error: La hora debe tener el formato HH:MM.\n";
        return false;
    }
    if (hora[2] != ':') {
        std::cout << "Error: La hora debe tener el formato HH:MM.\n";
        return false;
    }
    for (int i = 0; i < 5; i++) {
        if (i != 2) {
            if (hora[i] < '0' || hora[i] > '9') {
                std::cout << "Error: La hora debe contener solo numeros y dos puntos.\n";
                return false;
            }
        }
    }
    return true;
}

// Funciones para manejo de archivos (Sesión 3 - Acceso a archivos)
void guardarDatos() {
    // Guardar pacientes
    std::ofstream archivoPacientes("pacientes.txt");
    for (const auto& paciente : pacientes) {
        archivoPacientes << paciente.getNombre() << "\n"
            << paciente.getId() << "\n"
            << paciente.getFechaIngreso() << "\n";
    }
    archivoPacientes.close();

    // Guardar doctores
    std::ofstream archivoDoctores("doctores.txt");
    for (const auto& doctor : doctores) {
        archivoDoctores << doctor.getNombre() << "\n"
            << doctor.getId() << "\n"
            << doctor.getEspecialidad() << "\n";
    }
    archivoDoctores.close();

    // Guardar citas
    std::ofstream archivoCitas("citas.txt");
    for (const auto& cita : citas) {
        archivoCitas << cita.getFecha() << "\n"
            << cita.getHora() << "\n"
            << cita.getIdPaciente() << "\n"
            << cita.getIdDoctor() << "\n";
    }
    archivoCitas.close();
}

void cargarDatos() {
    // Cargar pacientes
    std::ifstream archivoPacientes("pacientes.txt");
    std::string nombre, id, fecha;
    while (getline(archivoPacientes, nombre)) {
        getline(archivoPacientes, id);
        getline(archivoPacientes, fecha);
        Paciente nuevoPaciente(nombre, id, fecha);
        pacientes.push_back(nuevoPaciente);
    }
    archivoPacientes.close();

    // Cargar doctores
    std::ifstream archivoDoctores("doctores.txt");
    std::string especialidad;
    while (getline(archivoDoctores, nombre)) {
        getline(archivoDoctores, id);
        getline(archivoDoctores, especialidad);
        Doctor nuevoDoctor(nombre, id, especialidad);
        doctores.push_back(nuevoDoctor);
    }
    archivoDoctores.close();

    // Cargar citas
    std::ifstream archivoCitas("citas.txt");
    std::string hora, idPaciente, idDoctor;
    while (getline(archivoCitas, fecha)) {
        getline(archivoCitas, hora);
        getline(archivoCitas, idPaciente);
        getline(archivoCitas, idDoctor);
        Cita nuevaCita(fecha, hora, idPaciente, idDoctor);
        citas.push_back(nuevaCita);
    }
    archivoCitas.close();
}

// Funciones de gestión (Sesión 2 - Funciones)
void gestionPacientes() {
    while (true) {
        std::cout << "\nGestion de Pacientes\n"
            << "1. Registrar paciente\n"
            << "2. Buscar paciente\n"
            << "3. Listar pacientes\n"
            << "4. Eliminar paciente\n"
            << "5. Volver\n"
            << "Opcion: ";

        int opcion;
        std::cin >> opcion;
        limpiarBuffer();

        if (opcion == 5) break;

        switch (opcion) {
        case 1: {
            std::string nombre, id, fecha;

            do {
                std::cout << "Nombre: ";
                getline(std::cin, nombre);
            } while (!validarCadenaNoVacia(nombre) || !validarSoloLetras(nombre));

            do {
                std::cout << "ID: ";
                getline(std::cin, id);
            } while (!validarSoloNumeros(id));

            std::cout << "Fecha (YYYY-MM-DD): ";
            getline(std::cin, fecha);

            pacientes.push_back(Paciente(nombre, id, fecha));
            std::cout << "Paciente registrado\n";
            break;
        }
        case 2: {
            std::cout << "ID a buscar: ";
            std::string idBuscar;
            getline(std::cin, idBuscar);

            for (const auto& paciente : pacientes) {
                if (paciente.getId() == idBuscar) {
                    std::cout << "Nombre: " << paciente.getNombre() << "\n"
                        << "Fecha: " << paciente.getFechaIngreso() << "\n";
                    break;
                }
            }
            break;
        }
        case 3: {
            for (const auto& paciente : pacientes) {
                std::cout << "ID: " << paciente.getId()
                    << " - Nombre: " << paciente.getNombre() << "\n";
            }
            break;
        }
        case 4: {
            std::cout << "ID del paciente a eliminar: ";
            std::string idEliminar;
            getline(std::cin, idEliminar);

            bool encontrado = false;
            for (size_t i = 0; i < pacientes.size(); i++) {
                if (pacientes[i].getId() == idEliminar) {
                    // Verificar si el paciente tiene citas
                    bool tieneCitas = false;
                    for (const auto& cita : citas) {
                        if (cita.getIdPaciente() == idEliminar) {
                            tieneCitas = true;
                            break;
                        }
                    }

                    if (tieneCitas) {
                        std::cout << "No se puede eliminar el paciente porque tiene citas programadas\n";
                    }
                    else {
                        std::cout << "Estas seguro de eliminar al paciente " << pacientes[i].getNombre() << "? (s/n): ";
                        std::string confirmar;
                        getline(std::cin, confirmar);

                        if (confirmar == "s" || confirmar == "S") {
                            pacientes.erase(pacientes.begin() + i);
                            std::cout << "Paciente eliminado\n";
                        }
                    }
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                std::cout << "Paciente no encontrado\n";
            }
            break;
        }
        default:
            std::cout << "Opcion invalida\n";
        }
    }
}

void gestionDoctores() {
    while (true) {
        std::cout << "\nGestion de Doctores\n"
            << "1. Registrar doctor\n"
            << "2. Buscar doctor\n"
            << "3. Listar doctores\n"
            << "4. Eliminar doctor\n"
            << "5. Volver\n"
            << "Opcion: ";

        int opcion;
        std::cin >> opcion;
        limpiarBuffer();

        if (opcion == 5) break;

        switch (opcion) {
        case 1: {
            std::string nombre, id, especialidad;

            do {
                std::cout << "Nombre: ";
                getline(std::cin, nombre);
            } while (!validarCadenaNoVacia(nombre) || !validarSoloLetras(nombre));

            do {
                std::cout << "ID: ";
                getline(std::cin, id);
            } while (!validarSoloNumeros(id));

            do {
                std::cout << "Especialidad: ";
                getline(std::cin, especialidad);
            } while (!validarCadenaNoVacia(especialidad) || !validarSoloLetras(especialidad));

            doctores.push_back(Doctor(nombre, id, especialidad));
            std::cout << "Doctor registrado\n";
            break;
        }
        case 2: {
            std::cout << "ID a buscar: ";
            std::string idBuscar;
            getline(std::cin, idBuscar);

            for (const auto& doctor : doctores) {
                if (doctor.getId() == idBuscar) {
                    std::cout << "Nombre: " << doctor.getNombre() << "\n"
                        << "Especialidad: " << doctor.getEspecialidad() << "\n";
                    break;
                }
            }
            break;
        }
        case 3: {
            for (const auto& doctor : doctores) {
                std::cout << "ID: " << doctor.getId()
                    << " - Nombre: " << doctor.getNombre()
                    << " - Especialidad: " << doctor.getEspecialidad() << "\n";
            }
            break;
        }
        case 4: {
            std::cout << "ID del doctor a eliminar: ";
            std::string idEliminar;
            getline(std::cin, idEliminar);

            bool encontrado = false;
            for (size_t i = 0; i < doctores.size(); i++) {
                if (doctores[i].getId() == idEliminar) {
                    // Verificar si el doctor tiene citas
                    bool tieneCitas = false;
                    for (const auto& cita : citas) {
                        if (cita.getIdDoctor() == idEliminar) {
                            tieneCitas = true;
                            break;
                        }
                    }

                    if (tieneCitas) {
                        std::cout << "No se puede eliminar el doctor porque tiene citas programadas\n";
                    }
                    else {
                        std::cout << "Estas seguro de eliminar al doctor " << doctores[i].getNombre() << "? (s/n): ";
                        std::string confirmar;
                        getline(std::cin, confirmar);

                        if (confirmar == "s" || confirmar == "S") {
                            doctores.erase(doctores.begin() + i);
                            std::cout << "Doctor eliminado\n";
                        }
                    }
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                std::cout << "Doctor no encontrado\n";
            }
            break;
        }
        default:
            std::cout << "Opcion invalida\n";
        }
    }
}

void gestionCitas() {
    while (true) {
        std::cout << "\nGestion de Citas\n"
            << "1. Programar cita\n"
            << "2. Buscar cita\n"
            << "3. Listar citas\n"
            << "4. Eliminar cita\n"
            << "5. Volver\n"
            << "Opcion: ";

        int opcion;
        std::cin >> opcion;
        limpiarBuffer();

        if (opcion == 5) break;

        switch (opcion) {
        case 1: {
            std::string fecha, hora, idPaciente, idDoctor;

            do {
                std::cout << "Fecha (YYYY-MM-DD): ";
                getline(std::cin, fecha);
            } while (!validarFormatoFecha(fecha));

            do {
                std::cout << "Hora (HH:MM): ";
                getline(std::cin, hora);
            } while (!validarFormatoHora(hora));

            bool pacienteValido = false;
            do {
                std::cout << "ID del paciente: ";
                getline(std::cin, idPaciente);
                for (const auto& paciente : pacientes) {
                    if (paciente.getId() == idPaciente) {
                        pacienteValido = true;
                        break;
                    }
                }
                if (!pacienteValido) std::cout << "Paciente no encontrado\n";
            } while (!pacienteValido);

            bool doctorValido = false;
            do {
                std::cout << "ID del doctor: ";
                getline(std::cin, idDoctor);
                for (const auto& doctor : doctores) {
                    if (doctor.getId() == idDoctor) {
                        doctorValido = true;
                        break;
                    }
                }
                if (!doctorValido) std::cout << "Doctor no encontrado\n";
            } while (!doctorValido);

            citas.push_back(Cita(fecha, hora, idPaciente, idDoctor));
            std::cout << "Cita programada\n";
            break;
        }
        case 2: {
            std::cout << "ID del paciente: ";
            std::string idBuscar;
            getline(std::cin, idBuscar);

            bool encontrado = false;
            for (const auto& cita : citas) {
                if (cita.getIdPaciente() == idBuscar) {
                    std::cout << "Fecha: " << cita.getFecha() << "\n"
                        << "Hora: " << cita.getHora() << "\n"
                        << "ID Doctor: " << cita.getIdDoctor() << "\n";
                    encontrado = true;
                }
            }
            if (!encontrado) {
                std::cout << "No se encontraron citas\n";
            }
            break;
        }
        case 3: {
            for (const auto& cita : citas) {
                std::cout << "Fecha: " << cita.getFecha()
                    << " - Hora: " << cita.getHora()
                    << " - ID Paciente: " << cita.getIdPaciente()
                    << " - ID Doctor: " << cita.getIdDoctor() << "\n";
            }
            break;
        }
        case 4: {
            std::string idPaciente, fecha, hora;
            std::cout << "ID del paciente: ";
            getline(std::cin, idPaciente);
            std::cout << "Fecha de la cita (YYYY-MM-DD): ";
            getline(std::cin, fecha);
            std::cout << "Hora de la cita (HH:MM): ";
            getline(std::cin, hora);

            bool encontrado = false;
            for (size_t i = 0; i < citas.size(); i++) {
                if (citas[i].getIdPaciente() == idPaciente &&
                    citas[i].getFecha() == fecha &&
                    citas[i].getHora() == hora) {

                    std::cout << "Estas seguro de eliminar la cita? (s/n): ";
                    std::string confirmar;
                    getline(std::cin, confirmar);

                    if (confirmar == "s" || confirmar == "S") {
                        citas.erase(citas.begin() + i);
                        std::cout << "Cita eliminada\n";
                    }
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                std::cout << "Cita no encontrada\n";
            }
            break;
        }
        default:
            std::cout << "Opcion invalida\n";
        }
    }
}

// Función principal del menú (Sesión 2 - Funciones)
void mostrarMenu() {
    std::cout << "\n=== Hospital MSMK ===\n"
        << "1. Gestion de Pacientes\n"
        << "2. Gestion de Doctores\n"
        << "3. Gestion de Citas\n"
        << "4. Salir\n"
        << "Opcion: ";
}

// Función principal (Sesión 1 y 2)
int main() {
    cargarDatos();

    bool ejecutar = true;
    while (ejecutar) {
        mostrarMenu();

        int opcion;
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
            guardarDatos();
            ejecutar = false;
            break;
        default:
            std::cout << "Opcion invalida\n";
        }
    }

    return 0;
}