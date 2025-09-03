#include <iostream>
#include <fstream>

int resolver(int num) {
	if (num == 1) return 4;
	else return 4 * resolver(num / 2) + 4 * num;
}

bool resuelveCaso() {
	int num;
	std::cin >> num;
	if (!std::cin) return false;
	std::cout << resolver(num) << '\n';
}

int main() {
	while (resuelveCaso());
	return 0;
}