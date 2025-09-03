
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>

int resolver(int num) {
    if (num < 6) return num;
    else return resolver(num / 6) * 10 + num % 6;
}
void resuelveCaso() {
    int num;
    std::cin >> num;
    std::cout << resolver(num) << '\n';
}

int main() {
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();
    return 0;
}
