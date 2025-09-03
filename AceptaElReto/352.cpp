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
	int n, m;
	cin >> n >> m;
	al.assign(n, vi());
	marks.assign(n, false);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		al[a].push_back(b);
		al[b].push_back(a);
	}
	int s = 0;
	for (int i = 0; i < n; i++) {
		s = max(s, dfs(i));
	}
	cout << s << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) resuelveCaso();
	return 0;
}