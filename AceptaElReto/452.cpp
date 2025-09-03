#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#pragma warning (disable :4996)
using namespace std;

bool resuelveCaso() {
	int num;
	scanf("%d", &num);
	if (!num) return false;
	vector<bool> m(2001, false);
	vector<int> v(num);
	for (int& x : v) scanf("%d", &x);
	for (int i = 0; i < num; i++) {
		for (int j = i + 1; j < num; j++) {
			m[max(v[i], v[j]) - min(v[i], v[j])] = true;
		}
	}
	bool primero = true;
	for (int i = 1; i < m.size(); i++) {
		if (m[i]) {
			if (primero) {
				primero = false;
				printf("%d", i);
			}
			else printf(" %d", i);
		}
	}
	printf("\n");
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}