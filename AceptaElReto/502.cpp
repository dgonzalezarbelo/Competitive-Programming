#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;

bool resuelveCaso() {
	int num;
	if (scanf("%d", &num) == EOF) return false;
	vector <int> torres;
	int elem;
	scanf("%d", &elem);
	torres.push_back(elem);
	int pos;
	for (int i = 1; i < num; i++) {
		scanf("%d", &elem);
		auto it = upper_bound(torres.begin(), torres.end(), elem);
		pos = it - torres.begin();
		if (pos == torres.size()) torres.push_back(elem);
		else torres[pos] = elem;
	}
	printf("%d\n", torres.size());
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}