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

vvi dp; // Turno, suma, cara

bool solve(int suma, int cara) {
    if(suma >= 1000) return false;
    if(dp[suma][cara] != -1) return dp[suma][cara];
    bool gana = true;
    for(int c = 1; c <= 6; c++) {
        if(c == cara || c + cara == 7) continue;
        if(solve(suma + c, c)) {
            gana = false;
            break;
        }
    }
    return dp[suma][cara] = gana;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    dp.assign(10001, vi(7, -1));
    for(int i = 1; i <= 6; i++) {
        dp[1000][i] = false;
    }
    for(int suma = 999; suma >= 0; suma--) {
        for(int cara = 1; cara <= 6; cara++) {
            bool gana = true;
            for(int cara2 = 1; cara2 <= 6; cara2++) {
                if(cara == cara2 || cara + cara2 == 7) continue;
                if(dp[min(1000, suma + cara2)][cara2]) {
                    gana = false;
                    break;
                }
            }
            dp[suma][cara] = gana;
        }
    }
    while(t--) {
        int n, v; cin >> n >> v;
        if(dp[n][v] == 0) cout << "GANA\n";
        else cout << "PIERDE\n";
    }
    return 0;
}