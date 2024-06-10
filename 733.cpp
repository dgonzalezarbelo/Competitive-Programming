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
    int t; cin >> t;
    string letras_viables = "BCDFGHJKLMNPRSTVWXYZ";
    unordered_map<char, ll> index;
    for(int i = 0; i < letras_viables.size(); i++) {
        index[letras_viables[i]] = i;
    }
    while(t--) {
        ll a, b;
        string sa, sb;
        cin >> a >> sa >> sb >> b >> sb;
        ll letras = letras_viables.size();
        ll sol = ((index[sb[0]] - index[sa[0]]) * letras * letras + (index[sb[1]] - index[sa[1]]) * letras + (index[sb[2]] - index[sa[2]])) * 10000 + b - a;
        cout << abs(sol) + 1 << endl;
    }
    return 0;
}