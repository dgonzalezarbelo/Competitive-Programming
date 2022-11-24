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

/*-------------------------------------*/

bool resuelveCaso() {
	int n;
	scanf("%d", &n);
	if (!n) return false;
	unordered_set<int> s;
	int a;
	int m = 0;
	while (n--) {
		cin >> a;
		if (!s.count(a)) s.insert(a);
		else s.erase(a);
		if (s.size() > m) m = s.size();
	}
	printf("%d\n", m);
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}