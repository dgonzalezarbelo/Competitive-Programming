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
    char c; double n;
    cin >> c >> n;
    if(!cin) return false;
    unordered_map<char, string> nombres;
    nombres['D'] = "DESAYUNOS";
    nombres['A'] = "COMIDAS";
    nombres['M'] = "MERIENDAS";
    nombres['I'] = "CENAS";
    nombres['C'] = "COPAS";
    unordered_map<char, double> totales;
    totales['D'] = 0.0;
    totales['A'] = 0.0;
    totales['M'] = 0.0;
    totales['I'] = 0.0;
    totales['C'] = 0.0;
    double suma = 0.0;
    int countA = 0, countB = 0;
    while(c != 'N') {
        suma += n;
        totales[c] += n;
        if(c == 'A') countA++;
        countB++;
        cin >> c >> n;
    }
    double maximo = -1.0;
    double minimo = (double) INT_MAX;
    vector<char> mejores, peores;
    for(auto p : totales) {
        if(p.second > maximo) {
            mejores = {p.first};
            maximo = p.second;
        }
        else if(p.second == maximo) mejores.push_back(p.first);
        if(p.second < minimo) {
            peores = {p.first};
            minimo = p.second;
        }
        else if(p.second == minimo) peores.push_back(p.first);
    }
    if(sz(mejores) == 1) cout << nombres[mejores[0]];
    else cout << "EMPATE";
    cout << "#";
    if(sz(peores) == 1) cout << nombres[peores[0]];
    else cout << "EMPATE";
    cout << "#";
    if(countB * totales['A'] > suma * countA) cout << "SI\n";
    else cout << "NO\n";
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(resuelveCaso());
    return 0;
}