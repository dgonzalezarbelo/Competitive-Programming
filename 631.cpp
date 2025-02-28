#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ascensor {
    ascensor() {}
    ascensor(int ini, int fin, int nivel) : ini(ini), fin(fin), nivel(nivel) {}
    int ini, fin, nivel;
    bool operator < (ascensor const& a) const {
        return ini < a.ini || (ini == a.ini && (fin < a.fin || (fin == a.fin && nivel < a.nivel)));
    }
};

bool resuelveCaso() {
    int n; cin >> n;
    if(!cin) return false;
    vector<ascensor> v(n);
    int max_piso = 0, max_nivel = 0;
    for(int i = 0; i < n; i++) {
        int ini, fin, nivel; cin >> ini >> fin >> nivel;
        v[i] = {ini, fin, nivel};
        max_piso = max(max_piso, fin);
        max_nivel = max(max_nivel, nivel);
    }
    sort(v.begin(), v.end(), less<ascensor>());
    int ini = 0, fin = max_nivel;
    while(ini + 1 < fin) {
        int m = (ini + fin) / 2;
        int cur_piso = 0;
        for(int i = 0; i < n; i++) {
            if(v[i].ini <= cur_piso && v[i].nivel <= m)
                cur_piso = max(cur_piso, v[i].fin);
        }
        if(cur_piso == max_piso)    // m es un nivel válido -> la solución es <= m
            fin = m;
        else                        // m no es un nivel válido -> la solución es > m
            ini = m;
    }
    cout << fin << '\n';
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(resuelveCaso());
    return 0;
}