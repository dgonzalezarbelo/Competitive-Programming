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

vector<vector<char>> mat; //{Posicion, visitada}

struct posit {
	unordered_set<char> solapado_por;
	unordered_set<char> solapa_a;
	int iz = INT_MAX, der = INT_MIN, arr = INT_MAX, ab = INT_MIN;
};

unordered_map<char, posit> posits;

map<int, set<char>> solapamientos;

void busca_solapamientos(char c) {
	posit& p = posits[c];
	int s = 0; //Solapamientos
	char a;
	for (int i = p.arr; i <= p.ab; i++) {
		for (int j = p.iz; j <= p.der; j++) {
			a = mat[i][j];
			if (a != c && !p.solapado_por.count(a)) {
				p.solapado_por.insert(a);
				posits[a].solapa_a.insert(c);
				s++;
			}
		}
	}
	solapamientos[s].insert(c);
}

void resuelveCaso() {
	int ancho, alto;
	cin >> ancho >> alto;
	mat.assign(alto, vector<char>(ancho));
	posits.clear();
	solapamientos.clear();
	for (int i = 0; i < alto; i++) {
		for (int j = 0; j < ancho; j++) {
			char c;
			cin >> c;
			mat[i][j] = c;
			if (c != '.') {
				posit& p = posits[c];
				p.iz = min(p.iz, j);
				p.der = max(p.der, j);
				p.arr = min(p.arr, i);
				p.ab = max(p.ab, i);
			}
		}
	}
	for (auto it : posits) {
		busca_solapamientos(it.first);
	}
	bool posible = true;
	list<list<char>> orden;
	while (posible && !solapamientos.empty()) {
		auto it = solapamientos.begin();
		if (it->first > 0) {
			posible = false;
			break;
		}
		set<char> s = it->second;
		list<char> actuales;
		for (char c : s) {
			posit& p = posits[c];
			for (char d : p.solapa_a) {
				posit& p2 = posits[d];
				solapamientos[p2.solapado_por.size()].erase(d);
				if (solapamientos[p2.solapado_por.size()].empty()) solapamientos.erase(p2.solapado_por.size());
				p2.solapado_por.erase(c);
				solapamientos[p2.solapado_por.size()].insert(d);
			}
			actuales.push_back(c);
		}
		for (char c : actuales) solapamientos[0].erase(c);
		if (solapamientos[0].empty()) solapamientos.erase(0);
		orden.push_back(actuales);
		actuales.clear();
	}
	if (posible) {
		bool primer_char = true;
		for (auto& l : orden) {
			primer_char = true;
			for (char c : l) {
				if (!primer_char) {
					cout << ' ';
				}
				primer_char = false;
				cout << c;
			}
			cout << '\n';
		}
	}
	else cout << "IMPOSIBLE\n";
	cout << "----\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	while (n--) resuelveCaso();
	return 0;
}