#include <iostream>
#include <vector>
#include <string>
#include "Jugador.h"
#include "Ahorcado.h"

// Ordenamiento manual (Bubble Sort) - Requisito del Grupo K
void ordenarRanking(std::vector<Jugador>& lista) {
    if (lista.empty()) return;
    for(size_t i = 0; i < lista.size(); i++) {
        for(size_t j = 0; j < lista.size() - 1; j++) {
            // Orden descendente (Mayor puntaje primero)
            if(lista[j].getPuntaje() < lista[j+1].getPuntaje()) {
                std::swap(lista[j], lista[j+1]);
            }
        }
    }
}

int main() {
    std::vector<Jugador> ranking;
    int op;
    Ahorcado juego;

    do {
        std::cout << "\n--- SISTEMA DE GESTION: GRUPO K ---" << std::endl;
        std::cout << "1. Registrar Jugador y Partida" << std::endl;
        std::cout << "2. Ver Ranking (Top 3)" << std::endl;
        std::cout << "3. Modulo Ahorcado Academico" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        
        // Validacion robusta del menu
        if(!(std::cin >> op)) {
            std::cout << "Error: Ingrese un numero valido." << std::endl;
            std::cin.clear();
            while(std::cin.get() != '\n');
            continue;
        }

        if(op == 1) {
            std::string nombre;
            int m1, m2, m3, err, tiempo;
            
            std::cout << "\n--- Registro de Partida ---" << std::endl;
            std::cout << "Alias del jugador: "; std::cin >> nombre;
            
            // Simulacion de ingreso de datos segun el caso de estudio
            std::cout << "Puntos Mision 1: "; std::cin >> m1;
            std::cout << "Puntos Mision 2: "; std::cin >> m2;
            std::cout << "Puntos Mision 3: "; std::cin >> m3;
            std::cout << "Errores cometidos: "; std::cin >> err;
            std::cout << "Tiempo empleado (seg): "; std::cin >> tiempo;

            Jugador nuevo(nombre);
            Partida p;
            p.setDatos(m1, m2, m3, err, tiempo);
            nuevo.procesarResultado(p);
            
            ranking.push_back(nuevo);
            std::cout << "¡Jugador registrado con éxito!" << std::endl;

        } else if(op == 2) {
            if(ranking.empty()) {
                std::cout << "No hay jugadores registrados." << std::endl;
            } else {
                ordenarRanking(ranking);
                std::cout << "\n--- TOP 3 RANKING ---" << std::endl;
                // Mostrar maximo 3 o el tamaño del vector
                int limite = (ranking.size() < 3) ? ranking.size() : 3;
                for(int i = 0; i < limite; i++) {
                    std::cout << i+1 << ". " << ranking[i].getAlias() 
                              << " | Puntaje: " << ranking[i].getPuntaje() 
                              << " | Rango: " << ranking[i].getRango() << std::endl;
                }
            }
        } else if(op == 3) {
            // Llamamos al menu interno del Ahorcado
            juego.mostrarMenu();
        }
    } while(op != 4);

    std::cout << "Saliendo del sistema..." << std::endl;
    return 0;
}