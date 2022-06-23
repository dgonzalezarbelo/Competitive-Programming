#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#pragma warning (disable:4996)

int pot = 10e9;

bool resuelveCaso() {
	int num;
	scanf("%d", &num);
	if (!num) return false;
	vector<int> v(num);
	int digit, sumaIz = 0, sumaD = 0;
	for (int i = 0; i < num; i++) {
		scanf("%d", &digit);
		v[i] = digit;
		sumaIz += digit;
	}
	int index = num, minDist = abs(sumaIz);
	for (int i = num - 1; i >= 0; i--) {
		sumaIz -= v[i];
		sumaD += v[i];
		if (abs(sumaIz - sumaD) <= minDist) {
			minDist = abs(sumaIz - sumaD);
			index = i;
		}
	}
	printf("%d\n", index);
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}