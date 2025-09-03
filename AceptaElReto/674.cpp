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
	ll d, n;
	cin >> d >> n;
	if (!d && !n) return false;
	ll ini = 1, fin = 10e12 + 1;
	ll m;
	while (ini < fin) {
		if (ini == fin - 1) {
			m = ini;
			break;
		}
		else if (ini == fin - 2) {
			ll pot = 5;
			ll cincos = 0;
			while (ini >= pot) {
				cincos += ini / pot;
				pot *= 5;
			}
			if (cincos < n) m = ini + 1;
			else m = ini;
			break;
		}
		m = (fin + ini - 1) / 2;
		ll pot = 5;
		ll cincos = 0;
		while (m >= pot) {
			cincos += m / pot;
			pot *= 5;
		}
		if (cincos < n) ini = m + 1;
		else fin = m + 1;
	}
	if ((m % d) != 0) m += d - (m % d);
	ll cincos = 0;
	ll pot = 5;
	while (m >= pot) {
		cincos += m / pot;
		pot *= 5;
	}
	if (cincos == n) cout << m << '\n';
	else cout << "NINGUNO\n";
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}