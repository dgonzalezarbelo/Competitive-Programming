#include <iostream>

bool resuelveCaso() {
	int n, m;
	std::cin >> n >> m;
	if (n < 0 || m < 0) return false;
	std::cout << n + n + m + m << '\n';
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}