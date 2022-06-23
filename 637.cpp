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

unordered_map<char, int> puntos;

void resuelveCaso() {
	string linea;
	getline(cin, linea);
	int total = 0;
	bool primera = true;
	for (char c : linea) {
		if (c == ' ') {
			primera = true;
			total += 5;
		}
		else {
			if (!primera) total += 3;
			primera = false;
			total += puntos.at(c);
		}
	}
	cout << total << '\n';
}

int main() {
	puntos['A'] = 5;
	puntos['B'] = 9;
	puntos['C'] = 11;
	puntos['D'] = 7;
	puntos['E'] = 1;
	puntos['F'] = 9;
	puntos['G'] = 9;
	puntos['H'] = 7;
	puntos['I'] = 3;
	puntos['J'] = 13;
	puntos['K'] = 9;
	puntos['L'] = 9;
	puntos['M'] = 7;
	puntos['!'] = 19;
	puntos['N'] = 5;
	puntos['O'] = 11;
	puntos['P'] = 11;
	puntos['Q'] = 13;
	puntos['R'] = 7;
	puntos['S'] = 5;
	puntos['T'] = 3;
	puntos['U'] = 7;
	puntos['V'] = 9;
	puntos['W'] = 9;
	puntos['X'] = 11;
	puntos['Y'] = 13;
	puntos['Z'] = 11;
	puntos['?'] = 15;
	int n;
	cin >> n;
	cin.get();
	while (n--) resuelveCaso();
	return 0;
}