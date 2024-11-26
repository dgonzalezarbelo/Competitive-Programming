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
    int casos; cin >> casos; cin.get();
    for(int caso = 1; caso <= casos; caso++) {
        string linea; getline(cin, linea);
        set<string> palabras;
        vector<string> en_orden;
        while(linea != "END") {
            string palabra;
            for(char c : linea) {
                if('a' <= c && c <= 'z') palabra += c;
                else if(palabra != "") {
                    palabras.insert(palabra);
                    en_orden.push_back(palabra);
                    palabra = "";
                }
            }
            if(palabra != "") {
                palabras.insert(palabra);
                en_orden.push_back(palabra);
            }
            getline(cin, linea);
        }
        int best_i = -1, best_j = -1;
        int i = 0, j = 0;
        map<string, int> m_encontradas;
        int encontradas = 0;
        while(j < sz(en_orden)) {
            string palabra = en_orden[j];
            m_encontradas[palabra]++;
            if(m_encontradas[palabra] == 1) encontradas++;
            if(encontradas == sz(palabras)) {
                while(i < j && m_encontradas[en_orden[i]] > 1) {
                    m_encontradas[en_orden[i]]--;
                    i++;
                }
                if(best_j == -1 || j - i < best_j - best_i || (j - i == best_j - best_i && i < best_i)) {
                    best_i = i;
                    best_j = j;
                }
            }
            j++;
        }
        cout << "Document " << caso << ": " << best_i + 1 << " " << best_j + 1 << '\n';
    }
    return 0;
}