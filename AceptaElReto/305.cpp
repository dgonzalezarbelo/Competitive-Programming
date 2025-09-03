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
	if (!cin) return false;
	vector<int> ataque, defensa;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		ataque.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		defensa.push_back(a);
	}
	sort(ataque.begin(), ataque.end());
	sort(defensa.begin(), defensa.end());
	int i = 0, j = 0;
	int s = 0;
	while (i < n && j < n) {
		if (ataque[i] <= defensa[j]) {
			s++;
			i++;
			j++;
		}
		else j++;
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