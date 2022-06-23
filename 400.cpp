#include <iostream>
#include <vector>
#include <string>
using namespace std;
#pragma warning(disable :4996)

bool resuelveCaso() {
	string cad;
	getline(cin, cad);
	if (!cin) return false;
	vector<int> v;
	for (int i = 0; i < cad.size(); i++) {
		if (cad[i] == 'X') v.push_back(i);
	}
	int max = v[0] - 1;
	if (max < 0) max = 0;
	for (int i = 1; i < v.size(); i++) {
		if ((v[i] - v[i - 1] - 2) / 2 > max) max = (v[i] - v[i - 1] - 2) / 2;
	}
	if (int(cad.size() - v[v.size() - 1] - 2) > max) max = (cad.size() - v[v.size() - 1] - 2);
	printf("%d\n", max);
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}