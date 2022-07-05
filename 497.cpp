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
#include <climits>
#pragma warning (disable : 4996)
using namespace std;

using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<pair<int, int>>;
using lli = long long int;
using vlli = vector<long long int>;

bool resuelveCaso() {
	int n, l;
	scanf("%d %d", &n, &l);
	if (!n && !l) return false;
	vector<int> apariciones(n + 1);
	int importantes = 0;
	vector<vi> lineas;
	unordered_map<int, int> cambio;
	unordered_map<int, int> cambio_inverso;
	while (l--) {
		vector<int> linea;
		int aux;
		scanf("%d", &aux);
		while (aux) {
			linea.push_back(aux);
			apariciones[aux]++;
			if (apariciones[aux] == 2) {
				cambio[aux] = importantes;
				cambio_inverso[importantes++] = aux;
			} 
			scanf("%d", &aux);
		}
		lineas.push_back(linea);
	}
	vector<vi> am(importantes, vi(importantes, 10e4));
	for (int k = 0; k < lineas.size(); k++) {
		vector<int>& linea = lineas[k];
		for (int i = 0; i < linea.size(); i++) {
			for (int j = i + 1; j < linea.size(); j++) {
				if (apariciones[linea[i]] >= 2 && apariciones[linea[j]] >= 2) {
					am[cambio[linea[i]]][cambio[linea[j]]] = min(am[cambio[linea[i]]][cambio[linea[j]]], 10 * (j - i));
					am[cambio[linea[j]]][cambio[linea[i]]] = min(am[cambio[linea[j]]][cambio[linea[i]]], 10 * (j - i));
				}
			}
		}
	}
	for (int k = 0; k < importantes; k++) {
		for (int i = 0; i < importantes; i++) {
			for (int j = 0; j < importantes; j++) {
				am[i][j] = min(am[i][j], am[i][k] + am[k][j]);
			}
		}
	}
	int total;
	int min = INT_MAX;
	int importante = 0;
	for (int i = 0; i < importantes; i++) {
		total = 0;
		for (int j = 0; j < importantes; j++) {
			if (i != j) {
				total += am[i][j];
			}
		}
		if (total < min || (total == min && cambio_inverso[i] < importante)) {
			importante = cambio_inverso[i];
			min = total;
		}
	}
	printf("%d\n", importante);
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}