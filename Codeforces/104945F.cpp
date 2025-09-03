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
    int n; cin >> n;
    map<int, vector<string>, greater<int>> m;
    rep(i,0,n) {
        string s; cin >> s;
        int suma = 0;
        int p; cin >> p;
        suma += p * 10;
        vi v(6);
        for(int & x : v) cin >> x;
        sort(all(v));
        rep(j,1,5) suma += v[j];
        m[suma].push_back(s);
    }
    int med = 0;
    for(auto it = m.begin(); it != m.end() && med < 3; it++) {
        rep(i,0,it->second.size()) {
            cout << it->second[i] << ' ' << it->first << '\n';
            med++;
        }
    }
    return 0;
}