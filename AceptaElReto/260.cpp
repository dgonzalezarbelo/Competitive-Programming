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

void resuelveCaso() {
	string s;
	getline(cin, s);
	unordered_map<char, int> m;
	int total = 0;
	for (char c : s) {
		if (c != ' ') {
			m[tolower(c)]++;
			total++;
		}
	}
	getline(cin, s);
	bool ok = true;
	for (char c : s) {
		if (c != ' ') {
			if (m[tolower(c)]-- == 0) {
				ok = false;
				break;
			}
			total--;
		}
	}		
	if (ok && !total) cout << "SI\n";
	else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	cin.get();
	while (t--) resuelveCaso();
	return 0;
}