
// Nombre y Apellidos: Daniel Gonzalez Arbelo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#pragma warning(disable:4996)

//T(n) = 2T(2n/3) + c = 2T(n/1,5) + c pertenece a O(n^log_1,5(2))

int resolver(int fuerza, int peso) {
    if (peso <= 2 * fuerza) return 0;
    else {
        int m = peso / 3;
        return 1 + resolver(fuerza, m) + resolver(fuerza, peso - m);
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int fuerza, peso;
    scanf("%d %d", &fuerza, &peso);
    if (fuerza == 0)
        return false;

    printf("%d\n", resolver(fuerza, peso));

    // escribir sol

    return true;
}

int main() {

    while (resuelveCaso());


    return 0;
}
