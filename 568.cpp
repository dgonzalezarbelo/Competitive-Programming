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

vi meses;

struct comp {
    bool operator()(ii const&  p1, ii const& p2) {
        return p1.second < p2.second || (p1.second == p2.second && p1.first > p2.first);
    }
};

bool resuelveCaso() {
    int n;
    if(scanf("%d", &n) == EOF) return false;
    vi v(410);
    vii intervalos(n);
    for(int i = 0; i < n; i++) {
        int a, b, c, d;
        scanf("%d-%d %d-%d", &a, &b, &c, &d);
        intervalos[i] = {meses[--b] + a, meses[--d] + c};
    }
    sort(all(intervalos), comp());
    int sol = 0;
    for(ii & p : intervalos) {
        bool ok = true;
        for(int i = p.first; i <= p.second; i++) {
            if(v[i] >= 4) {
                ok = false;
                break;
            }
        }
        if(!ok) continue;
        sol++;
        for(int i = p.first; i <= p.second; i++) {
            v[i]++;
        }
    }
    printf("%d\n", sol);
    return true;
}

int main() {
    meses.assign(12, 0);
    meses[0] = 0;
    meses[1] = 31;
    meses[2] = 29;
    meses[3] = 31;
    meses[4] = 30;
    meses[5] = 31;
    meses[6] = 30;
    meses[7] = 31;
    meses[8] = 31;
    meses[9] = 30;
    meses[10] = 31;
    meses[11] = 30;
    for(int i = 1; i < 12; i++) {
        meses[i] += meses[i - 1];
    }
    while(resuelveCaso());
    return 0;
}