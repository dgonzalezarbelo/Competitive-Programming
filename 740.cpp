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

set<int> solutions;

void solve(string& s, int i, vi & v, set<int> & solutions) {
    if(i == sz(s)) {
        int suma = 0, acum = 0;
        for(int j = 0; j < sz(s); j++) {
            if(v[j] > 0) {
                suma += acum;
                acum = s[j] - '0';
            }
            else {
                acum *= 10;
                acum += s[j] - '0';
            }
        }
        if(acum > 0) suma += acum;
        solutions.insert(suma);
    }
    else {
        v[i] = 0;
        solve(s, i + 1, v, solutions);
        v[i] = 1;
        solve(s, i + 1, v, solutions);
        v[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        set<int> solutions;
        vi v(sz(s), 0);
        solve(s, 0, v, solutions);
        bool first = true;
        for(int a : solutions) {
            if(!first) cout << ' ';
            first = false;
            cout << a;
        }
        cout << '\n';
    }
    return 0;
}