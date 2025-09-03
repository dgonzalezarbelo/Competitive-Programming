//Pensado por Tururiru y yo :)
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

#pragma warning(disable:4996)

std::vector <int> primos;


int resolver(int num) {
	int apariciones = 1, actual = 0;
    for (int i = 0; i < primos.size(); i++)
    {
        if (primos[i] * primos[i] > num) break;
        actual = 0;
        // While i divides n, print i and divide n
        while (num % primos[i] == 0)
        {
            num = num / primos[i];
            actual++;
        }
        apariciones *= 2 * actual + 1;
    }
    if (num != 1) apariciones *= 3;
    return (apariciones + 1) / 2;
}

int resuelveCaso() {
    int num;
    if(scanf("%d", &num) == EOF) return false;
    printf("%d\n", resolver(num));
    return true;
}

int main() {
    primos.push_back(2);
    bool esPrimo;
    for (int i = 3; i < 65536; i++) {
        esPrimo = true;
        for (int j = 0; j < primos.size(); j++) {
            if (i % primos[j] == 0) {
                esPrimo = false;
                break;
            }
        }
        if (esPrimo) primos.push_back(i);
    }
    while (resuelveCaso());


	return 0;
}