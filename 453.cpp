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
	int e;
	scanf("%d", &e);
	if (!e) return false;
	UnionFind uf(e);
	int r;
	scanf("%d", &r);
	int o, d;
	while (r--) {
		scanf("%d %d", &o, &d);
		uf.unionSet(o - 1, d - 1);
	}
	uf.numDisjointSets() == 1 ? printf("TODAS\n") : printf("FALTA ALGUNA\n");
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}