#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#pragma warning (disable : 4996)

typedef pair<int, int> ii;

void resuelveCaso() {
	int ancho, alto;
	scanf("%d %d", &ancho, &alto);
	vector<vector<char>> mat(alto, vector<char>(ancho, true));
	vector<vector<bool>> disponible(alto, vector<bool>(ancho, true));
	ii E, P;
	char aux;
	for (int i = 0; i < alto; i++) {
		for (int j = 0; j < ancho; j++) {
			cin >> aux;
			mat[i][j] = aux;
		}
	}
	for (int i = 0; i < alto; i++) {
		for (int j = 0; j < ancho; j++) {
			aux = mat[i][j];
			if (isdigit(aux)) {
				int l = int(aux) - '0';
				for (int a = 1; a <= l && i + a < alto; a++) {
					if (mat[i + a][j] == '#') break;
					disponible[i + a][j] = false;
				}
				for (int a = -1; a >= -l && i + a >= 0; a--) {
					if (mat[i + a][j] == '#') break;
					disponible[i + a][j] = false;
				}
				for (int b = 1; b <= l && j + b < ancho; b++) {
					if (mat[i][j + b] == '#') break;
					disponible[i][j + b] = false;
				}
				for (int b = -1; b >= -l && j + b >= 0; b--) {
					if (mat[i][j + b] == '#') break;
					disponible[i][j + b] = false;
				}
				disponible[i][j] = false;
			}
			else if (aux == '#') {
				disponible[i][j] = false;
			}
			else {
				if (aux == 'E') E = { i, j };
				else if (aux == 'P') P = { i, j };
			}
		}
	}
	if (!disponible[E.first][E.second]) {
		printf("NO\n");
		return;
	}
	bool found = false;
	queue<ii> q;
	vector<vector<int>> dist(alto, vector<int>(ancho, -1));
	ii pos;
	dist[E.first][E.second] = 0;
	q.push(E);
	ii newPos;
	while (!found && !q.empty()) {
		pos = q.front();
		q.pop();
		if (pos.first - 1 >= 0 && dist[pos.first - 1][pos.second] == -1 && disponible[pos.first - 1][pos.second]) {
			newPos = { pos.first - 1, pos.second };
			q.push(newPos);
			dist[pos.first - 1][pos.second] = dist[pos.first][pos.second] + 1;
			if (newPos == P) {
				found = true;
				break;
			}
		}
		if (pos.first + 1 < alto && dist[pos.first + 1][pos.second] == -1 && disponible[pos.first + 1][pos.second]) {
			newPos = { pos.first + 1, pos.second };
			q.push(newPos);
			dist[pos.first + 1][pos.second] = dist[pos.first][pos.second] + 1;
			if (newPos == P) {
				found = true;
				break;
			}
		}
		if (pos.second - 1 >= 0 && dist[pos.first][pos.second - 1] == -1 && disponible[pos.first][pos.second - 1]) {
			newPos = { pos.first, pos.second - 1 };
			q.push(newPos);
			dist[pos.first][pos.second - 1] = dist[pos.first][pos.second] + 1;
			if (newPos == P) {
				found = true;
				break;
			}
		}
		if (pos.second + 1 < ancho && dist[pos.first][pos.second + 1] == -1 && disponible[pos.first][pos.second + 1]) {
			newPos = { pos.first, pos.second + 1 };
			q.push(newPos);
			dist[pos.first][pos.second + 1] = dist[pos.first][pos.second] + 1;
			if (newPos == P) {
				found = true;
				break;
			}
		}
	}
	if (found) printf("%d\n", dist[P.first][P.second]);
	else printf("NO\n");
}

int main() {
	int num;
	scanf("%d", &num);
	while (num--) resuelveCaso();
	return 0;
}