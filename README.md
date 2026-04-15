# EXAMEN_PRACTICO_UNIDAD2_BRAVO_SÁNCHEZ
# 🎮 SISTEMA DE GESTIÓN: GRUPO K - UTA
> **Proyecto Final - Unidad 2** > Desarrollo de un Sistema de Gestión de Jugadores y Módulo Académico de Ahorcado.

---

## 📋 Descripción del Proyecto
Este sistema ha sido desarrollado como parte del examen práctico de programación. Implementa una arquitectura modular en **C++** para gestionar un ranking de jugadores, calcular bonificaciones mediante recursividad y ofrecer un entorno de aprendizaje técnico a través de un juego de ahorcado.

## 🚀 Características Principales
- **Arquitectura Multifichero:** Separación clara entre interfaces (`.h`) e implementaciones (`.cpp`).
- **Ranking Dinámico:** Gestión de puntajes utilizando `std::vector` y objetos de la clase `Jugador`.
- **Algoritmo de Ordenamiento:** Implementación manual de **Bubble Sort** para organizar el Top 3 de mejores puntajes.
- **Módulo Académico:** Juego de ahorcado con vocabulario técnico orientado a ingeniería.
- **Robustez:** Validación de entradas para evitar errores de ejecución y bucles infinitos.

---

## 🛠️ Estructura del Código
El proyecto se divide en los siguientes módulos:

| Archivo | Función |
| :--- | :--- |
| `main.cpp` | Punto de entrada, menú principal y algoritmo de ordenamiento. |
| `Jugador.h/.cpp` | Gestión de datos del usuario y lógica de bonificación recursiva. |
| `Partida.h/.cpp` | Clase encargada de almacenar los resultados de cada sesión. |
| `Ahorcado.h/.cpp` | Motor del juego con niveles de dificultad y validación de caracteres. |

---

## 💻 Instrucciones de Compilación
Para compilar y ejecutar el proyecto en Windows (PowerShell), utiliza los siguientes comandos:

1. **Compilar todos los módulos:**
   ```powershell
   g++ main.cpp Jugador.cpp Partida.cpp Ahorcado.cpp -o sistema_uta.exe
