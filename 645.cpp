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

const int MAX_V = 1001, MAX_E = 10001;
int root[MAX_V];
int nodes, edges;
pair <long long, pair<int, int> > p[MAX_E];
int pc;

int parent(int a)                                                       //find the parent of the given node
{
    while (root[a] != a)
    {
        root[a] = root[root[a]];
        a = root[a];
    }
    return a;
}

void union_find(int a, int b)                                         //check if the given two vertices are in the same “union” or not
{
    int d = parent(a);
    int e = parent(b);
    root[d] = root[e];
}

long long kruskal()
{
    int a, b;
    long long cost, minCost = 0;
    for (int i = 0; i < edges; ++i)
    {
        a = p[i].second.first;
        b = p[i].second.second;
        cost = p[i].first;
        if (parent(a) != parent(b))                                  //only select edge if it does not create a cycle (ie the two nodes forming it have different root nodes)
        {
            minCost += cost;
            union_find(a, b);
        }
    }
    return minCost;
}

vector<bool> visited;
vector<list<int>> al;

void dfs(int a) {
    visited[a] = true;
    for (int b : al[a])
        if(!visited[b]) dfs(b);
}

bool resuelveCaso() {
	cin >> nodes;
	if (!cin) return false;
    cin >> edges;
    visited.assign(nodes + 1, false);
    al.assign(nodes + 1, list<int>());
    pc = 0;
	int a, b, d;
    for (int i = 0; i < MAX_V; ++i) {
        root[i] = i;
    }
    for (int i = 0; i < edges; i++) {
        cin >> a >> b >> d;
        p[pc++] = { d, {a, b} };
        al[a].push_back(b);
        al[b].push_back(a);
    }
    int count = 0;
    for (int i = 1; i <= nodes; i++) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
        if (count > 1) break;
    }
    if (count > 1) cout << "No hay puentes suficientes\n";
    else {
        sort(p, p + pc);
        int sol = kruskal();
        cout << sol << '\n';
    }
	return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (resuelveCaso());
	return 0;
}