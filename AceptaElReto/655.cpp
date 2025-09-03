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
#include <climits>
#pragma warning (disable : 4996)
using namespace std;

using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<pair<int, int>>;
using lli = long long int;
using vlli = vector<long long int>;

vector<vii> al;	//{Peso, destino}
vector<bool> raices;
vector<bool> hojas;
vector<int> dist;
vector<int> hijos;

int v, e;

void dfs(int a) {
	if (a == v + 1) return;
	int d;
	for (auto p : al[a]) {
		if(dist[p.second] == -1) dfs(p.second);
		d = dist[p.second];
		if (d + p.first > dist[a]) {
			dist[a] = d + p.first;
			hijos[a] = p.second;
		}
		else if (d + p.first == dist[a] && hijos[a] > p.second) {
			dist[a] = d + p.first;
			hijos[a] = p.second;
		}
	}
}

bool resuelveCaso() {
	scanf("%d %d", &v, &e);
	if (!v && !e) return false;
	al.assign(v + 2, vii());
	raices.assign(v + 2, true);
	hojas.assign(v + 2, true);
	hijos.assign(v + 2, -1);
	dist.assign(v + 2, -1);
	dist[v + 1] = 0;
	while (e--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		al[a].push_back({ c, b });
		raices[b] = false;
		hojas[a] = false;
	}
	for (int i = 1; i <= v; i++) {
		if (raices[i]) al[0].push_back({ 0, i });
		if (hojas[i]) al[i].push_back({ 0, v + 1 });
	}
	dfs(0);
	printf("%d\n", dist[0]);
	int p = hijos[0];
	bool primero = true;
	while (p != v + 1) {
		if (!primero) printf(" ");
		primero = false;
		printf("%d", p);
		p = hijos[p];
	}
	printf("\n");
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}