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

vll dp;

unordered_set<string> numeros;

ll solve(string const& n, int i) {
	if (i >= n.size()) return 1;
	if (dp[i] != -1) return dp[i];
	ll sol = 0;
	for (int j = 1; j <= 4 && i + j <= n.size(); j++) {
		if (numeros.count(n.substr(i, j))) {
			sol += solve(n, i + j);
		}
	}
	return dp[i] = sol;
}

bool resuelveCaso() {
	string n;
	cin >> n;
	if (!cin) return false;
	dp.assign(n.size(), -1);
	cout << solve(n, 0) << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	numeros.insert("X");
	numeros.insert("I");
	numeros.insert("II");
	numeros.insert("III");
	numeros.insert("IV");
	numeros.insert("V");
	numeros.insert("VI");
	numeros.insert("VII");
	numeros.insert("VIII");
	numeros.insert("IX");
	while (resuelveCaso());
	return 0;
}