#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)
typedef pair<int, int> ii;

int resolver(vector <ii> const& charlas) {
	int usados = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < charlas.size(); i++) {
		while (!pq.empty() && pq.top() <= charlas[i].first) pq.pop();
		pq.push(charlas[i].second);
		if (pq.size() > usados) usados = pq.size();
	}
	return usados;
}

bool resuelveCaso() {
	int num;
	if (scanf("%d", &num) == EOF) return false;
	vector<ii> charlas(num);
	for (ii& x : charlas) scanf("%d %d", &x.first, &x.second);
	sort(charlas.begin(), charlas.end());
	printf("%d\n", resolver(charlas) - 1);
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}