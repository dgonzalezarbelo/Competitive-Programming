#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;
#pragma warning (disable:4996)

vector<int> dp;

int solve(vector<int> const& alturas, vector<int> const& costes, int pos, int desnivel) {
	if (pos == alturas.size() - 1) {
		return 0;
	}
	else {
		if (dp[pos] != -1) return dp[pos];
		int i = pos + 1;
		int minimo = INT_MAX;
		while (i < alturas.size() && alturas[i] - alturas[pos] <= desnivel) {
			minimo = min(minimo, solve(alturas, costes, i, desnivel));
			i++;
		}
		return dp[pos] = minimo + costes[pos];
	}
}

bool resuelveCaso() {
	int num;
	if (scanf("%d", &num) == EOF) return false;
	vector<int> alturas(num + 1);
	alturas[0] = 0;
	for (int i = 1; i < num + 1; i++) cin >> alturas[i];
	vector<int> costes(num + 1);
	costes[0] = 0;
	for (int i = 1; i < num + 1; i++) cin >> costes[i];
	int desnivel;
	scanf("%d", &desnivel);
	dp.assign(num + 1, -1);
	printf("%d\n", solve(alturas, costes, 0, desnivel));
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}