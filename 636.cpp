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

bool resuelveCaso() {
	int n, d;
	cin >> n >> d;
	if (!cin) return false;
	unordered_map<int, int> aparecidos;
	int comienzoPeriodo = -1;
	vector<int> division;
	n *= 10;
	int i = 0;
	if (n % d == 0) division.push_back(n / d);
	while (n % d != 0) {
		if (!aparecidos.count(n)) {
			aparecidos[n] = i;
			division.push_back(n / d);
			n %= d;
			++i;
		}
		else {
			comienzoPeriodo = aparecidos[n];
			break;
		}
		n *= 10;
		if (n % d == 0) division.push_back(n / d);
	}
	cout << "0.";
	for (int j = 0; j < division.size(); j++) {
		if (j == comienzoPeriodo) cout << "|";
		cout << division[j];
	}
	if (comienzoPeriodo != -1) cout << "|";
	cout << '\n';
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}