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
    int n, t;
    while(cin >> n >> t) {
        int min_x = INT_MAX, max_x = INT_MIN, min_y = INT_MAX, max_y = INT_MIN;
        map<int, int> en_x, en_y;
        rep(i,0,t) {
            int x, y; cin >> x >> y;
            min_x = min(min_x, x);
            max_x = max(max_x, x);
            min_y = min(min_y, y);
            max_y = max(max_y, y);
            en_x[x]++;
            en_y[y]++;
        }

        int pos_x = min_x, sol_x = 0, cur_x;
        for(auto it = ++en_x.begin(); it != en_x.end(); it++) {
            sol_x += it->first * it->second;
        }
        cur_x = sol_x;
        int iz = 0, der = t - en_x[min_x];
        for(int x = min_x + 1; x <= max_x; x++) {
            cur_x = cur_x - der + iz + en_x[x - 1];
            iz += en_x[x - 1];
            der -= en_x[x];
            if(cur_x < sol_x) {
                sol_x = cur_x;
                pos_x = x;
            }
        }

        int pos_y = min_y, sol_y = 0, cur_y;
        for(auto it = ++en_y.begin(); it != en_y.end(); it++) {
            sol_y += it->first * it->second;
        }
        cur_y = sol_y;
        int ab = 0, arr = t - en_y[min_y];
        for(int y = min_y + 1; y <= max_y; y++) {
            cur_y = cur_y - arr + ab + en_y[y - 1];
            ab += en_y[y - 1];
            arr -= en_y[y];
            if(cur_y < sol_y) {
                sol_y = cur_y;
                pos_y = y;
            }
        }

        cout << pos_x << ' ' << pos_y << '\n';
    }
    return 0;
}