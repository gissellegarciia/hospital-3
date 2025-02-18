
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

bool validarCadenaNoVacia(const std::string& cadena, const std::string& mensaje) {
    if (cadena.empty()) {
        std::cout << "Error: " << mensaje << " no puede estar vacio.\n";
        return false;
    }
    return true;
}

bool validarSoloLetras(const std::string& cadena, const std::string& mensaje) {
    for (char c : cadena) {
        if (!std::isalpha(c) && !std::isspace(c)) {
            std::cout << "Error: " << mensaje << " debe contener solo letras.\n";
            return false;
        }
    }
    return true;
}

bool validarSoloDigitos(const std::string& cadena, const std::string& mensaje) {
    for (char c : cadena) {
        if (!std::isdigit(c)) {
            std::cout << "Error: " << mensaje << " debe contener solo digitos.\n";
            return false;
        }
    }
    return !cadena.empty();
}

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
        std::cout << "4. Eliminar paciente\n";
        std::cout << "5. Volver\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcionPaciente;
        limpiarBuffer();

        switch (opcionPaciente) {
        case 1: {
            std::string nombre, id, fecha;
            bool datosValidos = false;

            while (!datosValidos) {
                while (true) {
                    std::cout << "Nombre: ";
                    std::getline(std::cin, nombre);
                    if (validarCadenaNoVacia(nombre, "Nombre") &&
                        validarSoloLetras(nombre, "Nombre")) {
                        break;
                    }
                }

                while (true) {
                    std::cout << "ID (solo digitos): ";
                    std::getline(std::cin, id);
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
                        std::cout << "Error: El ID ya existe.\n";
                    }
                }

                while (true) {
                    std::cout << "Fecha de ingreso (YYYY-MM-DD): ";
                    std::getline(std::cin, fecha);
                    if (validarFormatoFecha(fecha)) {
                        break;
                    }
                }

                std::cout << "\nConfirmar datos:\n";
                std::cout << "Nombre: " << nombre << "\n";
                std::cout << "ID: " << id << "\n";
                std::cout << "Fecha de ingreso: " << fecha << "\n";

                std::string confirmacion;
                std::cout << "Son correctos estos datos? (s/n): ";
                std::getline(std::cin, confirmacion);

                if (confirmacion == "s" || confirmacion == "S") {
                    Paciente nuevoPaciente(nombre, id, fecha);
                    pacientes.push_back(nuevoPaciente);
                    std::cout << "Paciente registrado con exito\n";
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
        case 4: {
            if (pacientes.empty()) {
                std::cout << "No hay pacientes registrados\n";
                break;
            }

            std::string idEliminar;
            std::cout << "Ingrese ID del paciente a eliminar: ";
            std::getline(std::cin, idEliminar);

            for (int i = 0; i < pacientes.size(); i++) {
                if (pacientes[i].getId() == idEliminar) {
                    std::cout << "Paciente encontrado:\n";
                    std::cout << "Nombre: " << pacientes[i].getNombre() << "\n";
                    std::cout << "ID: " << pacientes[i].getId() << "\n";

                    std::string confirmacion;
                    std::cout << "Esta seguro de eliminar este paciente? (s/n): ";
                    std::getline(std::cin, confirmacion);

                    if (confirmacion == "s" || confirmacion == "S") {
                        pacientes.erase(pacientes.begin() + i);
                        std::cout << "Paciente eliminado con exito\n";
                    }
                    else {
                        std::cout << "Operacion cancelada\n";
                    }
                    break;
                }
            }
            break;
        }
        case 5:
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
        std::cout << "4. Eliminar doctor\n";
        std::cout << "5. Volver\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcionDoctor;
        limpiarBuffer();

        switch (opcionDoctor) {
        case 1: {
            std::string nombre, id, especialidad;
            bool datosValidos = false;

            while (!datosValidos) {
                while (true) {
                    std::cout << "Nombre: ";
                    std::getline(std::cin, nombre);
                    if (validarCadenaNoVacia(nombre, "Nombre") &&
                        validarSoloLetras(nombre, "Nombre")) {
                        break;
                    }
                }

                while (true) {
                    std::cout << "ID (solo digitos): ";
                    std::getline(std::cin, id);
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
                        std::cout << "Error: El ID ya existe.\n";
                    }
                }

                while (true) {
                    std::cout << "Especialidad: ";
                    std::getline(std::cin, especialidad);
                    if (validarCadenaNoVacia(especialidad, "Especialidad") &&
                        validarSoloLetras(especialidad, "Especialidad")) {
                        break;
                    }
                }

                std::cout << "\nConfirmar datos:\n";
                std::cout << "Nombre: " << nombre << "\n";
                std::cout << "ID: " << id << "\n";
                std::cout << "Especialidad: " << especialidad << "\n";

                std::string confirmacion;
                std::cout << "Son correctos estos datos? (s/n): ";
                std::getline(std::cin, confirmacion);

                if (confirmacion == "s" || confirmacion == "S") {
                    Doctor nuevoDoctor(nombre, id, especialidad);
                    doctores.push_back(nuevoDoctor);
                    std::cout << "Doctor registrado con exito\n";
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
        case 4: {
            if (doctores.empty()) {
                std::cout << "No hay doctores registrados\n";
                break;
            }

            std::string idEliminar;
            std::cout << "Ingrese ID del doctor a eliminar: ";
            std::getline(std::cin, idEliminar);

            for (int i = 0; i < doctores.size(); i++) {
                if (doctores[i].getId() == idEliminar) {
                    std::cout << "Doctor encontrado:\n";
                    std::cout << "Nombre: " << doctores[i].getNombre() << "\n";
                    std::cout << "Especialidad: " << doctores[i].getEspecialidad() << "\n";

                    std::string confirmacion;
                    std::cout << "Esta seguro de eliminar este doctor? (s/n): ";
                    std::getline(std::cin, confirmacion);

                    if (confirmacion == "s" || confirmacion == "S") {
                        doctores.erase(doctores.begin() + i);
                        std::cout << "Doctor eliminado con exito\n";
                    }
                    else {
                        std::cout << "Operacion cancelada\n";
                    }
                    break;
                }
            }
            break;
        }
        case 5:
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
        std::cout << "4. Eliminar cita\n";
        std::cout << "5. Volver\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcionCita;
        limpiarBuffer();

        switch (opcionCita) {
        case 1: {
            std::string fecha, hora, idPaciente, idDoctor;

            while (true) {
                std::cout << "Fecha (YYYY-MM-DD): ";
                std::getline(std::cin, fecha);
                if (validarFormatoFecha(fecha)) {
                    break;
                }
            }

            while (true) {
                std::cout << "Hora (HH:MM): ";
                std::getline(std::cin, hora);
                std::regex horaRegex("^([01]\\d|2[0-3]):([0-5]\\d)$");
                if (std::regex_match(hora, horaRegex)) {
                    break;
                }
                std::cout << "Error: La hora debe tener el formato HH:MM (00:00 - 23:59).\n";
            }

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
                    std::cout << "Error: Paciente no encontrado.\n";
                }
            }

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
                    std::cout << "Error: Doctor no encontrado.\n";
                }
            }

            std::cout << "\nConfirmar datos de la cita:\n";
            std::cout << "Fecha: " << fecha << "\n";
            std::cout << "Hora: " << hora << "\n";
            std::cout << "ID Paciente: " << idPaciente << "\n";
            std::cout << "ID Doctor: " << idDoctor << "\n";

            std::string confirmacion;
            std::cout << "Son correctos estos datos? (s/n): ";
            std::getline(std::cin, confirmacion);

            if (confirmacion == "s" || confirmacion == "S") {
                Cita nuevaCita(fecha, hora, idPaciente, idDoctor);
                citas.push_back(nuevaCita);
                std::cout << "Cita programada con exito\n";
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
        case 4: {
            if (citas.empty()) {
                std::cout << "No hay citas registradas\n";
                break;
            }

            std::string idPaciente, fecha;
            std::cout << "Ingrese ID del paciente: ";
            std::getline(std::cin, idPaciente);
            std::cout << "Ingrese fecha de la cita (YYYY-MM-DD): ";
            std::getline(std::cin, fecha);

            for (int i = 0; i < citas.size(); i++) {
                if (citas[i].getIdPaciente() == idPaciente && citas[i].getFecha() == fecha) {
                    std::cout << "Cita encontrada:\n";
                    std::cout << "Fecha: " << citas[i].getFecha() << "\n";
                    std::cout << "Hora: " << citas[i].getHora() << "\n";
                    std::cout << "Doctor ID: " << citas[i].getIdDoctor() << "\n";

                    std::string confirmacion;
                    std::cout << "Esta seguro de eliminar esta cita? (s/n): ";
                    std::getline(std::cin, confirmacion);

                    if (confirmacion == "s" || confirmacion == "S") {
                        citas.erase(citas.begin() + i);
                        std::cout << "Cita eliminada con exito\n";
                    }
                    else {
                        std::cout << "Operacion cancelada\n";
                    }
                    break;
                }
            }
            break;
        }
        case 5:
            volverMenu = true;
            break;
        default:
            std::cout << "Opcion no valida\n";
        }
    }
}

void mostrarMenu() {
    std::cout << "\n=== Hospital MSMK ===\n";
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