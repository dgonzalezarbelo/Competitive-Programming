#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#pragma warning (disable:4996)
const int mod = 10000;

bool resuelveCaso() {
	int original, fin;
	if (scanf("%d %d", &original, &fin) == EOF) return false;
	vector<int> pasos(10001);
	bool found = (original == fin);
	queue<int> q;
	q.push(original);
	pasos[original] = 0;
	int sol = 0;
	int aux;
	vector<bool> encontrados(10001, false);
	while (!found) {
		aux = (q.front() + 1) % mod;
		if (!encontrados[aux]) {
			encontrados[aux] = true;
			q.push(aux);
			pasos[aux] = pasos[q.front()] + 1;
			if (aux == fin) {
				sol = pasos[aux];
				break;
			}
		}
		aux = (q.front() * 2) % mod;
		if (!encontrados[aux]) {
			encontrados[aux] = true;
			q.push(aux);
			pasos[aux] = pasos[q.front()] + 1;
			if (aux == fin) {
				sol = pasos[aux];
				break;
			}
		}
		if (q.front() != 0) {
			aux = q.front() / 3;
			if (!encontrados[aux]) {
				encontrados[aux] = true;
				q.push(aux);
				pasos[aux] = pasos[q.front()] + 1;
				if (aux == fin) {
					sol = pasos[aux];
					break;
				}
			}
		}
		q.pop();
	}
	printf("%d\n", sol);
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}