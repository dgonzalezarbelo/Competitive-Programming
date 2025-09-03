#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
#pragma warning (disable:4996)

bool resuelveCaso() {
	int td, ta, dd, da, n;
	if (scanf("%d %d %d %d %d", &td, &ta, &dd, &da, &n) == EOF) return false;
	priority_queue<int, vector<int>, less<int>> pd, pa;
	int aux;
	while (n--) {
		for (int i = 0; i < min(td, dd); i++) {
			scanf("%d", &aux);
			pd.push(aux);
		}
		for (int i = 0; i < min(ta, da); i++) {
			scanf("%d", &aux);
			pa.push(aux);
		}
		while (!pd.empty() && !pa.empty()) {
			if (pd.top() >= pa.top()) ta--;
			else td--;
			pd.pop();
			pa.pop();
		}
		while (!pd.empty()) pd.pop();
		while (!pa.empty()) pa.pop();
	}
	printf("%d %d\n", td, ta);
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}