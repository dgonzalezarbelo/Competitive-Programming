#include <iostream>
#include <fstream>
#include <vector>

void resuelveCaso() {
	std::vector <int> arriba(6), abajo(6);
	for (int i = 0; i < 6; i++) std::cin >> arriba[i];
	for (int i = 0; i < 6; i++) std::cin >> abajo[i];
	int suma = arriba[0] + abajo[0];
	bool iguales = true;
	int i = 1;
	while (iguales && i < 6) {
		if (arriba[i] + abajo[i] != suma) iguales = false;
		i++;
	}
	if (iguales) std::cout << "SI\n";
	else std::cout << "NO\n";
}

int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; i++) resuelveCaso();
	return 0;
}