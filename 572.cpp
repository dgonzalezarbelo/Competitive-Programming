#include <iostream>
#include <vector>
using namespace std;


void resuelveCaso() {
	vector <int> v(5);
	double num;
	bool cero = false, nueve = false;
	for (int i = 0; i < 5; i++) {
		cin >> num;
		if (num == 0) cero = true;
		else if (num >= 9) nueve = true;
	}
	if (cero && !nueve) cout << "SUSPENSO DIRECTO\n";
	else cout << "MEDIA\n";
}

int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) resuelveCaso();
	return 0;
}