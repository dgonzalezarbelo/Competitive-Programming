#include <iostream>
#include <vector>

int resolver(std::vector <int> const& v) {
	int max = v[v.size() - 1];
	int cont = 1;
	for (int i = v.size() - 2; i >= 0; i--) {
		if (v[i] > max) {
			max = v[i];
			cont++;
		}
	}
	return cont;
}

bool resuelveCaso() {
	int num;
	std::cin >> num;
	if (num == 0) return false;

	std::vector <int> v(num);
	for (int i = 0; i < num; i++) std::cin >> v[i];
	if (num == 1) std::cout << "1\n";
	else std::cout << resolver(v) << '\n';
	return true;

}

int main() {
	while (resuelveCaso());
	return 0;
}