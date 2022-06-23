#include <iostream>
#include <fstream>

/*
{1 <= x <= 100 && 0 <= n <= 10000000}
fun resolver(x, n: ent) dev suma: ent
{suma = sumatorio(x, n)}
sumatorio(x, n) = (sumatorio j: 0 <= j <= n: x^i)

Inv: suma = sumatorio(x, i) && 0 <= i <= n && pot = x^i
*/

int resolver(int x, int n) {
	int suma = 0, pot = 1, i = 0;
	while (i < n + 1) {
		suma += pot;
		suma = suma % 1000007;
		pot *= x;
		pot = pot % 1000007;
		i++;
	}
	return suma;
}

bool resuelveCaso() {
	int x, n;
	std::cin >> x >> n;
	if (!std::cin) return false;
	printf("%d\n", resolver(x, n));
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}