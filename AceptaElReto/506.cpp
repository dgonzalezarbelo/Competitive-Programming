#include <iostream>
#include <fstream>
#pragma warning (disable:4996)

int main() {
	int num, a, b;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d / %d", &a, &b);
		a >= b ? printf("BIEN\n") : printf("MAL\n");
	}
	return 0;
}