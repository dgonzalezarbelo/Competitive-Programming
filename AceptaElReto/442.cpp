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

vvi al;
vb marks;

int dfs(int a) {
	if (marks[a]) return 0;
	marks[a] = true;
	int s = 1;
	for (int b : al[a]) {
		s += dfs(b);
	}
	return s;
}

bool resuelveCaso() {
	string s;
	cin >> s;
	if (!cin) return false;
	string tipo;
	cin >> tipo;
	if (tipo == "snake_case") {
		bool primerUpper = true;
		for (char c : s) {
			if (isupper(c)) {
				if (!primerUpper) cout << '_';
				primerUpper = false;
				cout << (char)tolower(c);
			}
			else if (c == '-') cout << '_';
			else cout << c;
		}
	}
	else if (tipo == "kebab-case") {
		bool primerUpper = true;
		for (char c : s) {
			if (isupper(c)) {
				if (!primerUpper) cout << '-';
				primerUpper = false;
				cout << (char)tolower(c);
			}
			else if (c == '_') cout << '-';
			else cout << c;
		}
	}
	else {
		bool mayus = true;
		for (char c : s) {
			if (c == '-' || c == '_') mayus = true;
			else {
				if (mayus) cout << (char)toupper(c);
				else cout << c;
				mayus = false;
			}
		}
	}
	cout << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}