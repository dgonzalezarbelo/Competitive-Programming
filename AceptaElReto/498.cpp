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

vlli potencias;

bool resuelveCaso() {
	int k, n;
	scanf("%d %d", &k, &n);
	if (!k && !n) return false;
	lli m1 = potencias[k - 1] * (2 * k - 1);
	lli m2 = potencias[n] - k * potencias[k] - potencias[k - 1];
	if (m1 < 0) m1 = -1;
	if (m2 < 0) m2 = -1;
	if (m1 >= potencias[n]) m1 = -1;
	if (m2 >= potencias[n]) m2 = -1;
	printf("%d %d %lld %lld\n", k, n, m1, m2);
	return true;
}

int main() {
	lli pot = 1;
	int i = 0;
	while (i <= 32) {
		potencias.push_back(pot);
		pot *= 2;
		i++;
	}
	while (resuelveCaso());
	return 0;
}