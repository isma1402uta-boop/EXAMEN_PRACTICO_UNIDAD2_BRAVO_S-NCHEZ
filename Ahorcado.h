#ifndef AHORCADO_H
#define AHORCADO_H

#include <string>
#include <vector>

class Ahorcado {
private:
    std::vector<std::string> palabras;
    int intentos;

public:
    Ahorcado();
    void iniciarJuego(); // Vocabulario: misiones, rangos, penalizaciones [cite: 211]
};

#endif