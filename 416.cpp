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

bool resuelveCaso() {
	int n;
	cin >> n;
	if (!n) return false;
	unordered_set<int> s;
	bool repetido = false;
	while (n--) {
		int a, b, c;
		cin >> a;
		cin.get();
		cin >> b;
		cin.get();
		cin >> c;
		if (s.count(337 * a + b)) {
			repetido = true;
		}
		else s.insert(337 * a + b);
	}
	repetido ? cout << "SI\n" : cout << "NO\n";
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}