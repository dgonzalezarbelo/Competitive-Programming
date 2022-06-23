#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

class UnionFind {
private:
	vector<int> p, rank;
	int numSets;
public:
	UnionFind(int N) {
		rank.assign(N, 0);
		p.assign(N, 0);
		for (int i = 0; i < N; ++i) p[i] = i;
		numSets = N;
	}
	int findSet(int i) {
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}
	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) p[y] = x;
			else {
				p[x] = y;
				if (rank[x] == rank[y]) ++rank[y];
			}
			--numSets;
		}
	}
	int numDisjointSets() {
		return numSets;
	}
	int sizeOfSet(int i) {
		int res = 0;
		for (int j = 0; j < p.size(); ++j) {
			if (isSameSet(i, j)) ++res;
		}
		return res;
	}
};

bool resuelveCaso() {
	int N, M, K, n;
	if (scanf("%d %d %d %d", &N, &M, &K, &n) == EOF) return false;
	vector <pair <int, int>> v(n + 2);
	vector <vector <bool>> mat((N + 1), vector <bool>(M + 1, false));
	v[0] = { 0,0 };
	v[n + 1] = { N, M };
	mat[0][0] = true;
	mat[N][M] = true;
	for (int i = 1; i < n + 1; i++) {
		cin >> v[i].first >> v[i].second;
	}
	UnionFind uf((N + 1) * (M + 1));
	bool posible = false;
	int i = n + 1;
	int a, b;
	while (!posible && i >= 0) {
		mat[v[i].first][v[i].second] = true;
		a = v[i].first - K;
		while (a <= v[i].first + K) {
			b = v[i].second - K;
			while (b <= v[i].second + K) {
				if (a >= 0 && a < mat.size() && b >= 0 && b < mat[0].size() && mat[a][b] && (v[i].first - a) * (v[i].first - a) + (v[i].second - b) * (v[i].second - b) <= K * K) {
					uf.unionSet(a * (M + 1) + b, v[i].first * (M + 1) + v[i].second);
				}
				b++;
			}
			a++;
		}
		if (uf.isSameSet(0, (N + 1) * (M + 1) - 1)) {
			posible = true;
			cout << v[i].first << ' ' << v[i].second << '\n';
		}
		i--;
	}
	if (!posible) cout << "NUNCA SE PUDO\n";
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}