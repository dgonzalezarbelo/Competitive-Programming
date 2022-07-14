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
using ll = long long;
using vll = vector<long long int>;

vector<vector<int>> dp;

int solve(string const& a, string const& b, int i, int j) {
	if (i == a.size()) return 0;
	else if (j == b.size()) return 0;
	else {
		if (dp[i][j] != -1) return dp[i][j];
		if (a[i] == b[j]) return dp[i][j] = solve(a, b, i + 1, j + 1) + 1;
		else return dp[i][j] = max(solve(a, b, i + 1, j), solve(a, b, i, j + 1));
	}
}

bool resuelveCaso() {
	string a, b;
	cin >> a >> b;
	if (!cin) return false;
	dp.assign(a.size(), vector<int>(b.size(), -1));
	cout << solve(a, b, 0, 0) << '\n';
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}