#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#pragma warning (disable:4996)
using namespace std;

vector<vector<int>> dp;

int solve(vector<vector<int>> const& v, int origen, int destino) {
	if (dp[origen][destino] != -1) return dp[origen][destino];
	else {
		int minimo = v[origen][destino];
		for (int j = origen + 1; j < destino; j++) {
			minimo = min(minimo, solve(v, origen, j) + solve(v, j, destino));
		}
		return dp[origen][destino] = minimo;
	}
}

bool resuelveCaso() {
	int n;
	if (scanf("%d", &n) == EOF) return false;
	vector<vector<int>> v(n, vector<int> (n));
	dp.assign(n, vector<int>(n, - 1));
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			cin >> v[i][j];
			dp[i][j] = -1;
		} 
	}
	for (int origen = 0; origen < n - 1; origen++) {
		printf("%d", solve(v, origen, origen + 1));
		for (int destino = origen + 2; destino < n; destino++) {
			printf(" %d", solve(v, origen, destino));
		}
		printf("\n");
	}
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}