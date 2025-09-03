#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
#pragma warning (disable:4996)

bool resolver(int& a, int& b, int k, vector<long long int>& v, int capacidad) {
	if (k == v.size()) return true;
	else {
		if (a + v[k] <= capacidad) {
			a += v[k];
			if (resolver(a, b, k + 1, v, capacidad)) return true;
			a -= v[k];
		}
		if (b + v[k] <= capacidad) {
			b += v[k];
			if (resolver(a, b, k + 1, v, capacidad)) return true;
			b -= v[k];
		}
		return false;
	}
}

bool resuelveCaso() {
	int capacidad, num;
	cin >> capacidad >> num;
	if (!cin) return false;
	vector<long long int> v(num);
	for (int i = 0; i < num; i++) cin >> v[i];
	int a = 0, b = 0;
	bool sol = resolver(a, b, 0, v, capacidad);
	if (sol) cout << "SI\n";
	else cout << "NO\n";
	return true;
}

int main() {
	while (resuelveCaso());


	return 0;
}