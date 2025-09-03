#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable:4996)

bool comprobar(vector<int> const& v, vector<int> const& patron) {
	int j = 0;
	for (int i = 1; i < v.size(); i++) {
		if (v[i] - v[i - 1] != patron[j]) return false;
		j = (j + 1) % patron.size();
	}
	return true;
}

bool resuelveCaso() {
	int num;
	scanf("%d", &num);
	if (!num) return false;
	vector<int> v(num);
	for (int& x : v) scanf("%d", &x);
	vector<int> patron;
	patron.push_back(v[1] - v[0]);
	for (int i = 2; i < num; i++) {
		if (v[i] - v[i - 1] == patron[0]) {
			if (comprobar(v, patron)) break;
			else patron.push_back(v[i] - v[i - 1]);
		}
		else patron.push_back(v[i] - v[i - 1]);
	}
	printf("%d\n", v[num - 1] + patron[(num - 1) % patron.size()]);
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}