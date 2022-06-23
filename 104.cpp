#include <iostream>
#include <vector>

struct tSol {
	bool equilibrio;
	unsigned int peso;
};

tSol resolver(std::vector <unsigned int> const& v) {
	if (v[0] != 0 && v[2] != 0) {
		return { (v[0] * v[1] == v[2] * v[3]), v[0] + v[2]};
	}
	else {
		tSol p1, p2;
		if (v[0] == 0) {
			std::vector <unsigned int> l1(4);
			for (int i = 0; i < 4; i++) std::cin >> l1[i];
			p1 = resolver(l1);
		}
		else p1 = { true, v[0] };
		if (v[2] == 0) {
			std::vector <unsigned int> l2(4);
			for (int i = 0; i < 4; i++) std::cin >> l2[i];
			p2 = resolver(l2);
		}
		else p2 = { true, v[2] };
		return { p1.equilibrio && p2.equilibrio && p1.peso * v[1] == p2.peso * v[3], p1.peso + p2.peso};
	}
}

bool resuelveCaso() {
	std::vector <unsigned int> v(4);
	for (int i = 0; i < 4; i++) std::cin >> v[i];
	if (v[0] == 0 && v[1] == 0 && v[2] == 0 && v[3] == 0) return false;
	tSol sol = resolver(v);
	sol.equilibrio ? std::cout << "SI\n" : std::cout << "NO\n";
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}