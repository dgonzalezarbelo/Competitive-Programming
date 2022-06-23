#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void resuelveCaso() {
	vector <int> palos(4);
	char num, palo;
	int suma = 0;
	for (int i = 0; i < 13; i++) {
		cin >> num;
		if (num == 'A') suma += 4;
		else if (num == 'K') suma += 3;
		else if (num == 'Q') suma += 2;
		else if (num == 'J') suma += 1;
		cin >> palo;
		if (palo == '0') cin >> palo;
		if (palo == 'C') palos[0]++;
		else if (palo == 'D') palos[1]++;
		else if (palo == 'T') palos[2]++;
		else palos[3]++;
	}
	for (int i = 0; i < 4; i++) {
		if (palos[i] == 0) suma += 3;
		else if (palos[i] == 1) suma += 2;
		else if (palos[i] == 2) suma += 1;
	}
	cout << suma << '\n';
}

int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) resuelveCaso();
	return 0;
}