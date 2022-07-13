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

struct tarea {
	int ini;
	int fin;
	int periodo = 0;
	bool repetir;
};

struct comp {
	bool operator() (tarea const& t1, tarea const& t2) {
		return t1.ini > t2.ini;
	}
};

bool resuelveCaso() {
	int n, m, t;
	cin >> n >> m >> t;
	if (!cin) return false;
	priority_queue<tarea, vector<tarea>, comp> pq;
	int a, b, c;
	while (n--) {
		cin >> a >> b;
		tarea t;
		t.ini = a;
		t.fin = b;
		t.repetir = false;
		pq.push(t);
	}
	while (m--) {
		cin >> a >> b >> c;
		tarea t;
		t.ini = a;
		t.fin = b;
		t.periodo = c;
		t.repetir = true;
		pq.push(t);	
	}
	a = 0;
	bool solapamiento = false;
	while (pq.top().ini < t && !pq.empty()) {
		tarea t = pq.top();
		if (t.ini < a) {
			solapamiento = true;
			break;
		}
		if (t.periodo) {
			tarea t2;
			t2.ini = t.ini + t.periodo;
			t2.fin = t.fin + t.periodo;
			t2.periodo = t.periodo;
			t.repetir = true;
			pq.push(t2);
		}
		a = t.fin;
		pq.pop();
	}
	solapamiento ? cout << "SI\n" : cout << "NO\n";
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}