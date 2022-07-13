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

using lli = long long int;

lli base10(lli n) {
	lli pot = 1;
	lli res = 0;
	while (n) {
		res += (n % 10) * pot - ((n % 10) >= 5) * pot;
		pot *= 9;
		n /= 10;
	}
	return res;
}

bool resuelveCaso() {
	lli a, b;
	cin >> a >> b;
	if (!cin) return false;
	a = base10(a);
	b = base10(b);
	lli N = a * b;
	string num;
	lli pot = 1;
	while (pot * 9 <= N) {
		pot *= 9;
	}
	while (pot != 0) {
		num += N / pot + '0';
		N %= pot;
		pot /= 9;
	}
	for (char c : num) {
		if (int(c) - '0' >= 5) cout << int(c) - '0' + 1;
		else cout << c;
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