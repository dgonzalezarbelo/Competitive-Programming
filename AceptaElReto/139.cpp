#include <iostream>
#include <set>
using namespace std;

int cubos(int num) {
	if (num < 10) return num * num * num;
	else return cubos(num / 10) + (num % 10) * (num % 10) * (num % 10);
}

bool resuelveCaso() {
	int num;
	cin >> num;
	if (num == 0) return false;
	set <int> conjunto;
	conjunto.insert(num);
	cout << num << " -";
	while (num != 1) {
		num = cubos(num);
		cout << ' ' << num << " -";
		if(!conjunto.insert(num).second) break;
	}
	if (num == 1) cout << "> cubifinito.\n";
	else cout << "> no cubifinito.\n";
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}