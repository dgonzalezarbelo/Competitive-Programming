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
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    int f, c;
    while(cin >> f >> c && f && c) {
        vector<vector<char>> orig(f, vector<char>(c)), fin(f, vector<char>(c));
        for(int i = 0; i < f; i++) {
            for(int j = 0; j < c; j++) cin >> orig[i][j];
            for(int j = 0; j < c; j++) cin >> fin[i][j];
        }
        int o0 = 0, o1 = 0, f0 = 0, f1 = 0, r = 0;
        for(int i = 0; i < f; i++) {
            for(int j = 0; j < c; j++) {
                if(orig[i][j] == '0') o0++;
                else if(orig[i][j] == '1') o1++;
                else r++;
                if(fin[i][j] == '0') f0++;
                else f1++;
            }
        }
        if(o1 + r < f1) {
            cout << "IMPOSIBLE\n";
            continue;
        }
        int mal = 0, r = 0;
        for(int i = 0; i < f; i++) {
            for(int j = 0; j < c; j++) {
                if(orig[i][j] != 'R' && orig[i][j] != fin[i][j]) mal++;
                if(orig[i][j] == 'R') r++;
            }
        }
        cout << mal / 2 + r << '\n';
    }
    return 0;
}