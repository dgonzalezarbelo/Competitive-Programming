#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#pragma warning(disable:4996)

void resuelveCaso() {
	int a, b;
	scanf("%d %d", &a, &b);
	vector <int> v(a + b + 1, 0);
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			v[i + j]++;
		}
	}
	vector <int> maximos;
	int maxAp = -1;
	for (int i = 1; i < v.size(); i++) {
		if (v[i] > maxAp) {
			maximos = { i };
			maxAp = v[i];
		} 
		else if (v[i] == maxAp) maximos.push_back(i);
	}
	cout << maximos[0];
	if (maximos.size() > 1) {
		for (int i = 1; i < maximos.size(); i++) {
			cout << ' ' << maximos[i];
		}
	}
	cout << '\n';
}

int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) resuelveCaso();
	return 0;
}