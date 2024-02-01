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
    stack<pair<string, int>> pila;
    int vic;
    rep(i,0,n) {
        string cad;
        cin >> cad >> vic;
        cad = cad.substr(6,4) + '/' + cad.substr(3,2) + '/' + cad.substr(0,2);
        while(!pila.empty() && pila.top().second <= vic) pila.pop();
        if(pila.empty()) cout << "NO HAY\n";
        else {
            string top = pila.top().first;
            cout << top.substr(8,2) << '/' << top.substr(5,2) << '/' << top.substr(0,4) << endl;
        }
        pila.push({cad, vic});
    }
    cout << "---\n";
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(resuelveCaso());
    return 0;
}