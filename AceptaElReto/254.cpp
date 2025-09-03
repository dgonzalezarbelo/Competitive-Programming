#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable:4996)

bool resuelveCaso() {
	int num;
	scanf("%d", &num);
	if (!num) return false;
	vector <int> v(num), w(num);
	for (int& x : v) scanf("%d", &x);
	for (int& x : w) scanf("%d", &x);
	sort(v.begin(), v.end());
	sort(w.begin(), w.end());
	int total = 0;
	for (int i = 0; i < num; i++) {
		total += abs(v[i] - w[i]);
	}
	printf("%d\n", total);
	return true;

}

int main() {
	while (resuelveCaso());
	return 0;
}