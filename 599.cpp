#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

struct tComparador {
	bool operator()(std::pair<int, int> p1, std::pair<int, int> p2) {
		return (float)p1.second / p1.first > (float)p2.second / p2.first;
	}
};

void solucionInicial() {

}

void resolver() {

}

bool resuelveCaso() {
	int numCanciones;
	std::cin >> numCanciones;
	if (numCanciones == 0) return false;
	int duracion;
	std::cin >> duracion;
	std::vector <std::pair<int, int>> v(numCanciones);
	for (int i = 0; i < numCanciones; i++) {
		std::cin >> v[i].first;	//Duracion
		std::cin >> v[i].second;	
	}
	std::sort(v.begin(), v.end(), tComparador());
	int caraA = 0, caraB = 0, puntAcual = 0, puntMejor = 0;
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}