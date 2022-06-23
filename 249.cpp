#include <iostream>
#include <vector>
#pragma warning (disable:4996)
using namespace std;

void resuelveCaso() {
	int maxBurros, alforjas;
	scanf("%d %d", &maxBurros, &alforjas);
	vector <bool> v(20002, false);
	int burros = 0, num;
	for (int i = 0; i < alforjas; i++) {
		scanf("%d", &num);
		if (!v[num]) v[num] = true;
		else {
			v[num] = false;
			if(burros < maxBurros) burros++;
		}
	}
	printf("%d\n", burros);
}

int main() {
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) resuelveCaso();
	return 0;
}