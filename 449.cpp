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
    string s;
    while(cin >> s) {
        int n = sz(s);
        vvi dp(n, vi(n, 0));
        for(int i = 0; i < n; i++)
            dp[i][i] = 1;
        for(int d = 1; d < n; d++) {
            for(int i = 0; i + d < n; i++) {
                int j = i + d;
                int I = i + 1, J = j - 1;
                while(s[I] == s[i]) I++;
                while(s[J] == s[j]) J--;
                if(s[i] == s[j]) {
                    if(I <= J) dp[i][j] = dp[I][J];
                    dp[i][j]++;
                }
                else {
                    dp[i][j] = min(dp[i][J], dp[I][j]) + 1;
                }
            }
        }
        cout << dp[0][n - 1] << '\n';
    }
    return 0;
}