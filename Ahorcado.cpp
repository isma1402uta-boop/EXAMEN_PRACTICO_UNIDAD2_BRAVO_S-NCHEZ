#include "Ahorcado.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Constructor: Inicializa el vocabulario técnico del Grupo K
Ahorcado::Ahorcado() {
    palabrasNivel1 = {"MISION", "RANGO", "VIDAS", "PUNTOS"};
    palabrasNivel2 = {"BONIFICACION", "PENALIZACION", "RECURSIVIDAD", "RANKING"};
    intentosMaximos = 6;
}

// Función auxiliar: Valida que la entrada sea estrictamente una letra
bool Ahorcado::esLetraValida(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

void Ahorcado::mostrarMenu() {
    int opcion;
    do {
        cout << "\n================================" << endl;
        cout << "   MODULO OBLIGATORIO: AHORCADO   " << endl;
        cout << "================================" << endl;
        cout << "1. Jugar Nivel Inicial (Misiones)" << endl;
        cout << "2. Jugar Nivel Avanzado (Sistemas)" << endl;
        cout << "3. Ver Instrucciones" << endl;
        cout << "4. Volver al Menu Principal" << endl;
        cout << "Seleccione una opcion: ";
        
        if (!(cin >> opcion)) {
            cin.clear();
            while (cin.get() != '\n');
            continue;
        }

        switch (opcion) {
            case 1: iniciarJuego(palabrasNivel1); break;
            case 2: iniciarJuego(palabrasNivel2); break;
            case 3: 
                cout << "\nInstrucciones: Adivina la palabra tecnica antes de agotar tus intentos." << endl;
                cout << "Solo se permiten letras de la A a la Z." << endl;
                break;
        }
    } while (opcion != 4);
}

void Ahorcado::iniciarJuego(vector<string> listaPalabras) {
    // Selección de la primera palabra del vector
    string palabraSecreta = listaPalabras[0]; 
    string palabraOculta(palabraSecreta.length(), '_');
    int intentosRestantes = intentosMaximos;
    vector<char> letrasUsadas;
    char letra;

    while (intentosRestantes > 0 && palabraOculta != palabraSecreta) {
        cout << "\n--------------------------------" << endl;
        cout << "Palabra: " << palabraOculta << endl;
        cout << "Intentos restantes: " << intentosRestantes << endl;
        cout << "Letras usadas: ";
        for (char l : letrasUsadas) cout << l << " ";
        
        cout << "\nIngrese una letra: ";
        cin >> letra;

        // 1. VALIDACIÓN DE CARÁCTER (Fase 4: Robustez)
        if (!esLetraValida(letra)) {
            cout << ">> Error: Solo se permiten letras (A-Z). <<" << endl;
            continue; 
        }

        // 2. NORMALIZACIÓN
        letra = toupper(letra);

        // 3. VALIDACIÓN DE REPETICIÓN
        bool yaUsada = false;
        for (char l : letrasUsadas) {
            if (l == letra) yaUsada = true;
        }
        if (yaUsada) {
            cout << ">> Ya intentaste con la letra '" << letra << "'. <<" << endl;
            continue;
        }
        
        letrasUsadas.push_back(letra);

        // 4. LÓGICA DE VERIFICACIÓN
        bool acierto = false;
        for (int i = 0; i < (int)palabraSecreta.length(); i++) {
            if (palabraSecreta[i] == letra) {
                palabraOculta[i] = letra;
                acierto = true;
            }
        }

        if (!acierto) {
            intentosRestantes--;
            cout << ">> Letra incorrecta. <<" << endl;
        } else {
            cout << ">> ¡Buen acierto! <<" << endl;
        }
    }

    if (palabraOculta == palabraSecreta) {
        cout << "\n¡FELICIDADES! Ganaste la ronda. Palabra: " << palabraSecreta << endl;
    } else {
        cout << "\nGAME OVER. La palabra era: " << palabraSecreta << endl;
    }
}