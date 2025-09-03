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
    string s; cin >> s;
    if(s == "0") return false;
    bool ean13 = sz(s) > 8;
    bool trece_digitos = sz(s) >= 13;
    int j = sz(s) - 2;
    int i = 1;
    ll cod = 0;
    while(j >= 0) {
        if(i % 2 == 0)
            cod += (s[j] - '0') % 10;
        else
            cod += ((s[j] - '0') % 10) * 3;
        i++;
        j--;
    }
    ll rem = (10 - cod % 10) % 10;
    if(rem != s[sz(s) - 1] - '0') cout << "NO\n";
    else {
        cout << "SI";
        if(ean13) {
            cout << ' ';
            if(!trece_digitos) cout << "EEUU";
            else {
                int acum = s[0] - '0';
                int i = 1;
                while(!m.count(acum)) {
                    acum *= 10;
                    acum += s[i] - '0';
                    i++;
                    if(i == 4) break;
                }
                if(m.count(acum)) cout << m[acum];
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