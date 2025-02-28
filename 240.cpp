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

int sols;
vector<string> cadenas;
vector<string> soluciones;
vi posiciones;
vi valores;

ll valor(int pos, int x) {
    string s = cadenas[pos];
    ll ret = 0;
    rep(i,0,sz(s)) {
        char c = s[i];
        ret *= 10;
        if(i == posiciones[pos]) ret += x;
        else ret += (ll)(c - '0');
    }
    return ret;
}

void simula(int i) {
    if(i == 3) {
        if(valores[0] + valores[1] == valores[2]) {
            sols++;
            rep(i,0,3) soluciones[i] = cadenas[i];
        }
    }
    else {
        if(posiciones[i] == -1) {
            simula(i + 1);
            return;
        }
        int x = (posiciones[i] > 0 ? 0 : 1);
        while(x <= 9 && sols < 2) {
            valores[i] = valor(i, x);
            cadenas[i][posiciones[i]] = x + '0';
            simula(i + 1);
            x++;
        }
    }
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    cadenas.assign(3, "");
    soluciones.assign(3, "");
    valores.assign(3, -1);
    while(cin >> cadenas[0] >> cadenas[1] >> cadenas[2]) {
        sols = 0;
        posiciones.assign(3, -1);
        rep(i,0,3) rep(j,0,sz(cadenas[i])) {
            if(cadenas[i][j] == '-') {
                posiciones[i] = j;
                break;
            }
        }
        simula(0);
        if(sols == 0) cout << "IMPOSIBLE\n";
        else if(sols > 1) cout << "VARIAS\n";
        else cout << soluciones[0] << ' ' << soluciones[1] << ' ' << soluciones[2] << '\n';
    }
    return 0;
}