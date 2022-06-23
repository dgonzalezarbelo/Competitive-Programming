#include <iostream>
#include <string>
using namespace std;

void resuelveCaso() {
	string c, nombre;
	cin >> nombre;
	int n;
	cin >> n;
	if (n == 1) {
		cin >> c;
		printf("FALSA\n");
		return;
	}
	int pos = -1;
	for (int i = 1; i <= n; i++) {
		cin >> c;
		if (c == nombre) {
			if (pos == -1) pos = i;
		}
	}
	if (pos == n) printf("VERDADERA\n");
	else printf("FALSA\n");
}

int main() {
	int num;
	cin >> num;
	while (num--) resuelveCaso();
	return 0;
}