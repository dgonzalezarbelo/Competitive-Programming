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

map<string, ii> apariciones;

struct comp {
    bool operator()(pair<string, ii> const& s1, pair<string, ii> const& s2) const {
        return s1.second.first > s2.second.first || (s1.second.first == s2.second.first && s1.second.second > s2.second.second);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k; cin.get();
    vector<pair<string, ii>> lineas;
    rep(i,0,3*n) {
        string s; getline(cin, s);
        ii & p = apariciones[s];
        p.first++;
        p.second = i;
    }
    for(auto it = apariciones.begin(); it != apariciones.end(); it++) lineas.push_back(*it);
    sort(all(lineas), comp());
    rep(i,0,min(sz(lineas), k)) cout << lineas[i].first << '\n';   
    return 0;
}