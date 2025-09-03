#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable:4996)

int solve(int N, int M) {
	return ((N + M) * (N + M + 1) / 2) + N + 1;
}

void resuelveCaso() {
	int N, M;
	scanf("%d %d", &N, &M);
	if (N + M == 0) printf("1\n");
	else printf("%d\n", solve(N, M));
}

int main() {
	int num;
	scanf("%d", &num);
	while (num--) resuelveCaso();
	return 0;
}