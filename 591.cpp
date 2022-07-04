#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <deque>
#include <numeric>
#include <algorithm>
#include <climits>
#pragma warning (disable : 4996)
using namespace std;

using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<pair<int, int>>;
using lli = long long int;
using vlli = vector<long long int>;

bool resuelveCaso() {
	int n;
	if (scanf("%d", &n) == EOF) return false;
	vector<lli> anillos((n + 1) / 2);
	lli aux;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%lld", &aux);
			anillos[min({ i, j, n - 1 - i, n - 1 - j })] += aux;
		}
	}
	for (int i = (n + 1) / 2 - 1; i >= 0; i--) {
		printf("%lld", anillos[i]);
		if (i) printf(" ");
	}
	printf("\n");
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}