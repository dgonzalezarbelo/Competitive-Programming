#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable : 4996)

vector<int> meses = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool resuelveCaso() {
	int dia, mes;
	scanf("%d.%d", &mes, &dia);
	if (!dia && !mes) return false;
	if (mes > 0 && mes <= 12 && dia > 0 && dia <= meses[mes]) printf("SI\n");
	else printf("NO\n");
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}