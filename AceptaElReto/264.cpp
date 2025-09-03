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
	int i = 1, j = 1;
	int sum = 0;
	while (sum != n) {
		if (sum + j <= n) sum += j++;
		else sum -= i++;
	}
	cout << j - i << '\n';
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}