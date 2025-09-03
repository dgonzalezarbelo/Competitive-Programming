#include <iostream>
#include <fstream>
#include <vector>

void resuelveCaso(std::vector <char> & v, int k, int & numC, int & numV, bool & primera) {
	if (numC > 0) {
		numC--;
		v[k] = 'C';
		if (k == v.size() - 1) {
			if (primera) primera = false;
			else std::cout << ' ';
			for (int i = 0; i < v.size(); i++) std::cout << v[i];
		}
		else resuelveCaso(v, k + 1, numC, numV, primera);
		numC++;
	}
	if (numV > 0) {
		numV--;
		v[k] = 'V';
		if (k == v.size() - 1) {
			if (primera) primera = false;
			else std::cout << ' ';
			for (int i = 0; i < v.size(); i++) std::cout << v[i];
		}
		else resuelveCaso(v, k + 1, numC, numV, primera);
		numV++;
	}
}

void resolver() {
	int numC, numV;
	std::cin >> numC >> numV;
	std::vector <char> v(numC + numV);
	bool primera = true;
	resuelveCaso(v, 0, numC, numV, primera);
	std::cout << '\n';
}

int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; i++) resolver();
	return 0;
}