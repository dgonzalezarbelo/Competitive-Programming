#include <iostream>
#include <fstream>
#include <vector>

bool resolver(std::vector <int> const& numeros, int k, int resultado, int & acumulado) {
	if (k < 4) {
		acumulado += numeros[k];
		if (resolver(numeros, k + 1, resultado, acumulado)) return true;
		acumulado -= numeros[k];
		acumulado -= numeros[k];
		if (resolver(numeros, k + 1, resultado, acumulado)) return true;
		acumulado += numeros[k];
		if (numeros[k] != 0) {
			acumulado *= numeros[k];
			if (resolver(numeros, k + 1, resultado, acumulado)) return true;
			acumulado /= numeros[k];
			if (acumulado % numeros[k] == 0) {
				acumulado /= numeros[k];
				if (resolver(numeros, k + 1, resultado, acumulado)) return true;
				acumulado *= numeros[k];
			}
			return false;
		}
		else {
			int anterior = acumulado;
			acumulado = 0;
			if (resolver(numeros, k + 1, resultado, acumulado)) {
				acumulado = anterior;
				return true;
			} 
			else {
				acumulado = anterior;
				return false;
			}
		}
	}
	else {
		acumulado += numeros[k];
		if (acumulado == resultado) return true;
		acumulado -= numeros[k];
		acumulado -= numeros[k];
		if (acumulado == resultado) return true;
		acumulado += numeros[k];
		if (numeros[k] != 0) {
			acumulado *= numeros[k];
			if (acumulado == resultado) return true;
			acumulado /= numeros[k];
			if (acumulado % numeros[k] == 0) {
				acumulado /= numeros[k];
				if (acumulado == resultado) return true;
				acumulado *= numeros[k];
			}
			return false;
		}
		else {
			int anterior = acumulado;
			acumulado = 0;
			if (acumulado == resultado) {
				acumulado = anterior;
				return true;
			}
			else {
				acumulado = anterior;
				return false;
			}
		}
	}
}

bool resuelveCaso() {
	int resultado;
	std::cin >> resultado;
	if (!std::cin) return false;
	std::vector <int> numeros(5);
	for (int i = 0; i < 5; i++) std::cin >> numeros[i];
	int acumulado = numeros[0];
	if (resolver(numeros, 1, resultado, acumulado)) std::cout << "SI\n";
	else std::cout << "NO\n";
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}