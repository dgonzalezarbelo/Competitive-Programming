#include <iostream>
using namespace std;
#pragma warning(disable:4996)

bool resuelveCaso() {
	int abuelo, iglesia;
	scanf("%d %d", &abuelo, &iglesia);
	if (abuelo == 0 && iglesia == 0) return false;
	abuelo >= iglesia ? printf("CUERDO\n") : printf("SENIL\n");
	return true;
}


int main() {
	while (resuelveCaso());
	return 0;
}