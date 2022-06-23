#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable:4996)

bool resuelveCaso() {
	int num, peso;
	scanf("%d %d", &num, &peso);
	if (num == 0 && peso == 0) return false;
	vector <int> v(num);
	for (int& x : v) scanf("%d", &x);
	sort(v.begin(), v.end());
	long long int parejas = 0;
	int i = 0, j = v.size() - 1;
	while (i < j) {
		if (v[i] + v[j] <= peso) {
			parejas += j - i;
			i++;
		}
		else j--;
	}
	printf("%lld\n", parejas);
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}