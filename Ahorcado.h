#ifndef AHORCADO_H
#define AHORCADO_H

#include <string>
#include <vector>

class Ahorcado {
private:
    std::vector<std::string> palabrasNivel1; // Vocabulario: misiones, rangos
    std::vector<std::string> palabrasNivel2; // Vocabulario: penalizaciones, sistemas
    int intentosMaximos;
    bool esLetraValida(char c); // Fase 4: Robustez

public:
    Ahorcado();
    void mostrarMenu(); 
    void iniciarJuego(std::vector<std::string> listaPalabras);
};

#endif