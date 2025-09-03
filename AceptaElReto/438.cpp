#include <iostream>
#include <string>
using namespace std;

bool resuelveCaso() {
	string linea;
	getline(cin, linea);
	if (!cin) return false;
	int i = 0;
	int exclamaciones = 0, letras = 0;
	while (i < linea.size()) {
		if (linea[i] == '!') {
			exclamaciones++;
		}
		else if (isalpha(linea[i])) letras++;
		i++;
	}
	letras >= exclamaciones ? printf("escrito\n") : printf("ESGRITO\n");
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}