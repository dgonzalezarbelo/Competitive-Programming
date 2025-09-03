#include <iostream>
#include <vector>
using namespace std;
bool resuelveCaso() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int num, calles;
	cin >> calles;
	if (!calles) return false;
	cin >> num;
	vector<int> grados(num + 1, 0);
	int a, b;
	while (calles--) {
		cin >> a >> b;
		grados[a]++;
		grados[b]++;
	}
	int impares = 0;
	for (int i = 1; i <= num; i++) {
		if (grados[i] % 2 == 1) impares++;
	}
	if (impares == 0 || impares == 2) printf("SI\n");
	else printf("NO\n");
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}