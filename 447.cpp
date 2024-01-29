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

bool dfs(vi & niveles, set<vi> & s, int l, vi & capacidades) {
    if(s.count(niveles)) return false;
    s.insert(niveles);
    for(int x : niveles) if(x == l) return true;
    for(int i = 0; i < niveles.size(); i++) {
        int aux = niveles[i];
        niveles[i] = 0; //Vaciar
        if(dfs(niveles, s, l, capacidades)) return true;
        niveles[i] = capacidades[i]; //Llenar
        if(dfs(niveles, s, l, capacidades)) return true;
        niveles[i] = aux; //Restaurar
        for(int j = 0; j < niveles.size(); j++) {
            if(i != j) {
                
            }
        }
    }
}

bool solve() {
    int l, r; cin >> l;
    if(!l) return false;
    cin >> r;
    vi capacidades(r);
    for(int i = 0; i < r; i++) cin >> capacidades[r];
    
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(solve());
    return 0;
}