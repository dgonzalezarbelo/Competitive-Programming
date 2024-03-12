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

unordered_map<ll, string> m;

bool resuelveCaso() {
    ll n; cin >> n;
    if(!n) return false;
    ll init = n / 10, last = n % 10;
    ll cod = 0;
    bool ean13 = n >= 1e9;
    bool todos_digitos = n >= 1e13;
    int i = 1;
    while(init) {
        if(i % 2 == 0)
            cod += init % 10;
        else
            cod += (init % 10) * 3;
        init /= 10;
        i++;
    }
    int rem = (10 - cod % 10) % 10;
    if(rem != last) cout << "NO\n";
    else {
        cout << "SI";
        if(ean13) {
            cout << ' ';
            if(todos_digitos) cout << "EEUU";
            else {
                while(n && !m.count(n)) n /= 10;
                if(n) cout << m[n];
                else cout << "Desconocido";
            }
        }
        cout << endl;
    }
    return true;
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    m[0] = "EEUU";
    m[380] = "Bulgaria";
    m[50] = "Inglaterra";
    m[539] = "Irlanda";
    m[560] = "Portugal";
    m[70] = "Noruega";
    m[759] = "Venezuela";
    m[850] = "Cuba";
    m[890] = "India";
    while(resuelveCaso());
    return 0;
}