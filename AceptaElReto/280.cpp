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

struct nodo {
    nodo() : x(0), iz(nullptr), der(nullptr) {}
    nodo(int x, nodo* iz, nodo* der) : x(x), iz(iz), der(der) {}
    ~nodo() {
        delete iz;
        delete der;
    }
    int x;
    nodo* iz;
    nodo* der;
};

nodo* crea_inorden(int ini, int fin, vi const& v) {
    if(ini > fin) return nullptr;
    if(ini == fin) return new nodo(v[ini], nullptr, nullptr);
    int mid = (ini + fin + 1) / 2;
    nodo *iz = crea_inorden(ini, mid - 1, v);
    nodo *der = crea_inorden(mid + 1, fin, v);
    return new nodo(v[mid], iz, der);
}

void preorden(nodo* raiz, bool& primero) {
    if(raiz == nullptr) return;
    if(!primero) cout << ' ';
    primero = false;
    cout << raiz->x;
    preorden(raiz->iz, primero);
    preorden(raiz->der, primero);
}

void postorden(nodo* raiz, bool& primero) {
    if(raiz == nullptr) return;
    postorden(raiz->iz, primero);
    postorden(raiz->der, primero);
    if(!primero) cout << ' ';
    primero = false;
    cout << raiz->x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a;
    while(cin >> a && a != -1) {
        vi v;
        while(a != -1) {
            v.push_back(a);
            cin >> a;
        }
        nodo* raiz = crea_inorden(0, sz(v) - 1, v);
        bool primero = true;
        preorden(raiz, primero);
        cout << '\n';
        primero = true;
        postorden(raiz, primero);
        cout << '\n';
    }
    return 0;
}