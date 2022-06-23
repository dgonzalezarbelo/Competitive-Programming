#include <iostream>
#include <queue>
#include<vector>
using namespace std;
#pragma warning (disable:4996)

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int maxInt = 2147483647;

void dijkstra(int s, vector<vii> & adjList, vi& dist, int initialDist) {
	dist[s] = initialDist;
	priority_queue<ii, vii, greater<ii>> pq;
	pq.push(ii(0, s));
	while (!pq.empty()) {
		ii front = pq.top();
		pq.pop();
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
	int num;
	if (scanf("%d", &num) == EOF) return false;
	num++;
	vi cargas(num);
	for (int i = 1; i < num; i++) cin >> cargas[i];
	int M, o, f, aux;
	scanf("%d", &M);
	vector<vii> adjList(num);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &o, &f, &aux);
		adjList[o].push_back({ aux + cargas[f], f });
	}
	vi dist(num, maxInt);
	dijkstra(1, adjList, dist, cargas[1]);
	if (dist[num - 1] == maxInt) printf("IMPOSIBLE\n");
	else printf("%d\n", dist[num - 1]);
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}