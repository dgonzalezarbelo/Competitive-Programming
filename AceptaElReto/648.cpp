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

vector<pair<int, int>> pasos;
vector<int> sectores;
int n;

int solve(int a) {
	if (a > n) return -2;
	if (a == n) {
		pasos[a].first = 0;
		pasos[a].second = 0;
		return 0;
	}
	if (pasos[a].first != -1) return pasos[a].first;
	int mejor = -1;
	for (int b : sectores) {
		int c = solve(a + b);
		if (c != -1 && c != -2) {
			if (pasos[a].first == -1 || pasos[a].first > c) {
				pasos[a].first = c + 1;
				pasos[a].second = b;
			} 
		}
	}
	if (pasos[a].first == -1) pasos[a].first = -2;
	return pasos[a].first;
}

bool resuelveCaso() {
	int s;
	if (scanf("%d %d", &n, &s) == EOF) return false;
	int a;
	sectores.clear();
	int max = -1;
	while (s--) {
		scanf("%d", &a);
		sectores.push_back(a);
		if (a > max) max = a;
	}
	pasos.assign(n + max + 1, {-1, -1});
	solve(0);
	if (pasos[0].first != -1 && pasos[0].first != -2) {
		printf("%d:", pasos[0]);
		int c = 0;
		while (c != n) {
			printf(" %d", pasos[c].second);
			c += pasos[c].second;
		}
		printf("\n");
	}
	else printf("Imposible\n");
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}