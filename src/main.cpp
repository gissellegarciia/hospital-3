#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Paciente.hpp"
#include "Doctor.hpp"
#include "Cita.hpp"

std::vector<Paciente> pacientes;
std::vector<Doctor> doctores;
std::vector<Cita> citas;

void limpiarBuffer() {
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}

bool validarCadenaNoVacia(const std::string& cadena) {
    if (cadena.length() == 0) {
        std::cout << "Error: El campo no puede estar vacio.\n";
        return false;
    }
    return true;
}

bool validarSoloLetras(const std::string& cadena) {
    for (int i = 0; i < cadena.length(); i++) {
        if (!((cadena[i] >= 'a' && cadena[i] <= 'z') ||
            (cadena[i] >= 'A' && cadena[i] <= 'Z') ||
            cadena[i] == ' ')) {
            std::cout << "Error: Solo se permiten letras.\n";
            return false;
        }
    }
    return true;
}

bool validarSoloNumeros(const std::string& cadena) {
    for (int i = 0; i < cadena.length(); i++) {
        if (!(cadena[i] >= '0' && cadena[i] <= '9')) {
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
}void guardarDatos() {
    std::ofstream archivoPacientes("pacientes.txt");
    for (int i = 0; i < pacientes.size(); i++) {
        archivoPacientes << pacientes[i].getNombre() << "\n";
        archivoPacientes << pacientes[i].getId() << "\n";
        archivoPacientes << pacientes[i].getFechaIngreso() << "\n";
    }
    archivoPacientes.close();

    std::ofstream archivoDoctores("doctores.txt");
    for (int i = 0; i < doctores.size(); i++) {
        archivoDoctores << doctores[i].getNombre() << "\n";
        archivoDoctores << doctores[i].getId() << "\n";
        archivoDoctores << doctores[i].getEspecialidad() << "\n";
    }
    archivoDoctores.close();

    std::ofstream archivoCitas("citas.txt");
    for (int i = 0; i < citas.size(); i++) {
        archivoCitas << citas[i].getFecha() << "\n";
        archivoCitas << citas[i].getHora() << "\n";
        archivoCitas << citas[i].getIdPaciente() << "\n";
        archivoCitas << citas[i].getIdDoctor() << "\n";
    }
    archivoCitas.close();
}

void cargarDatos() {
    std::ifstream archivoPacientes("pacientes.txt");
    std::string nombre, id, fecha;
    while (getline(archivoPacientes, nombre)) {
        getline(archivoPacientes, id);
        getline(archivoPacientes, fecha);
        Paciente nuevoPaciente(nombre, id, fecha);
        pacientes.push_back(nuevoPaciente);
    }
    archivoPacientes.close();

    std::ifstream archivoDoctores("doctores.txt");
    while (getline(archivoDoctores, nombre)) {
        getline(archivoDoctores, id);
        std::string especialidad;
        getline(archivoDoctores, especialidad);
        Doctor nuevoDoctor(nombre, id, especialidad);
        doctores.push_back(nuevoDoctor);
    }
    archivoDoctores.close();

    std::ifstream archivoCitas("citas.txt");
    while (getline(archivoCitas, fecha)) {
        std::string hora, idPaciente, idDoctor;
        getline(archivoCitas, hora);
        getline(archivoCitas, idPaciente);
        getline(archivoCitas, idDoctor);
        Cita nuevaCita(fecha, hora, idPaciente, idDoctor);
        citas.push_back(nuevaCita);
    }
    archivoCitas.close();
}void gestionPacientes() {
    int opcion;
    bool volver = false;

    while (!volver) {
        std::cout << "\nGestion de Pacientes\n";
        std::cout << "Pacientes registrados: " << pacientes.size() << "\n";
        std::cout << "1. Registrar paciente\n";
        std::cout << "2. Buscar paciente\n";
        std::cout << "3. Listar pacientes\n";
        std::cout << "4. Eliminar paciente\n";
        std::cout << "5. Volver\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;
        limpiarBuffer();

        switch (opcion) {
        case 1: {
            std::string nombre, id, fecha;
            bool datosValidos = false;

            while (!datosValidos) {
                while (true) {
                    std::cout << "Nombre: ";
                    getline(std::cin, nombre);
                    if (validarCadenaNoVacia(nombre) && validarSoloLetras(nombre)) {
                        break;
                    }
                }

                while (true) {
                    std::cout << "ID: ";
                    getline(std::cin, id);

                    bool idExiste = false;
                    for (int i = 0; i < pacientes.size(); i++) {
                        if (pacientes[i].getId() == id) {
                            idExiste = true;
                            break;
                        }
                    }

                    if (validarSoloNumeros(id) && !idExiste) {
                        break;
                    }

                    if (idExiste) {
                        std::cout << "Error: El ID ya existe\n";
                    }
                }

                while (true) {
                    std::cout << "Fecha de ingreso (YYYY-MM-DD): ";
                    getline(std::cin, fecha);
                    if (validarFormatoFecha(fecha)) {
                        break;
                    }
                }

                std::cout << "\nDatos ingresados:\n";
                std::cout << "Nombre: " << nombre << "\n";
                std::cout << "ID: " << id << "\n";
                std::cout << "Fecha: " << fecha << "\n";

                std::string confirmar;
                std::cout << "Son correctos? (s/n): ";
                getline(std::cin, confirmar);

                if (confirmar == "s" || confirmar == "S") {
                    Paciente nuevoPaciente(nombre, id, fecha);
                    pacientes.push_back(nuevoPaciente);
                    std::cout << "Paciente registrado\n";
                    datosValidos = true;
                }
            }
            break;
        }
        case 2: {
            std::string idBuscar;
            std::cout << "ID del paciente a buscar: ";
            getline(std::cin, idBuscar);

            bool encontrado = false;
            for (int i = 0; i < pacientes.size(); i++) {
                if (pacientes[i].getId() == idBuscar) {
                    std::cout << "Paciente encontrado:\n";
                    std::cout << "Nombre: " << pacientes[i].getNombre() << "\n";
                    std::cout << "Fecha de ingreso: " << pacientes[i].getFechaIngreso() << "\n";
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                std::cout << "Paciente no encontrado\n";
            }
            break;
        }
        case 3: {
            if (pacientes.size() == 0) {
                std::cout << "No hay pacientes registrados\n";
            }
            else {
                std::cout << "Lista de pacientes:\n";
                for (int i = 0; i < pacientes.size(); i++) {
                    std::cout << "ID: " << pacientes[i].getId()
                        << " - Nombre: " << pacientes[i].getNombre() << "\n";
                }
            }
            break;
        }
        case 4: {
            std::string idEliminar;
            std::cout << "ID del paciente a eliminar: ";
            getline(std::cin, idEliminar);

            bool encontrado = false;
            for (int i = 0; i < pacientes.size(); i++) {
                if (pacientes[i].getId() == idEliminar) {
                    bool tieneCitas = false;
                    for (const Cita& cita : citas) {
                        if (cita.getIdPaciente() == idEliminar) {
                            tieneCitas = true;
                            break;
                        }
                    }

                    if (tieneCitas) {
                        std::cout << "No se puede eliminar el paciente porque tiene citas programadas\n";
                    }
                    else {
                        std::cout << "Estas segura de eliminar al paciente " << pacientes[i].getNombre() << "? (s/n): ";
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
        case 5:
            volver = true;
            break;
        default:
            std::cout << "Opcion no valida\n";
        }
    }
}

void gestionDoctores() {
    int opcion;
    bool volver = false;

    while (!volver) {
        std::cout << "\nGestion de Doctores\n";
        std::cout << "Doctores registrados: " << doctores.size() << "\n";
        std::cout << "1. Registrar doctor\n";
        std::cout << "2. Buscar doctor\n";
        std::cout << "3. Listar doctores\n";
        std::cout << "4. Eliminar doctor\n";
        std::cout << "5. Volver\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;
        limpiarBuffer();

        switch (opcion) {
        case 1: {
            std::string nombre, id, especialidad;
            bool datosValidos = false;

            while (!datosValidos) {
                while (true) {
                    std::cout << "Nombre: ";
                    getline(std::cin, nombre);
                    if (validarCadenaNoVacia(nombre) && validarSoloLetras(nombre)) {
                        break;
                    }
                }

                while (true) {
                    std::cout << "ID: ";
                    getline(std::cin, id);

                    bool idExiste = false;
                    for (int i = 0; i < doctores.size(); i++) {
                        if (doctores[i].getId() == id) {
                            idExiste = true;
                            break;
                        }
                    }

                    if (validarSoloNumeros(id) && !idExiste) {
                        break;
                    }

                    if (idExiste) {
                        std::cout << "Error: El ID ya existe\n";
                    }
                }

                while (true) {
                    std::cout << "Especialidad: ";
                    getline(std::cin, especialidad);
                    if (validarCadenaNoVacia(especialidad) && validarSoloLetras(especialidad)) {
                        break;
                    }
                }

                std::cout << "\nDatos ingresados:\n";
                std::cout << "Nombre: " << nombre << "\n";
                std::cout << "ID: " << id << "\n";
                std::cout << "Especialidad: " << especialidad << "\n";

                std::string confirmar;
                std::cout << "Son correctos? (s/n): ";
                getline(std::cin, confirmar);

                if (confirmar == "s" || confirmar == "S") {
                    Doctor nuevoDoctor(nombre, id, especialidad);
                    doctores.push_back(nuevoDoctor);
                    std::cout << "Doctor registrado\n";
                    datosValidos = true;
                }
            }
            break;
        }
        case 2: {
            std::string idBuscar;
            std::cout << "ID del doctor a buscar: ";
            getline(std::cin, idBuscar);

            bool encontrado = false;
            for (int i = 0; i < doctores.size(); i++) {
                if (doctores[i].getId() == idBuscar) {
                    std::cout << "Doctor encontrado:\n";
                    std::cout << "Nombre: " << doctores[i].getNombre() << "\n";
                    std::cout << "Especialidad: " << doctores[i].getEspecialidad() << "\n";
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                std::cout << "Doctor no encontrado\n";
            }
            break;
        }
        case 3: {
            if (doctores.size() == 0) {
                std::cout << "No hay doctores registrados\n";
            }
            else {
                std::cout << "Lista de doctores:\n";
                for (int i = 0; i < doctores.size(); i++) {
                    std::cout << "ID: " << doctores[i].getId()
                        << " - Nombre: " << doctores[i].getNombre()
                        << " - Especialidad: " << doctores[i].getEspecialidad() << "\n";
                }
            }
            break;
        }
        case 4: {
            std::string idEliminar;
            std::cout << "ID del doctor a eliminar: ";
            getline(std::cin, idEliminar);

            bool encontrado = false;
            for (int i = 0; i < doctores.size(); i++) {
                if (doctores[i].getId() == idEliminar) {
                    bool tieneCitas = false;
                    for (const Cita& cita : citas) {
                        if (cita.getIdDoctor() == idEliminar) {
                            tieneCitas = true;
                            break;
                        }
                    }

                    if (tieneCitas) {
                        std::cout << "No se puede eliminar el doctor porque tiene citas programadas\n";
                    }
                    else {
                        std::cout << "Estas segura de eliminar al doctor " << doctores[i].getNombre() << "? (s/n): ";
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
        case 5:
            volver = true;
            break;
        default:
            std::cout << "Opcion no valida\n";
        }
    }
}

void gestionCitas() {
    int opcion;
    bool volver = false;

    while (!volver) {
        std::cout << "\nGestion de Citas\n";
        std::cout << "Citas registradas: " << citas.size() << "\n";
        std::cout << "1. Programar cita\n";
        std::cout << "2. Buscar cita\n";
        std::cout << "3. Listar citas\n";
        std::cout << "4. Eliminar cita\n";
        std::cout << "5. Volver\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;
        limpiarBuffer();

        switch (opcion) {
        case 1: {
            std::string fecha, hora, idPaciente, idDoctor;

            while (true) {
                std::cout << "Fecha (YYYY-MM-DD): ";
                getline(std::cin, fecha);
                if (validarFormatoFecha(fecha)) {
                    break;
                }
            }

            while (true) {
                std::cout << "Hora (HH:MM): ";
                getline(std::cin, hora);
                if (validarFormatoHora(hora)) {
                    break;
                }
            }

            while (true) {
                std::cout << "ID del paciente: ";
                getline(std::cin, idPaciente);

                bool pacienteExiste = false;
                for (int i = 0; i < pacientes.size(); i++) {
                    if (pacientes[i].getId() == idPaciente) {
                        pacienteExiste = true;
                        break;
                    }
                }

                if (validarSoloNumeros(idPaciente) && pacienteExiste) {
                    break;
                }

                if (!pacienteExiste) {
                    std::cout << "Error: Paciente no encontrado\n";
                }
            }

            while (true) {
                std::cout << "ID del doctor: ";
                getline(std::cin, idDoctor);

                bool doctorExiste = false;
                for (int i = 0; i < doctores.size(); i++) {
                    if (doctores[i].getId() == idDoctor) {
                        doctorExiste = true;
                        break;
                    }
                }

                if (validarSoloNumeros(idDoctor) && doctorExiste) {
                    break;
                }

                if (!doctorExiste) {
                    std::cout << "Error: Doctor no encontrado\n";
                }
            }

            std::cout << "\nDatos de la cita:\n";
            std::cout << "Fecha: " << fecha << "\n";
            std::cout << "Hora: " << hora << "\n";
            std::cout << "ID Paciente: " << idPaciente << "\n";
            std::cout << "ID Doctor: " << idDoctor << "\n";

            std::string confirmar;
            std::cout << "Son correctos? (s/n): ";
            getline(std::cin, confirmar);

            if (confirmar == "s" || confirmar == "S") {
                Cita nuevaCita(fecha, hora, idPaciente, idDoctor);
                citas.push_back(nuevaCita);
                std::cout << "Cita programada\n";
            }
            break;
        }
        case 2: {
            std::string idBuscar;
            std::cout << "ID del paciente: ";
            getline(std::cin, idBuscar);

            bool encontrado = false;
            for (int i = 0; i < citas.size(); i++) {
                if (citas[i].getIdPaciente() == idBuscar) {
                    std::cout << "Cita encontrada:\n";
                    std::cout << "Fecha: " << citas[i].getFecha() << "\n";
                    std::cout << "Hora: " << citas[i].getHora() << "\n";
                    std::cout << "ID Doctor: " << citas[i].getIdDoctor() << "\n";
                    encontrado = true;
                }
            }
            if (!encontrado) {
                std::cout << "No se encontraron citas\n";
            }
            break;
        }
        case 3: {
            if (citas.size() == 0) {
                std::cout << "No hay citas programadas\n";
            }
            else {
                std::cout << "Lista de citas:\n";
                for (int i = 0; i < citas.size(); i++) {
                    std::cout << "Fecha: " << citas[i].getFecha()
                        << " - Hora: " << citas[i].getHora()
                        << " - Paciente ID: " << citas[i].getIdPaciente()
                        << " - Doctor ID: " << citas[i].getIdDoctor() << "\n";
                }
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
            for (int i = 0; i < citas.size(); i++) {
                if (citas[i].getIdPaciente() == idPaciente &&
                    citas[i].getFecha() == fecha &&
                    citas[i].getHora() == hora) {

                    std::cout << "Estas segura de eliminar la cita? (s/n): ";
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
        case 5:
            volver = true;
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

    std::cout << "Iniciando sistema...\n";
    cargarDatos();

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
            std::cout << "Guardando datos...\n";
            guardarDatos();
            ejecutar = false;
            std::cout << "Gracias por usar el sistema\n";
            break;
        default:
            std::cout << "Opcion no valida\n";
        }
    }

    return 0;
}
