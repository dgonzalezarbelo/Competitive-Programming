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

void resuelveCaso() {
	int p, n;
	cin >> p >> n;
	vi v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	auto it = lower_bound(v.begin(), v.end(), p);
	int pos = it - v.begin();
	int i, j;
	int curr;
	if (pos < n) {
		if (v[pos] == p) {
			cout << p;
			i = pos - 1;
			j = pos + 1;
			curr = p;
		}
		else {
			if (pos > 0 && pos < n) {
				if (p - v[pos - 1] < v[pos] - p) {
					cout << v[pos - 1];
					i = pos - 2;
					j = pos;
					curr = v[pos - 1];
				}
				else {
					cout << v[pos];
					i = pos - 1;
					j = pos + 1;
					curr = v[pos];
				}
			}
			else if(pos == 0) {
				cout << v[pos];
				i = pos - 1;
				j = pos + 1; 
				curr = v[pos];
			}
			else {
				cout << v[pos - 1];
				i = pos - 2;
				j = pos;
				curr = v[pos - 1];
			}
		}
		while (i >= 0 || j < n) {
			if (i >= 0 && j < n) {
				if (curr - v[i] < v[j] - curr) {
					cout << ' ' << v[i];
					curr = v[i];
					i--;
				}
				else {
					cout << ' '	<< v[j];
					curr = v[j];
					j++;
				}
			}
			else if (i < 0) {
				cout << ' ' << v[j];
				curr = v[j];
				j++;
			}
			else {
				cout << ' ' << v[i];
				curr = v[i];
				i--;
			}
		}
	}
	else {
		for (int i = n - 1; i >= 0; i--) {
			cout << v[i];
			if (i) cout << ' ';
		}
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) resuelveCaso();
	return 0;
}