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
    int n;
    while(cin >> n && n) {
        int fotos = 0;
        set<string> en_foto;
        map<string, int> esperando_por_persona;
        vector<string> nombres = {"Mafalda", "Felipe", "Manolito", "Susanita", "Miguelito", "Libertad", "Guille"};
        for(string s : nombres) esperando_por_persona[s] = 0;
        map<int, int> personas_por_nivel;
        string s;
        rep(i,0,n) {
            cin >> s;
            esperando_por_persona[s]++;
            vector<string> preparados;
            if(s == "Mafalda") {
                for(string ss : nombres) {
                    if(esperando_por_persona[ss] > 0) preparados.push_back(ss);
                }
                if(sz(preparados) >= 3) {
                    fotos++;
                    for(string ss : preparados) esperando_por_persona[ss]--;
                }
            }
            else {
                for(string ss : nombres) {
                    if(esperando_por_persona[ss] > 0) preparados.push_back(ss);
                }
                if(sz(preparados) >= 3 && esperando_por_persona["Mafalda"] > 0) {
                    fotos++;
                    for(string ss : preparados) esperando_por_persona[ss]--;
                }
            }
        }
        int esperando = 0;
        for(string s : nombres) esperando += esperando_por_persona[s];
        cout << fotos << ' ' << esperando << '\n';
    }
    return 0;
}