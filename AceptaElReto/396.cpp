#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
#pragma warning (disable:4996)

typedef pair<double, double> dd;

struct comp {
	bool operator()(dd p1, dd p2) {
		return (ceil(p1.first / p1.second) < ceil(p2.first / p2.second));
	}
};

bool resuelveCaso() {
	int p, n;
	if (scanf("%d %d", &p, &n) == EOF) return false;
	vector<double> v(n);
	for (double& x : v) cin >> x;
	priority_queue<dd, vector<dd>, comp> pq;
	for (double x : v) pq.push({ x, 1 });
	p -= n;
	int top;
	while (p--) {
		dd top = pq.top();
		pq.pop();
		top.second++;
		pq.push(top);
	}
	cout << ceil(pq.top().first / pq.top().second) << '\n';
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}