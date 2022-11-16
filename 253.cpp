#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool resuelveCaso() {
	int N, K, S, E;
	cin >> N >> K >> S >> E;
	if (N == 0 && K == 0 && S == 0 && E == 0) return false;
	int cuadrado = N * N;
	vector<int> v(cuadrado + 1);
	for (int i = 1; i <= cuadrado; i++) {
		v[i] = i;
	}
	int aux;
	for (int i = 0; i < S + E; i++) {
		cin >> aux;
		cin >> v[aux];
	}
	vector<int> dist(cuadrado + 1, -1);
	queue<int> cola;
	cola.push(1);
	dist[1] = 0;
	bool terminar = false;
	while (!terminar) {
		int casilla = cola.front();
		cola.pop();
		for (int i = 1; i <= K && casilla + i <= cuadrado; i++) {
			if (dist[v[casilla + i]] == -1) {
				cola.push(v[casilla + i]);
				dist[v[casilla + i]] = 1 + dist[casilla];
				if (v[casilla + i] == cuadrado) {
					terminar = true;
					break;
				}
			}
		}
	}
	cout << dist[cuadrado] << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}