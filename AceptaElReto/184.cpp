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

bool solve() {
    int n;
    scanf("%d", &n);
    if(!n) return false;
    int suma = 0;
    while(n--) {
        int h1, h2, m1, m2;
        scanf("%d:%d-%d:%d", &h1, &m1, &h2, &m2);
        if(h2 < h1 || (h2 == h1 && m2 < m1)) h2 += 24;
        suma += (h2 - h1) * 60 + (m2 - m1);
    }
    if(suma / 60 < 10) printf("0");
    printf("%d:", suma / 60);
    if(suma % 60 < 10) printf("0");
    printf("%d\n", suma % 60);
    return true;
}

int main() {
    while(solve());
    return 0;
}