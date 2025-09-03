#include <iostream>
#include <string>
#pragma warning (disable : 4996)

using namespace std;

bool resuelveCaso() {
	string n;
	getline(cin, n);
	if (!cin) return false;
	for (int i = 0; i < n.size(); i++) {
		if (i) cout << 0;
		cout << n[i];
	}
	cout << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}