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

void resuelveCaso() {
	int g, n;
	cin >> g >> n;
	vll v(g), dp(g);
	for (int i = 0; i < g; i++) cin >> v[i];
	dp[g - 1] = v[g - 1];
	for (int i = g - 2; i >= 0; i--) {
		ll sol = dp[i + 1];
		if (i + n + 1 < g) sol = max(sol, dp[i + n + 1] + v[i]);
		else sol = max(sol, v[i]);
		dp[i] = sol;
	}
	cout << dp[0] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) resuelveCaso();
	return 0;
}