#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

bool resuelveCaso() {
	int num;
	scanf("%d", &num);
	if (num == 0) return false;
	int digit;
	int menor = -1, mayor = -1, total = 0;
	for (int i = 0; i < num; i++) {
		scanf("%d", &digit);
		if (digit > 6) mayor = i;
		else if (digit <= 4) {
			if (menor == -1) {
				total++;
			}
			else if (mayor > menor) total++;
			menor = i;
		}
	}
	printf("%d\n", total);
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}