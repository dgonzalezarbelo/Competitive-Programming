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
	int n, c;
	cin >> n >> c;
	if (!cin) return false;
	vi v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	int suma = 0;
	for (int i = 0; i < c; i++) {
		suma += v[i];
	}
	int pivote = -1, iz = 0, der = suma;
	while (iz + v[pivote + 1] <= der) {
		pivote++;
		iz += v[pivote];
		der -= v[pivote];
	}
	int maximo = -1, index = -1;
	if (iz == der) {
		maximo = iz;
		index = 0;
	}
	for (int i = c; i < n; i++) {
		iz -= v[i - c];
		der += v[i];
		while (iz + v[pivote + 1] <= der) {
			pivote++;
			iz += v[pivote];
			der -= v[pivote];
		}
		if (iz == der && iz > maximo) {
			maximo = iz;
			index = i - c + 1;
		}
	}
	index > -1 ? cout << index + 1<< '\n' : cout << "SIN ADORNOS\n";
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}