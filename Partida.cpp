#include "Partida.h"

Partida::Partida() : errores(0), tiempo(0) {
    for(int i = 0; i < 3; i++) misiones[i] = 0;
}

void Partida::setDatos(int mision1, int mision2, int mision3, int eventos, int t) {
    // Usamos los nombres de los parámetros definidos arriba
    misiones[0] = mision1; 
    misiones[1] = mision2; 
    misiones[2] = mision3;
    errores = eventos; 
    
    tiempo = t; 
}

int Partida::getPuntajeBase() const {
    return misiones[0] + misiones[1] + misiones[2];
}

int Partida::getErrores() const { return errores; }
int Partida::getTiempo() const { return tiempo; }