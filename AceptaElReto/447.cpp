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
using ull = unsigned long long;
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int l, r;
    while(cin >> l && l) {
        cin >> r;
        vi v(r);
        rep(i,0,r) cin >> v[i];
        bool sol = false;
        rep(i,0,r) {
            if(v[i] == l) {
                cout << "SI\n";
                sol = true;
                break;
            }
        }
        if(sol) continue;
        map<vi, bool> vis;
        vi estado(r, 0);
        queue<vi> q;
        q.push(estado);
        vis[estado] = true;
        while(!q.empty()) {
            estado = q.front(); q.pop();
            vi w;
            rep(i,0,r) {
                if(estado[i] == l) {
                    cout << "SI\n";
                    sol = true;
                    break;
                }
            }
            if(sol) break;
            rep(i,0,r) {
                w = estado;
                w[i] = 0;
                if(!vis[w]) {
                    vis[w] = true;
                    q.push(w);
                }
                w = estado;
                w[i] = v[i];
                if(!vis[w]) {
                    vis[w] = true;
                    q.push(w);
                }
                rep(j,0,r) {
                    w = estado;
                    if(i == j) continue;
                    int paso = min(w[i], v[j] - w[j]);
                    w[i] -= paso;
                    w[j] += paso;
                    if(!vis[w]) {
                        vis[w] = true;
                        q.push(w);
                    }
                }
            }
        }
        if(!sol) cout << "NO\n";
    }
    return 0;
}