#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable:4996)

void solve(vector<int> const& v, int numMonedas, int& suma, int & opciones, vector < pair<bool, int>> & valores, int maxMonedas, int primero) {
	if (numMonedas < maxMonedas) {
		for (int i = primero; i < v.size(); i++) {
			suma += v[i];
			if (!valores[suma].first) {
				valores[suma].first = true;
				opciones++;
			}
			if (valores[suma].second > numMonedas) {
				valores[suma].second = numMonedas;
				solve(v, numMonedas + 1, suma, opciones, valores, maxMonedas, i);
			}
			suma -= v[i];
		}
	}
}

void resuelveCaso() {
	int monedas, maxMonedas;
	scanf("%d %d", &monedas, &maxMonedas);
	vector <int> v(monedas);
	for (int& x : v) scanf("%d", &x);
	sort(v.begin(), v.end(), greater<int>());
	int suma = 0, opciones = 0;
	vector < pair<bool, int>> valores(200 * 11, {false, 11});
	solve(v, 0, suma, opciones, valores, maxMonedas, 0);
	printf("%d\n", opciones);
}

int main() {
	int num;
	scanf("%d", &num);
	while (num--) resuelveCaso();
	return 0;
}