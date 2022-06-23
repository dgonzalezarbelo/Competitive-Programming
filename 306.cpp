#include <iostream>
#include <vector>
#include <fstream>

using tMatriz = std::vector <std::vector<int>>;

const int k = 46337;

tMatriz resolver(int n) {
	if (n == 0) return { {0, 0}, {0, 0} };
	else if (n == 1) return { {0, 1}, {1, 1} };
	else {
		if (n % 2 == 0) {
			tMatriz mitad = resolver(n / 2);
			tMatriz res;
			res.resize(2, std::vector<int>(2));
			res[0][0] = ((mitad[0][0] * mitad[0][0]) % k + (mitad[0][1] * mitad[1][0]) % k) % k;
			res[1][0] = ((mitad[1][0] * mitad[0][0]) % k + (mitad[1][0] * mitad[1][1]) % k) % k;
			res[0][1] = ((mitad[0][0] * mitad[0][1]) % k + (mitad[0][1] * mitad[1][1]) % k) % k;
			res[1][1] = ((mitad[1][0] * mitad[0][1]) % k + (mitad[1][1] * mitad[1][1]) % k) % k;
			return res;
		}
		else {
			tMatriz mitad = resolver((n - 1) / 2);
			tMatriz res;
			res.resize(2, std::vector<int>(2));

			res[0][0] = ((mitad[0][0] * mitad[0][0]) % k + (mitad[0][1] * mitad[1][0]) % k) % k;
			res[1][0] = ((mitad[1][0] * mitad[0][0]) % k + (mitad[1][0] * mitad[1][1]) % k) % k;
			res[0][1] = ((mitad[0][0] * mitad[0][1]) % k + (mitad[0][1] * mitad[1][1]) % k) % k;
			res[1][1] = ((mitad[1][0] * mitad[0][1]) % k + (mitad[1][1] * mitad[1][1]) % k) % k;

			tMatriz res2;
			res2.resize(2, std::vector<int>(2));

			res2[0][0] = res[0][1];
			res2[0][1] = res[1][1];
			res2[1][0] = res[1][1];
			res2[1][1] = (res[0][1] + res[1][1]) % k;
			return res2;
		}
	}
}

bool resuelveCaso() {
	int n;
	std::cin >> n;
	if (n == 0) return false;
	tMatriz mat = resolver(n);
	std::cout << mat[1][0] << '\n';
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}