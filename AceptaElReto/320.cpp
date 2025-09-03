#include <iostream>
#include <fstream>
#include <vector>

/*
{v.size() >  0 && pesoMax > 0}
fun resolver(v[0..v.size()) de ent, pesoMax: ent) dev longMax: ent
{longMax = (max l: l > 0: (existe i: 0 <= i < v.size(): valido(v, i - l, i, pesoMax)))}
valido(v, ini, fin, pesoMax) = (#j: 0 <= ini <= j <= fin < v.size(): v[j] >= pesoMax) <= 5

Inv: {longMax = (max l: l > 0: (existe i: 0 <= i < n: valido(v, i - l, i, pesoMax))) && 0 <= n <= v.size() &&
 longActual = (max l: l > 0 && valido(v, n - l, n, pesoMax): l) && enPie = (#j: n - longActual <= j <= n: v[j] >= pesoMax)}

*/

int resolver(std::vector <int> const& v, int pesoMax) {
	int enPie = 0, longActual = 0, longMax = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] < pesoMax) longActual++;
		else {
			if (enPie < 5) {
				longActual++;
				enPie++;
			}
			else {
				while (enPie == 5 && longActual > 0 && i >= longActual) {
					if (v[i - longActual] >= pesoMax) enPie--;
					longActual--;
				}
				longActual++;
				enPie++;
			}
		}
		if (longActual > longMax) longMax = longActual;
	}
	return longMax;
}

void resuelveCaso() {
	int pesoMax, num;
	std::cin >> pesoMax >> num;
	std::vector <int> v(num);
	for (int i = 0; i < num; i++) std::cin >> v[i];
	std::cout << resolver(v, pesoMax) << '\n';

}

int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; i++) resuelveCaso();
	return 0;
}