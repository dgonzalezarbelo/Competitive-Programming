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

string cambio(ll n) {
    ll base = 'Z' - 'A' + 1; // 26
    string ret;
    ll pot = 1;
    while(n > 0) {
        n--;
        ret += 'A' + n % base;
        n /= base;
    }
    reverse(all(ret));
    return ret;
}

bool resuelveCaso() {
    ll n; cin >> n;
    if(n==0) return false;
    bool first = true;
    while(n != 0) {
        if(!first) cout << ' ';
        first = false;
        cout << cambio(n);
        cin >> n;
    }
    cout << '\n';
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(resuelveCaso()); 
    return 0;
}