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

void resuelveCaso() {
	string line;
	getline(cin, line);
	int puntos = 0;
	int actual = 0;
	for (auto c : line) {
		if (c == 'O') {
			actual += 10;
		}
		else {
			actual = 0;
		}
		puntos += actual;
	}
	printf("%d\n", puntos);
}

int main() {
	int n;
	cin >> n;
	cin.get();
	while (n--) resuelveCaso();
	return 0;
}