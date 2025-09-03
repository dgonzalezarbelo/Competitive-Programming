#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int resolver(vector<int> const& v) {
	vector <int> aux(v.size(), 1);
	int res = 1;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (v[j] < v[i]) {
				if (aux[j] + 1 > aux[i]) aux[i] = aux[j] + 1;
			}
		}
		if (aux[i] > res) res = aux[i];
	}
	return res;
}

bool resuelveCaso() {
	int num;
	cin >> num;
	if (num == 0) return false;
	vector <int> v(num);
	for (int i = 0; i < num; i++) cin >> v[i];
	cout << resolver(v) << '\n';
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}