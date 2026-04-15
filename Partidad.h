#ifndef PARTIDA_H
#define PARTIDA_H

class Partida {
private:
    int misiones[3]; // Puntos por misión 
    int errores;     // Cantidad de fallos presentados
    int tiempo;      // Cantidad de tiempo en segundos

public:
    Partida(); // Constructor de la clase
    void setDatos(int mision1, int mision2, int mision3, int eventos, int tiempo);
    int getPuntajeBase() const;
    int getErrores() const;
    int getTiempo() const;
};

#endif