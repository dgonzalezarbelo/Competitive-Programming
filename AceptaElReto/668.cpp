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
	int a, b, n;
	cin >> a >> b >> n;
	if (!a && !b && !n) return false;
	n %= 6;
	if (n == 0) cout << a << '\n';
	else if (n == 1) cout << b << '\n';
	else if (n == 2) cout << b - a << '\n';
	else if (n == 3) cout << -a << '\n';
	else if (n == 4) cout << -b << '\n';
	else cout << -b + a << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}