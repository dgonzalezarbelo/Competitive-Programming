#include <iostream>
#include <vector>

int calcularLong(int pos, std::vector <int> const& v, std::vector <bool> & calculados, int posOriginal, int longitud) {
	if (v[pos] == posOriginal) {
		calculados[pos] = true;
		return longitud;
	}
	else {
		calculados[pos] = true;
		return calcularLong(v[pos], v, calculados, posOriginal, ++longitud);
	}
}

int mcd(int a, int b) {
	if (b == 0) return a;
	else return mcd(b, a % b);
}

bool resuelveCaso() {
	int num;
	std::cin >> num;
	if (num == 0) return false;
	std::vector <int> v(num);
	for (int i = 0; i < num; i++) {
		std::cin >> v[i];
		v[i]--;
	} 
	std::vector <bool> calculados(num, false);
	std::vector <int> longitudes;
	for (int i = 0; i < num; i++) {
		if (!calculados[i]) longitudes.push_back(calcularLong(i, v, calculados, i, 1));
	}
	std::vector <int> mcm(longitudes.size() - 1);
	if (longitudes.size() == 1) {
		printf("%d\n", longitudes[0]);
		return true;
	}
	mcm[0] = longitudes[0] * longitudes[1] / mcd(longitudes[0], longitudes[1]);
	for (int i = 1; i < mcm.size(); i++) {
		mcm[i] = mcm[i - 1] * longitudes[i + 1] / mcd(mcm[i - 1], longitudes[i + 1]);
	}
	printf("%d\n", mcm[mcm.size() - 1]);
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}