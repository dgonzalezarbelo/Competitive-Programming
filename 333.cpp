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

bool capicua(string s) {
    if(sz(s) == 1) return true;
    if(s[0] == '0' || s[sz(s) - 1] == '0') return false;
    for(int i = 0; i < sz(s) / 2; i++) {
        if(s[i] != s[sz(s) - 1 - i]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    while(cin >> s && s != "0") {
        if(sz(s) == 1) {
            cout << "NO\n";
            continue;
        }
        bool ok = true;
        for(int mitad = 1; mitad < sz(s); mitad++) {
            ok = true;
            if(capicua(s.substr(0, mitad)) && capicua(s.substr(mitad, sz(s) - mitad))) {
                cout << "SI\n";
                break;
            }
            ok = false;
        }
        if(!ok) cout << "NO\n";
    }
    return 0;
}