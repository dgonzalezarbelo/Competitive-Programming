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

int main() {
    int t; scanf("%d\n", &t);
    while(t--) {
        int d, n; scanf("%d %d", &d, &n);
        int tiempo = 8 * 60;
        int suma = 0;
        rep(i,0,n) {
            int h, m, dur;
            scanf("%d:%d %d", &h, &m, &dur);
            m = 60 * h + m;
            if(m - tiempo >= d) {
                suma += m - tiempo;
            }
            tiempo = m + dur;
        }
        if(14 * 60 - tiempo >= d) {
            suma += 14 * 60 - tiempo;
        }
        printf("%d\n", suma);
    }
    return 0;
}