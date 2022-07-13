#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <deque>
#include <numeric>
#include <algorithm>
#pragma warning (disable : 4996)
using namespace std;

vector<list<pair<int, int>>> al;
vector<bool> visited;
bool found;
int target;
int anchura;

void dfs(int a) {
	visited[a] = true;
	if (a == target) {
		found = true;
		return;
	}
	for (auto p : al[a]) {
		if (!visited[p.first] && p.second >= anchura) {
			dfs(p.first);
			if (found) break;
		}
	}
}

bool resuelveCaso() {
	int v;
	cin >> v;
	if (!cin) return false;
	int e, k;
	cin >> e;
	int a, b, c;
	al.assign(v + 1, list<pair<int, int>>());
	while (e--) {
		cin >> a >> b >> c;
		al[a].push_back({ b, c });
		al[b].push_back({ a, c });
	}
	cin >> k;
	while (k--) {
		visited.assign(v + 1, false);
		found = false;
		cin >> a >> target >> anchura;
		dfs(a);
		found ? cout << "SI\n" : cout << "NO\n";
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}