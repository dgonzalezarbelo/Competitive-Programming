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

bool resuelveCaso() {
    int n; cin >> n;
    if(!cin) return false;
    map<string, int> fichas;
    unordered_map<int, vector<string>> m;
    rep(i,0,n) {
        string s; cin >> s;
        int a;
        cin >> a;
        int t = 0;
        while(a != 0) {
            m[a].push_back(s);
            t++;
            cin >> a;
        }
        fichas[s] = t;
    }
    int c; cin >> c;
    vector<string> ganadores;
    while(c--) {
        int a; cin >> a;
        if(!ganadores.empty()) continue;
        for(string& s : m[a]) {
            if(--fichas[s] == 0) ganadores.push_back(s);
        }
    }
    sort(all(ganadores));
    bool primero = true;
    for(string& s : ganadores) {
        if(!primero) cout << ' ';
        primero = false;
        cout << s;
    }
    cout << endl;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(resuelveCaso());
    return 0;
}