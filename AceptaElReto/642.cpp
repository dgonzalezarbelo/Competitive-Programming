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

enum flags { UNIVISITED, EXPLORED, VISITED };

vector<flags> dfs_num;
vector<int> al;
int cycles;

void cycleCheck(int u) {
    dfs_num[u] = EXPLORED;
    int v = al[u];
    if (dfs_num[v] == UNIVISITED) {
        cycleCheck(v);
    }
    else if (dfs_num[v] == EXPLORED) {
        cycles++;
    }
    dfs_num[u] = VISITED;
}

bool resuelveCaso() {
    int n;
    cin >> n;
    if (!cin) return false;
    dfs_num.assign(n + 1, UNIVISITED);
    al.assign(n + 1, 0);
    cycles = 0;
    for (int i = 1; i <= n; i++) {
        cin >> al[i];
    }
    for (int i = 1; i <= n; i++) {
        if (dfs_num[i] == UNIVISITED) {
            cycleCheck(i);
        }
    }
    cout << cycles << '\n';
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (resuelveCaso());
    return 0;
}