
// Nombre y Apellidos: Daniel Gonzalez Arbelo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#pragma warning(disable:4996)
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
bool resolver(int num, int ini, int fin, std::vector <int> const& preguntas, int index) {
    if (index == preguntas.size()) return ini == fin;
    else {
        if (num >= preguntas[index]) {
            if (ini > preguntas[index]) return resolver(num, ini, fin, preguntas, index + 1);
            else return resolver(num, preguntas[index], fin, preguntas, index + 1);
        }
        
        else {
            if (fin < preguntas[index]) return resolver(num, ini, fin, preguntas, index + 1);
            else return resolver(num, ini, preguntas[index] - 1, preguntas, index + 1);
        } 
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int ini, fin, num;
    scanf("%d %d %d", &ini, &fin, &num);
    if (ini == 0 && fin == 0 && num == 0)
        return false;
    int tam;
    std::cin >> tam;
    std::vector <int> preguntas(tam);
    for (int i = 0; i < tam; i++) std::cin >> preguntas[i];
    resolver(num, ini, fin, preguntas, 0) ? printf("LO SABE\n") : printf("NO LO SABE\n");

    // escribir sol

    return true;
}

int main() {

    while (resuelveCaso());


    return 0;
}
