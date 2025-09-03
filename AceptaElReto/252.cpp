#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool resuelveCaso() {
	string cad;
	getline(cin, cad);
	if (cad == "XXX") return false;
	vector <char> v;
	for (int i = 0; i < cad.size(); i++) {
		if (isalpha(cad[i])) v.push_back(tolower(cad[i]));
	}
	bool palindromo = true;
	int i = 0;
	while (i < v.size() / 2 && palindromo) {
		if (v[i] != v[v.size() - 1 - i]) palindromo = false;
		i++;
	}
	palindromo ? printf("SI\n") : printf("NO\n");
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}