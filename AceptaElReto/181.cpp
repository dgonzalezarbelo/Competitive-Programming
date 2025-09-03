#include <iostream>
#include <vector>
using namespace std;
#pragma warning(disable:4996)

vector<vector<int>> mat;
vector<vector<bool>> transitables;

int solve(int x, int y) {
	int sol = 0;
	if (mat[x][y] == -1) {
		if (x == 0 && y == mat.size() - 1) {
			return mat[x][y] = 1;
		}
		else {
			if (x - 1 >= 0 && transitables[x - 1][y]) {
				sol += solve(x - 1, y);
			}
			if (y + 1 < mat.size() && transitables[x][y + 1]) {
				sol += solve(x, y + 1);
			}
			return (mat[x][y] = sol);
		}
	}
	else return mat[x][y];
}

bool resuelveCaso() {
	int num;
	scanf("%d", &num);
	if (!num) return false;
	mat.assign(num, vector<int>(num, -1));
	transitables.resize(num, vector<bool> (num));
	char aux;
	for (int i = 0; i < num; i++) {
		scanf("\n");
		for (int j = 0; j < num; j++) {
			scanf("%c", &aux);
			if (aux == 'X') transitables[i][j] = false;
			else transitables[i][j] = true;
		}
	}
	printf("%d\n", solve(num - 1, 0));
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}