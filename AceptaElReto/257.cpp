#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <deque>
#include <numeric>
#include <algorithm>
#include <climits>
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
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;
using vb = vector<bool>;
using vvb = vector<vb>;
using db = double;
using vdb = vector<db>;
using ldb = long double; //100 ceros pero poca precision decimal

unordered_map<int, ii> m;
vvi dp;
int n;

int dist(int a, int b){
    return abs(m[a].fi - m[b].fi) + abs(m[a].se - m[b].se);
}

int solve(int a, int b){
    if(a == n) return 0;
    if(b == n) return 0;
    if(dp[a][b] != -1) return dp[a][b];
    int m = max(a, b);
    int s1 = solve(m + 1, b) + dist(a, m + 1);
    int s2 = solve(a, m + 1) + dist(b, m + 1);
    return dp[a][b] = min(s1, s2);
}

void resuelveCaso(){
    cin >> n;
    m.clear();
    for(int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        m[i] = mp(a, b);
    }
    m[0] = mp(0,0);
    dp.assign(n + 1, vi(n + 1, -1));
    cout << solve(0, 0) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) resuelveCaso();
    return 0;
}