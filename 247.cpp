#include <iostream>
#pragma warning(disable:4996)
using namespace std;
bool resuelveCaso() {
	int num;
	scanf("%d", &num);
	if (num == 0) return false;
	int a, b;
	scanf("%d", &a);
	bool bien = true;
	for (int i = 1; i < num; i++) {
		scanf("%d", &b);
		if (bien && a >= b) {
			bien = false;
		}
		a = b;
	}
	if (bien) printf("SI\n");
	else printf("NO\n");
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}