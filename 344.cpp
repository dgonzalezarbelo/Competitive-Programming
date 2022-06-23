#include <iostream>
#include <string>
using namespace std;
#pragma warning (disable:4996)

void resuelveCaso() {
	int num;
	scanf("%d", &num);
	string aux;
	int M = 0, H = 0;
	for (int i = 0; i < num; i++) {
		cin >> aux;
		if (aux == "HH") H += 2;
		else if (aux == "MM") M += 2;
	}
	H == M ? printf("POSIBLE\n") : printf("IMPOSIBLE\n");
}

int main() {
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) resuelveCaso();
	return 0;
}