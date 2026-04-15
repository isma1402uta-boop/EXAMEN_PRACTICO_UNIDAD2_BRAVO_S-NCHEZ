#include "Jugador.h"

Jugador::Jugador(std::string _alias) : alias(_alias), rango(0), puntajeFinal(0) {}

int Jugador::calcularBonificacionRecursiva(int t) {
    if (t <= 0) return 0;
    return 5 + calcularBonificacionRecursiva(t - 10); // Utilidad real: bonos por tiempo
}

void Jugador::procesarResultado(Partida p) {
    int base = p.getPuntajeBase();
    int penalizacion = p.getErrores() * 15; // Penalización por errores [cite: 207]
    int bonificacion = calcularBonificacionRecursiva(120 - p.getTiempo());
    
    puntajeFinal = base + bonificacion - penalizacion;
    if(puntajeFinal < 0) puntajeFinal = 0;

    // --- FRAGMENTO CORREGIDO --- [cite: 213, 214]
    if(puntajeFinal >= 900) rango = 5;
    else if(puntajeFinal >= 700) rango = 4;
    else if(puntajeFinal >= 500) rango = 3;
    else if(puntajeFinal >= 300) rango = 2;
    else rango = 1; 
}