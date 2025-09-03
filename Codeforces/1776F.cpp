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
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vvi al(n);
        vii aristas(m);
        rep(i,0,m) {
            int a, b; cin >> a >> b;
            a--; b--;
            aristas[i] = {min(a, b), max(a, b)};
            al[a].push_back(b);
            al[b].push_back(a);
        }
        if(m < n * (n - 1) / 2) {
            int vertex = -1;
            for(int i = 0; i < n; i++) {
                if(sz(al[i]) < n - 1) {
                    vertex = i;
                    break;
                }
            }
            cout << "2\n";
            bool first = true;
            for(ii p : aristas) {
                if(!first) cout << ' ';
                first = false;
                if(p.first == vertex || p.second == vertex) cout << 1;
                else cout << 2;
            }
        }
        else {
            cout << "3\n";
            bool first = true;
            for(ii p : aristas) {
                if(!first) cout << ' ';
                first = false;
                if(p.first == 0) {
                    if(p.second == 1) cout << 1;
                    else cout << 2;
                }
                else cout << 3;
            }
        }
        cout << '\n';
    }
    return 0;
}