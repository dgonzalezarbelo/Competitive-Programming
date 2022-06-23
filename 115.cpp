#include <iostream>
using namespace std;
#pragma warning (disable:4996)
bool resuelveCaso() {
	long long int num;
	scanf("%lld", &num);
	if (num == 0) return false;
	long long int cuadrado = num * num;
	long long int a, b;
	long long int pot = 10;
	while (pot < cuadrado) {
		pot *= 10;
	} 
	bool kaprekar = false;
	while (pot > 0 && !kaprekar) {
		a = cuadrado / pot;
		b = cuadrado % pot;
		if (a + b == num && b != 0) kaprekar = true;
		pot /= 10;
	}
	kaprekar ? printf("SI\n") : printf("NO\n");
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}