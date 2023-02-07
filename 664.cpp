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

bool solve() {
	int n; cin >> n;
	if (!n) return false;
	int maximo = -1, sol = INT_MAX;
	while (n--) {
		int a; cin >> a;
		maximo = INT_MIN;
		while (a--) {
			int b;
			cin >> b;
			maximo = max(maximo, b);
		}
		sol = min(maximo, sol);
	}
	cout << sol << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (solve());
	return 0;
}