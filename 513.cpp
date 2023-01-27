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
	int n;
	cin >> n;
	if (!cin) return false;
	int a;
	cin >> a;
	cout << a;
	int s = a;
	int b;
	for (int i = 2; i <= n; i++) {
		cin >> a;
		b = i * a - s;
		cout << ' ' << b;
		s += b;
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