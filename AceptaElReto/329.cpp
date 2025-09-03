#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

typedef pair<int, int> ii;

struct comparaPair {
	bool operator () (ii p1, ii p2) {
		return p1.second < p2.second || (p1.second == p2.second && p1.first < p2.first);
	}
};

int solve(vector<ii> const& v) {
	vector<int> w;
	w.push_back(v[0].second);
	for (int i = 1; i < v.size(); i++) {
		if (v[i].first >= w[w.size() - 1]) w.push_back(v[i].second);		
	}
	return w.size();
}

bool resuelveCaso() {
	int num;
	scanf("%d", &num);
	if (!num) return false;
	vector<ii> v(num);
	for (ii& p : v) scanf("%d %d", &p.first, &p.second);
	sort(v.begin(), v.end(), comparaPair());
	printf("%d\n", solve(v));
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}