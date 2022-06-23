#include <iostream>
#include <fstream>

using namespace std;

bool resuelveCaso() {
	char c;
	cin >> c;
	if (c == '.') return false;
	int v = 0, i = 0;
	while (c != '.') {
		if (c == 'I') i++;
		else if(c == 'V') v++;
		cin >> c;
	}
	if (i > v) cout << "INVIERNO\n";
	else if (i < v) cout << "VERANO\n";
	else cout << "EMPATE\n";
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}