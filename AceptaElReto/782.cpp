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
#define int ll
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

struct ventana {
    int x, y, fin;
    bool operator <(ventana const& v2) {
        return y < v2.y || (y == v2.y && (fin < v2.fin || (fin == v2.fin && x > v2.x)));
    }
};

signed main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    int ancho, alto, obs;
    while(cin >> ancho >> alto >> obs && (ancho || alto || obs)) {
        vector<int> cambios;
        unordered_map<int, vector<ventana>> ventanas; // Las ventanas que empiezan en cada x
        unordered_map<int, vi> inicios_ventanas;
        unordered_map<int, vi> finales_ventanas;
        unordered_map<int, int> gargolas;
        bool cero = false;
        rep(i,0,obs) {
            char c; cin >> c;
            int x, y, w = 1, aux = -1;
            if(c == 'G') {
                cin >> x >> y;
                cambios.push_back(x);
                gargolas[x] = max(gargolas[x], y);
            }
            else {
                cin >> x >> y >> w >> aux;
                inicios_ventanas[x].push_back(y);
                finales_ventanas[x + w].push_back(y);
                cambios.push_back(x);
                cambios.push_back(x + w);
            }
            
            if(x == 0) cero = true;
        }
        
        if(!cero) {
            cambios.push_back(0);
            inicios_ventanas[0].push_back(0);
            finales_ventanas[ancho].push_back(0);
        }
        sort(all(cambios));
        for(int x : cambios) {
            sort(all(inicios_ventanas[x]), less<int>());
            sort(all(finales_ventanas[x]), greater<int>());
        }

        stack<ventana> s;
        int sol = 0;

        for(int x : cambios) {
            int alt_maxima = -1;
            while(!s.empty() && s.top().fin < x) s.pop();
            if(!ventanas[x].empty()) {
                ventana& mas_alta = ventanas[x].back();
                alt_maxima = mas_alta.y;
                while(!s.empty()) {
                    ventana top = s.top();
                    if(top.fin < x) s.pop();
                    else if (top.y < alt_maxima) {
                        sol = max(sol, (x - top.x) * (alto - top.y));
                        s.pop();
                    }
                }
                if(s.top().y == alt_maxima) {
                    mas_alta.x = s.top().x;
                    mas_alta.fin = max(mas_alta.fin, s.top().fin);
                    s.pop();
                }
                for(ventana v : ventanas[x]) s.push(v);
            }
        }
    }
    return 0;
}