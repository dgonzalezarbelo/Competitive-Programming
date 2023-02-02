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
	vector<ii> v;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a, 1 });
		v.push_back({ b, -1 });
	}
	sort(v.begin(), v.end());
	vii w;
	int cur = 0, sum = 0;
	for (ii p : v) {
		if (p.first == cur) sum += p.second;
		else {
			if(sum != 0) w.push_back({ cur,sum });
			sum = p.second;
		}
		cur = p.first;
	}
	w.push_back({ cur, sum });
	int maximaOcupacion = 0, tiempo = 0;
	sum = 0;
	for (int i = 0; i < w.size() - 1; i++) {
		ii p = w[i];
		sum += p.second;
		if (sum > maximaOcupacion) {
			tiempo = w[i + 1].first - p.first;
			maximaOcupacion = sum;
		}
		else if (sum == maximaOcupacion) {
			tiempo += w[i + 1].first - p.first;
		}
	}
	cout << maximaOcupacion << ' ' << tiempo << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}