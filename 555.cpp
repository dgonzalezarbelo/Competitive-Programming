#include <bits/stdc++.h>
#pragma warning (disable : 4996)
using namespace std;

#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define mp make_pair

const double EPS = 1e-9;
const double INF = 1e9; //1e18 tambien suele ir bien
using ll = long long int;
using ii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;
using vb = vector<bool>;
using vvb = vector<vb>;
using db = double;
using vdb = vector<db>;
using ldb = long double; //100 ceros pero poca precision decimal

vii dir = {{-1,0},{1,0},{0,-1},{0,1}};
int a, b, n; 

bool rango(int i, int j) {
    return i >= 0 && i < a && j >= 0 && j < b;
}

bool solve() {
    cin >> a;
    if(!a) return false;
    cin >> b >> n;
    swap(a, b);
    a++; b++;
    vvi dist(a, vi(b, -1));
    vvb visited(a, vb(b, false));
    queue<ii> q;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        swap(x, y);
        q.push(mp(x, y));
        dist[x][y] = 0;
    }
    while(!q.empty()) {
        auto p = q.front(); q.pop();
        visited[p.fi][p.se] = true;
        for(auto d : dir) {
            if(rango(p.fi + d.fi, p.se + d.se) && !visited[p.fi + d.fi][p.se + d.se]) {
                visited[p.fi + d.fi][p.se + d.se] = true;
                dist[p.fi + d.fi][p.se + d.se] = dist[p.fi][p.se] - 1;
                if(dist[p.fi + d.fi][p.se + d.se] > -10)
                    q.push(mp(p.fi + d.fi, p.se + d.se));
            }
        }
    }
    for(int j = 0; j < b; j++) {
        if(!visited[0][j]) {
            q.push(mp(0, j));
            dist[0][j] = 0;
        }
    }
    bool sol = false;
    while(!q.empty()) {
        auto p = q.front(); q.pop();
        visited[p.fi][p.se] = true;
        if(p.fi == a - 1) {
            sol = true;
            break;
        }
        for(auto d : dir) {
            if(rango(p.fi + d.fi, p.se + d.se) && !visited[p.fi + d.fi][p.se + d.se]) {
                visited[p.fi + d.fi][p.se + d.se] = true;
                dist[p.fi + d.fi][p.se + d.se] = dist[p.fi][p.se] + 1;
                q.push(mp(p.fi + d.fi, p.se + d.se));
            }
        }
    }
    if(sol) cout << "SI\n";
    else cout << "NO\n";
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(solve());
    return 0;
}