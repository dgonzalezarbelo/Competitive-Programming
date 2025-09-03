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
#pragma warning (disable : 4996)
using namespace std;

using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<pair<int, int>>;
using lli = long long int;
using vlli = vector<long long int>;

lli mcd(lli a, lli b) { return b == 0 ? a : mcd(b, a % b); }

lli mcm(lli a, lli b) {	return a / mcd(a, b) * b; }

bool resuelveCaso() {
	lli M, D, N;
	scanf("%lld %lld %lld", &M, &D, &N);
	if (!M && !D && !N) return false;
	printf("%lld\n", N / mcm(M, D));
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}