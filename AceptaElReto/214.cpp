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

using namespace std;
typedef vector<int> vi;

bool resuelveCaso() {
	int n;
	cin >> n;
	if (!n) return false;
	unordered_map<string, int> m;
	string s;
	while (n--) {
		cin >> s;
		m[s]++;
	}
	cin >> n;
	while (n--) {
		cin >> s;
		cout << ++m[s] << '\n';
	}
	cout << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}