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

vll v;

bool solve(){
    ll n; cin >> n;
    if(!n) return false;
    auto it = lower_bound(v.begin(), v.end(), n);
    if (*it > n && it != v.begin()) it--;
    cout << it - v.begin() << ' ' << n - *it << '\n';
    return true;
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    v.push_back(0);
    ll n = 1;
    while(n * (n + 1) / 2 <= 250000000) {
        v.push_back(n*(n+1)/2);
        n++;
    }
    v.push_back(n*(n+1)/2);
    while(solve());
    return 0;
}