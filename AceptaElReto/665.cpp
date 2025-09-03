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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		vi v(3), w(3);
		for (int i = 0; i < 3; i++) {
			cin >> v[i];
			cin.get();
		} 
		for (int i = 0; i < 3; i++) {
			cin >> w[i];
			cin.get();
		}
		vi a = { v[0] + 1, 0, 0 };
		vi b = { v[0], v[1] + 1, 0 };
		vi c = { v[0], v[1], v[2] + 1 };
		if (w == a || w == b || w == c) cout << "SI\n";
		else cout << "NO\n";
	}
	return 0;
}