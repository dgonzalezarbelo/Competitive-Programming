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

using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<pair<int, int>>;
using lli = long long int;
using vlli = vector<long long int>;

struct pair_hash {
	template <class T1, class T2>
	std::size_t operator () (const std::pair<T1, T2>& p) const {
		auto h1 = std::hash<T1>{}(p.first);
		auto h2 = std::hash<T2>{}(p.second);

		// Mainly for demonstration purposes, i.e. works but is overly simple
		// In the real world, use sth. like boost.hash_combine
		return h1 ^ h2;
	}
};

unordered_map<ii, vector<vi>, pair_hash> piezas;

vi primera_libre;

void colocar(int I, int R, int P) {
	vector<vi> forma = piezas[{I, R}];
	int fila = primera_libre[P];
	bool valida = false;
	while (!valida) {	//Primero encontramos una valida
		valida = true;
		for (int i = 0; i < 4 && valida; i++) {
			for (int j = 0; j < 4 && valida; j++) {
				if (forma[i][j]) {
					if (fila + i < primera_libre[P + j]) {
						valida = false;
					}
				}
			}
		}
		if (!valida) fila++;
	}
	valida = true;
	while (valida && fila - 1 >= 0) {	//Ahora vemos si podemos bajar mas
		for (int i = 0; i < 4 && valida; i++) {
			for (int j = 0; j < 4 && valida; j++) {
				if (forma[i][j]) {
					if (fila - 1 + i < primera_libre[P + j]) {
						valida = false;
					}
				}
			}
		}
		if (valida) fila--;
	}
	for (int i = 0; i < 4; i++) {	//Recorremos de abajo a arriba para actualizar la primera libre
		for (int j = 0; j < 4; j++) {
			if (forma[i][j]) {
				primera_libre[P + j] = fila + i + 1;
			}
		}
	}
}

bool resuelveCaso() {
	int C, N;
	scanf("%d %d", &C, &N);
	if (!C && !N) return false;
	primera_libre.assign(C + 1, 0);
	int I, R, P;
	while (N--) {
		scanf("%d %d %d", &I, &R, &P);
		colocar(I, R, P);
	}
	for (int i = 1; i < primera_libre.size(); i++) {
		if (i - 1) printf(" ");
		printf("%d", primera_libre[i]);
	}
	printf("\n");
	return true;
}

int main() {
	piezas[{1, 0}] = piezas[{1, 180}] = { {1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };
	piezas[{1, 90}] = piezas[{1, 270}] = { {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0} };
	piezas[{2, 0}] = { {1, 1, 1, 0}, {1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };
	piezas[{2, 90}] = { {1, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0} };
	piezas[{2, 180}] = { {0, 0, 1, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };
	piezas[{2, 270}] = { {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 1, 0, 0}, {0, 0, 0, 0} };
	piezas[{3, 0}] = { {1, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };
	piezas[{3, 90}] = { {0, 1, 0, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}, {0, 0, 0, 0} };
	piezas[{3, 180}] = { {1, 0, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}  };
	piezas[{3, 270}] = { {1, 1, 0, 0}, {1, 0, 0, 0},{1, 0, 0, 0}, {0, 0, 0, 0} };
	piezas[{4, 0}] = piezas[{4, 90}] = piezas[{4, 180}] = piezas[{4, 270}] = { {1, 1, 0, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };
	piezas[{5, 0}] = piezas[{5, 180}] = { {1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };
	piezas[{5, 90}] = piezas[{5, 270}] = { {0, 1, 0, 0}, {1, 1, 0, 0}, {1, 0, 0, 0}, {0, 0, 0, 0} };
	piezas[{6, 0}] = { {1, 1, 1, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };
	piezas[{6, 90}] = { {0, 1, 0, 0}, {1, 1, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0} };
	piezas[{6, 180}] = { {0, 1, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };
	piezas[{6, 270}] = { {1, 0, 0, 0}, {1, 1, 0, 0}, {1, 0, 0, 0}, {0, 0, 0, 0} };
	piezas[{7, 0}] = piezas[{7, 180}] = { {0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };
	piezas[{7, 90}] = piezas[{7, 270}] = { {1, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0} };
	while (resuelveCaso());
	return 0;
}