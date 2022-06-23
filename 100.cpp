#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable:4996)
void resuelveCaso() {
	int num;
	scanf("%d", &num);
	if (num % 1111 == 0) printf("8\n");
	else {
		vector<int> v(4);
		int iteraciones = 0;
		while (num != 6174) {
			v[0] = num / 1000;
			v[1] = (num / 100) % 10;
			v[2] = (num / 10) % 10;
			v[3] = num % 10;
			sort(v.begin(), v.end());
			num = 1000 * v[3] + 100 * v[2] + 10 * v[1] + v[0] - 1000 * v[0] - 100 * v[1] - 10 * v[2] - v[3];
			iteraciones++;
		}
		printf("%d\n", iteraciones);
	}
}

int main() {
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) resuelveCaso();
	return 0;
}