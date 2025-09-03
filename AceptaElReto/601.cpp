#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <iomanip>
#include <climits>
#include <cmath>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <algorithm>
#pragma warning (disable : 4996)

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vii> al;
vi dist;

void dijkstra(int s, vector<vii>& adjList, vi& dist) {
	dist.assign(adjList.size(), INT_MAX);
	dist[s] = 0;
	priority_queue<ii, vii, greater<ii>> pq; pq.push(ii(0,
		s));
	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		if (d > dist[u]) continue;
		for (int j = 0; j < adjList[u].size(); j++) {
			ii v = adjList[u][j];
			if (dist[u] + v.first < dist[v.second]) {
				dist[v.second] = dist[u] + v.first;
				pq.push(ii(dist[v.second], v.second));
			}
		}
	}
}

bool resuelveCaso() {
	int n, s, t, p;
	if (scanf("%d %d %d %d", &n, &s, &t, &p) == EOF) return false;
	al.assign(n + 1, vii());
	int a, b, m;
	while (p--) {
		scanf("%d %d %d", &a, &b, &m);
		al[b].push_back({ m,a }); //Le damos la vuelta a las aristas para coger s como origen en vez de destino
	}
	dijkstra(s, al, dist);
	int c = 0;
	for (int i = 1; i < al.size(); i++) {
		if (i != s && dist[i] <= t) c++;
	}
	printf("%d\n", c);
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}