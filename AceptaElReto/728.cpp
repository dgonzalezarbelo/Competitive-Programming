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
    int n; cin >> n;
    if(!n) return false;
    int bajando = 0, subiendo = 0;
    int prev = INT_MIN;
    int sol = 0;
    while(n--) {
        int a; cin >> a;
        if(a < prev) {
            if(subiendo > 0) {
                if (bajando > 0) sol = max(sol, bajando + subiendo + 1);
                subiendo = 0;
                bajando = 1;
            }
            else bajando++;
        }
        else {
            subiendo++;
        }
        prev = a;
    }
    if(bajando > 0 && subiendo > 0) sol = max(sol, bajando + subiendo + 1);
    cout << sol << endl;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(resuelveCaso());
    return 0;
}