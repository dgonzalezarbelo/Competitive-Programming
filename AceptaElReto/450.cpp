#include <iostream>
#include <vector>
#pragma warning (disable : 4996)

int resolver(std::vector <int> const& codes, std::vector <int> const& v) {
	int index = 0;
	int i = 0;
	int first = -1;
	int last = -1;
	while (index < codes.size() && i < v.size()) {
		if (v[i] == codes[index]) {
			if (first == -1) first = i;
			if (index == codes.size() - 1) last = i;
			index++;
		}
		i++;
	}
	return last - first + 1;
}

bool resuelveCaso() {
	int numCodes, num;
	if(scanf("%d %d", &numCodes, &num) == EOF) return false;
	std::vector <int> codes(numCodes);
	std::vector <int> v(num);
	for (int i = 0; i < numCodes; i++) {
		std::cin >> codes[i];
	}
	for (int i = 0; i < num; i++) {
		std::cin >> v[i];
	}
	printf("%d\n", resolver(codes, v));
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}