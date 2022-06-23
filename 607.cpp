#include <iostream>
#include <fstream>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
vector <int> potencias;

int resolver(int num) {
	int i = 0;
	while (potencias[i] < num) i++;
	return i;
}

void resuelveCaso() {
	int num;
	scanf("%d", &num);
	printf("%d\n", resolver(num));
}

int main() {
	int numCasos;
	scanf("%d", &numCasos);
	potencias.push_back(1);
	int pot = 1;
	while (pot < 1000000000) {
		pot *= 2;
		potencias.push_back(pot);
	}
	for (int i = 0; i < numCasos; i++) resuelveCaso();
	return 0;
}