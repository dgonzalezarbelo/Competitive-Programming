#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <iomanip>
#include <climits>
#include <cmath>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <algorithm>
#pragma warning (disable : 4996)

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

////////////////////////////////////////////

vi dp;
vi pasos;

const int mod = 1000000007;

int solve(int i, int n) {
	if (i > n) return 0;
	else if (dp[i] != -1) return dp[i];
	dp[i] = 0;
	for (int a : pasos) {
		dp[i] += solve(i + a, n);
		dp[i] %= mod;
	}
	return dp[i];
}

bool resuelveCaso() {
	int n, k;
	scanf("%d", &n);
	if (!n) return false;
	scanf("%d", &k);
	dp.assign(n + 1, -1);
	dp[n] = 1;
	pasos.clear();
	while (k--) {
		int a;
		scanf("%d", &a);
		pasos.push_back(a);
	}
	solve(0, n);
	printf("%d\n", dp[0]);
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}