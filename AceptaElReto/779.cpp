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
    int n, a;
    while(cin >> n >> a && n && a) {
        vii v;
        while(a--) {
            int t; cin >> t;
            while(t--) {
                int ini, fin; scanf("%d,%d", &ini, &fin);
                v.push_back({ini, 1});
                v.push_back({fin, -1});
            }
        }
        sort(all(v));
        int cur = 1, sum = 0;
        rep(i,0,sz(v)) {
            if(sum == 0 && v[i].first > cur) break;
            cur = v[i].first+ 1;
            if(v[i].second == 1) sum++;
            else sum--;
        }
        if(cur > n) cout << "SI\n";
        else cout << "NO\n";
    }
    return 0;
}