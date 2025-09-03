#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
#pragma warning (disable:4996)

void resolver(int num) {
	string sonido;
	bool derecha = true;
	int pIz = 0, pDer = 0;
	for (int i = 0; i < num; i++) {
		cin >> sonido;
		if (sonido == "PIC") derecha = !derecha;
		else if (sonido == "POC") {

		}
		else {
			if (derecha) pIz++;
			else pDer++;
		}
	}
	cout << pIz << ' ' << pDer << '\n';
}

bool resuelveCaso() {
	int num;
	cin >> num;
	if (num == 0) return false;
	resolver(num);
	return true;
}

int main() {
	while (resuelveCaso());


	return 0;
}