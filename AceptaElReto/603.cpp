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
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<bool> vb;
/*-------------------------------------*/

vi v;
vvi dp;

int solve(int ini, int fin, int i, int j) {
	if (i > j || i < 0 || j >= v.size()) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	int minimo = INT_MAX;
	for (int k = i; k <= j; k++) {
		minimo = min(minimo, solve(ini, v[k], i, k - 1) + solve(v[k], fin, k + 1, j) + fin - ini);
	}
	return dp[i][j] = minimo;
}

bool resuelveCaso() {
	int l, n;
	cin >> l >> n;
	if (!l && !n) return false;
	v.assign(n, 0);
	dp.assign(n, vi(n, -1));
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cout << 2 * solve(0, l, 0, n - 1) << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}