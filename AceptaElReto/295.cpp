
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#pragma warning(disable:4996)
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
const int k = 31543;
int resolver(int num, int n) {
    if (n == 0) return 1;
    else {
        int mitad = resolver(num, (n - 1) / 2) % k;
        mitad = (mitad * mitad) % k;
        int x = num % k;
        if((n - 1) % 2 == 0) return (x * mitad) % k;
        else return ((x * x) % k * mitad) % k;
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int num, n;
    scanf("%d %d", &num, &n);
    if (num == 0 && n == 0) return false;

    printf("%d\n", resolver(num, n));

    // escribir sol

    return true;
}

int main() {


    while (resuelveCaso());


    return 0;
}
