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
	vi v(101);
	int pares = 0, cuatros = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v[a]++;
		if (v[a] % 4 == 0) {
			cuatros++;
			pares--;
		}
		else if (v[a] % 2 == 0) pares++;
	}
	int sol = 0;
	while (cuatros > 0 && pares > 0) {
		sol++;
		cuatros--;
		pares--;
	}
	for (int i = 1; i <= cuatros; i++) {
		if (i % 3 != 1) sol++;
	}
	cout << sol << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}