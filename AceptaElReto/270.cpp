#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool resuelveCaso() {
	int n;
	cin >> n;
	cin.get();
	if (!n) return false;
	map<string, int> m;
	string nombre, calificacion;
	while (n--) {
		getline(cin, nombre);
		getline(cin, calificacion);
		if (!m.count(nombre)) {
			if (calificacion == "CORRECTO") {
				m[nombre] = 1;
			}
			else m[nombre] = -1;
		}
		else {
			if (calificacion == "CORRECTO") {
				m[nombre]++;
			}
			else m[nombre]--;
		}
	}
	auto it = m.begin();
	while (it != m.end()) {
		if (it->second != 0)
			cout << it->first << ", " << it->second << '\n';
		it++;
	}
	cout << "---\n";
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}