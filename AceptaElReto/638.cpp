#include <iostream>
#pragma warning (disable:4996)
using namespace std;

void resuelveCaso() {
	int c, n;
	scanf("%d %d", &c, &n);
	int menor, mayor;
	menor = n / (c - 1);
	mayor = menor;
	if (n % (c - 1) == 0) {
		menor--;
	}
	printf("%d %d\n", menor + n, mayor + n);
}

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		resuelveCaso();
	}
	return 0;
}