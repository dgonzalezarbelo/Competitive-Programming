#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
#pragma warning (disable:4996)

bool resuelveCaso() {
	int alto, ancho;
	cin >> ancho >> alto;
	if (ancho == 0 && alto == 0) return false;
	vector<vector<char>> v(alto, vector<char>(ancho));
	for (int i = 0; i < alto; i++) {
		for (int j = 0; j < ancho; j++) {
			cin >> v[i][j];
		}
	}
	char uno = 'p', dos = 'p';
	bool correcto = true;
	int i = 0, j = 0, a = 0, b = 0;
	vector<vector<char>> caracteres1(alto / 8, vector<char>(ancho / 8, 'p'));
	vector<vector<char>> caracteres2(alto / 8, vector<char>(ancho / 8, 'p'));
	while (i < alto / 8 && correcto) {
		j = 0;
		a = 0;
		b = 0;
		while (j < ancho / 8 && correcto) {
			a = 0;
			b = 0;
			while (a < 8 && correcto) {
				b = 0;
				while (b < 8 && correcto) {
					if (v[8 * i + a][8 * j + b] != caracteres1[i][j]) {
						if (caracteres1[i][j] == 'p') caracteres1[i][j] = v[8 * i + a][8 * j + b];
						else if (v[8 * i + a][8 * j + b] != caracteres2[i][j]) {
							if (caracteres2[i][j] == 'p') caracteres2[i][j] = v[8 * i + a][8 * j + b];
							else correcto = false;
						}
					}
					b++;
				}
				a++;
			}
			j++;
		}
		i++;
	}
	if (correcto) cout << "SI\n";
	else cout << "NO\n";
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}