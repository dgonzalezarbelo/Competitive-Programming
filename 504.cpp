#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
using namespace std;

using ii = pair<int, int>;
vector<vector<ii>> al;
vector<int> depth;
vector<int> dist;

void dijkstra(int o) {
	dist.assign(al.size(), INT_MAX);
	dist[o] = 0;
	depth.assign(al.size(), INT_MAX);
	depth[o] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({ 0, o });
	while (!pq.empty()) {
		ii front = pq.top();
		pq.pop();
		int d = front.first, u = front.second;
		if (d > dist[u]) continue;
		for (ii p : al[u]) {
			if (dist[u] + p.first < dist[p.second]) {
				dist[p.second] = dist[u] + p.first;
				depth[p.second] = depth[u] + 1;
				pq.push({ dist[p.second], p.second });
			}
			else if (dist[u] + p.first == dist[p.second] && depth[p.second] > depth[u] + 1) {
				dist[p.second] = dist[u] + p.first;
				depth[p.second] = depth[u] + 1;
				pq.push({ dist[p.second], p.second });
			}
		}
	}
}

vector<bool> visited;

int bfs(int o, int d) {
	visited.assign(al.size(), false);
	visited[o] = true;
	queue<ii> q;
	q.push({ 0,o });
	while (!q.empty()) {
		ii f = q.front();
		q.pop();
		if (f.second == d) return f.first;
		for (ii b : al[f.second]) {
			if (!visited[b.second]) {
				visited[b.second] = true;
				q.push({ f.first + 1, b.second });
			}
		}
	}
	return -1;
}

bool resuelveCaso() {
	int n, c;
	cin >> n >> c;
	if (!cin) return false;
	al.assign(n, vector<ii>());
	while (c--) {
		int a, b, p;
		cin >> a >> b >> p;
		a--;
		b--;
		al[a].push_back({ p,b });
		al[b].push_back({ p,a });
	}
	int k;
	cin >> k;
	while (k--) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		int m = bfs(a, b);
		if (m == -1) cout << "SIN CAMINO\n";
		else {
			dijkstra(a);
			cout << dist[b] << ' ';
			if (depth[b] == m) cout << "SI\n";
			else cout << "NO\n";
		}
	}
	cout << "----\n";
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}