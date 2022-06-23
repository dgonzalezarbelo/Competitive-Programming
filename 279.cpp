#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <climits>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;

#pragma warning (disable : 4996)

vector<int> marks;

bool check(vector<list<int>> const& AL, int start) {
    bool bipartite = true;
    queue<int> q;
    q.push(start);
    marks[start] = 0;
    while (!q.empty() && bipartite) {
        int current = q.front();
        q.pop();
        for(int i : AL[current]) {
            if(marks[i] == -1) {
                q.push(i);
                marks[i] = 1 - marks[current];
            }
            else if(marks[i] == marks[current]) {
                bipartite = false;
                break;
            }
        }
    }
    return bipartite;
}

bool solveCase() {
    int V, E;
    cin >> V;
    if(!cin) return false;
    scanf("%d", &E);
    vector<list<int>> AL(V);
    int a, b;
    for(int i = 0; i < E; i++) {
        scanf("%d %d", &a, &b);
        AL[a].push_back(b);
        AL[b].push_back(a);
    }
    bool bipartite = true;
    marks.assign(V, -1);
    int i = 0;
    while(bipartite && i < V) {
        if(marks[i] == -1)
                bipartite = check(AL, i);
        i++;
    }
    bipartite ? printf("SI\n") : printf("NO\n");
    return true;
}

int main() {
    while(solveCase());
    return 0;
}