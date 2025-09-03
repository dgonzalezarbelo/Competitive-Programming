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

vi orden = {0, 1, 2, 3, 4};

struct Carta {
    int palo;
    int num;
    bool operator<(Carta const& c2) const {
        return orden[palo] < orden[c2.palo]
        || (orden[palo] == orden[c2.palo] && num < c2.num);
    }
};

vi lis(const vector<Carta> & S) {
    if (S.empty()) return {};
    vi prev(sz(S));
    typedef pair<Carta, int> p;
    vector<p> res;
    rep(i,0,sz(S)) {
        // change 0=> i for longest non=decreasing subsequence
        auto it = lower_bound(all(res), p{S[i],0});
        if(it == res.end())
            res.emplace_back(), it =res.end()-1;
        *it = {S[i],i};
        prev[i] = it == res.begin() ? 0 : (it-1)->second;
    }
    int L = sz(res), cur = res.back().second;
    vi ans(L);
    while (L--) ans[L] = cur, cur = prev[cur];
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    unordered_map<char, int> letras;
    letras['S'] = 0;
    letras['W'] = 1;
    letras['E'] = 2;
    letras['R'] = 3;
    letras['C'] = 4;
    vector<Carta> v(n);
    rep(i,0,n) {
        char c; cin >> c;
        int a; cin >> a;
        v[i] = {letras[c], a};
    }
    int sol = n;
    do {
        sol = min(sol, n - sz(lis(v)));
    } while(next_permutation(orden.begin(), --orden.end()));
    
    cout << sol << '\n';

    return 0;
}