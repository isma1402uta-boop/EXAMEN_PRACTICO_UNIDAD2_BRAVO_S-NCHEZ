#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include "Partida.h"

class Jugador {
private:
    std::string alias; 
    int rango;        
    int puntajeFinal;

public:
    // Constructor 
    Jugador(std::string _alias);

    // Función recursiva con utilidad real [cite: 47]
    int calcularBonificacionRecursiva(int t); 

    // Proceso de lógica del caso Grupo K [cite: 207]
    void procesarResultado(Partida p);
    
    // Getters para búsqueda y ordenamiento manual [cite: 45]
    std::string getAlias() const { return alias; }
    int getPuntaje() const { return puntajeFinal; }
    int getRango() const { return rango; }
};

#endif