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
    int m, g;
    while(cin >> m >> g && (m || g)) {
        vii mejillones(m), gambas(g);
        bool centro = false;
        for(ii & p : mejillones) {
            cin >> p.first >> p.second;
            if(p.first == 0 && p.second == 0) centro = true;
        }
        for(ii & p : gambas) {
            cin >> p.first >> p.second;
            if(p.first == 0 && p.second == 0) centro = true;
        }
        if(centro) {
            cout << "NO\n";
            continue;
        }

        //Trazamos rectas de la forma ax = by
        int m1, m2, g1, g2;
        bool sol = false;
        for(int i = 0; i < m && !sol; i++) {
            int a = mejillones[i].second, b = mejillones[i].first;
            m1 = m2 = g1 = g2 = 0;
            for(int j = 0; j < m; j++) {
                if(i == j) continue;
                int x = mejillones[j].first, y = mejillones[j].second;
                if(a * x > b * y) m1++;
                else m2++;
            }
            for(int j = 0; j < g; j++) {
                int x = gambas[j].first, y = gambas[j].second;
                if(a * x > b * y) g1++;
                else g2++;
            }
            if(g1 == g2 && abs(m1 - m2) == 1) sol = true;
        }
        for(int i = 0; i < g && !sol; i++) {
            int a = gambas[i].second, b = gambas[i].first;
            m1 = m2 = g1 = g2 = 0;
            for(int j = 0; j < m; j++) {
                int x = mejillones[j].first, y = mejillones[j].second;
                if(a * x > b * y) m1++;
                else m2++;
            }
            for(int j = 0; j < g; j++) {
                if(i == j) continue;
                int x = gambas[j].first, y = gambas[j].second;
                if(a * x > b * y) g1++;
                else g2++;
            }
            if(m1 == m2 && abs(g1 - g2) == 1) sol = true;
        }
        cout << (sol ? "SI\n" : "NO\n");
    }   
    return 0;
}