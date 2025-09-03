#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
#pragma warning (disable : 4996)

typedef pair<int, int> ii;

bool valid(int m, vector<ii> const& v, int t) {
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < m; i++) pq.push(0);
	for (int i = 0; i < v.size(); i++) {
		if (pq.top() - v[i].first > t) return false;
		int top = pq.top();
		pq.pop();
		if (top < v[i].first) pq.push(v[i].first + v[i].second);
		else pq.push(top + v[i].second);
	}
	return true;
}

bool resuelveCaso() {
	int n, t;
	scanf("%d %d", &n, &t);
	if (n == 0) return false;
	vector<ii> v(n);
	for (ii& x : v) scanf("%d %d", &x.first, &x.second);
	int ini = 0, fin = n;
	while (ini + 1 < fin) {
		int m = (ini + fin) / 2;
		if (valid(m, v, t)) fin = m;
		else ini = m;
	}
	printf("%d\n", fin);
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}