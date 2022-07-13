#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <deque>
#include <numeric>
#include <algorithm>
#pragma warning (disable : 4996)
using namespace std;

vector<int> libros;
vector<int> mejores;

void solve() {
	int i = libros.size() - 1;
	mejores[i] = 0;
	while (i >= 0) {
		int mejor = 0;
		int lote = 0;
		if (i < int(libros.size()) - 2) {
			lote = min({ libros[i], libros[i + 1], libros[i + 2]});
			if (i + 3 < libros.size()) lote += mejores[i + 3];
		}
		int saltar = 0;
		if (i + 1 < libros.size()) saltar = mejores[i + 1];
		mejor = max(lote, saltar);
		mejores[i] = mejor;
		i--;
	}
}

bool resuelveCaso() {
	int n;
	cin >> n;
	if (!cin) return false;
	libros.assign(n, 0);
	for (int & x : libros) {
		cin >> x;
	}
	mejores.assign(n, 0);
	solve();
	cout << mejores[0] << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}