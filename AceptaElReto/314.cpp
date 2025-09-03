#include <iostream>
#include <vector>
#include <fstream>

/*
{v.size() > 0}
fun resolver(v[0..v.size()) de ent) dev picos, valles: ent
{picos = (#i: 1 <= i < v.size() - 1: v[i] > v[i - 1] && v[i] > v[i + 1]) && valles = (#i: 1 <= i < v.size() - 1: v[i] < v[i - 1] && v[i] < v[i + 1])}

Inv: {picos = (#i: 1 <= i < n: v[i] > v[i - 1] && v[i] > v[i + 1]) && valles = (#i: 1 <= i < n: v[i] < v[i - 1] && v[i] < v[i + 1]) && 1 <= n <= v.size()}

*/

void resolver(std::vector <int> const& v) {
	int picos = 0, valles = 0;
	for (int i = 1; i < v.size() - 1; i++) {
		if (v[i] > v[i - 1] && v[i] > v[i + 1]) picos++;
		else if (v[i] < v[i - 1] && v[i] < v[i + 1]) valles++;
	}
	printf("%d %d\n", picos, valles);
}

void resuelveCaso() {
	int num;
	std::cin >> num;
	std::vector <int> v(num);
	for (int i = 0; i < num; i++) std::cin >> v[i];
	resolver(v);
}

int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}
	return 0;
}