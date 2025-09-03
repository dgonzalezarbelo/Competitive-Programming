#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable:4996)

int solve(vector <int> const& v) {
	int max = -1000001;
	int suma = 0;
	int i = 0;
	for (int j = 0; j < 2 * v.size(); j++) {
		i = j % v.size();
		if (suma + v[i] > 0) suma += v[i];
		else suma = 0;
		if (suma > max) max = suma;
	}
	return max;
}

bool resuelveCaso() {
	int num;
	scanf("%d", &num);
	if (!num) return false;
	int digit;
	int max = -1000001, maxIz = -1000001;
	int suma = 0, sumaIz = 0;
	int sol;
	for (int j = 0; j < num; j++) {
		scanf("%d", &digit);
		sumaIz += digit;
		if (suma + digit > 0) suma += digit;
		else suma = 0;
		if (suma > max) max = suma;
		if (sumaIz > maxIz) maxIz = sumaIz;
	}
	if (suma + maxIz > max) sol = suma + maxIz;
	else sol = max;
	printf("%d\n", sol);
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}