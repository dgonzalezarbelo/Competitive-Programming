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

vi cantidades;

bool resuelveCaso() {
	vi numero;
	int n;
	cin >> n;
	if (!n) return false;
	for (int i = 0; i < 4; i++) {
		numero.push_back(n % 10);
		n /= 10;
	}
	vi necesarias(10, 0);
	cantidades.assign(10, 0);
	for (int i = 0; i < 10; i++) cin >> cantidades[i];
	for (int i = 0; i < 4; i++) {
		necesarias[numero[i]] += 3;
	}
	int s = INT_MAX;
	for (int i = 0; i < 10; i++) {
		if(necesarias[i]) s = min(s, cantidades[i] / necesarias[i]);
	}
	cout << s << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}