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

int f, c, d;
vector<string> jugadores;

unordered_map<char, int> disponibles;

struct comp {
	bool operator()(string const& s1, string const& s2) {
		return s1.size() < s2.size();
	}
};

bool solve(int i) {
	if (i == jugadores.size()) return (f == 0 && c == 0 && d == 0);
	string s = jugadores[i];
	bool sol;
	bool hayf = false, hayc = false, hayd = false;
	bool entrado = false;
	for (char ch : s) {
		if (ch == 'F') hayf = true;
		if (ch == 'C') hayc = true;
		if (ch == 'D') hayd = true;
	}
	for (char ch : s) {
		int F = ch == 'F', C = ch == 'C', D = ch == 'D';
		if ((ch == 'F' && f > 0) || (ch == 'C' && c > 0) || (ch == 'D' && d > 0)) {
			f -= F; disponibles['F'] -= hayf;
			c -= C; disponibles['C'] -= hayc;
			d -= D; disponibles['D'] -= hayd;
			if (f == 0 && c == 0 && d == 0) return true;
			if (disponibles['F'] >= f && disponibles['C'] >= c && disponibles['D'] >= d) {
				if (solve(i + 1)) return true;
			}
			f += F; disponibles['F'] += hayf;
			c += C; disponibles['C'] += hayc;
			d += D; disponibles['D'] += hayd;
		}
		else {
			if (!entrado) {
				if (f == 0 && c == 0 && d == 0) return true;
				sol = solve(i + 1);
				if (sol) return true;
				entrado = true;
			}	
		}
	}
	return false;
}

bool resuelveCaso() {
	cin >> f >> c >> d;
	if (!f && !c && !d) return false;
	int n;
	cin >> n;
	jugadores.assign(n, "");
	disponibles.clear();
	for (string& s : jugadores) {
		cin >> s;
		for (char ch : s) {
			disponibles[ch]++;
		}
	} 
	sort(jugadores.begin(), jugadores.end(), comp());
	solve(0) ? cout << "SI\n" : cout << "NO\n";
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}