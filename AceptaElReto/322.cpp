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
    string s;
    while(getline(cin, s) && cin) {
        int n = sz(s);
        vvi dp(n, vi(n, -1));
        rep(i,0,n) dp[i][i] = 1;
        rep(i,0,n-1) dp[i][i + 1] = (s[i] == s[i + 1] ? 2 : 1) ;
        for(int d = 2; d < n; d++) {
            for(int i = 0; i + d < n; i++) {
                int j = i + d;
                int sol = dp[i + 1][j];
                sol = max(sol, dp[i][j - 1]);
                if(s[i] == s[j]) sol = max(sol, 2 + dp[i + 1][j - 1]);
                dp[i][j] = sol;
            }
        }
        int ini = 0, fin = n - 1;
        queue<char> q;
        stack<char> st;
        while(ini < fin - 1) {
            // cout << "ini -> " << ini << " fin -> " << fin << endl;
            if(s[ini] == s[fin]) {
                q.push(s[ini]);
                st.push(s[fin]);
                ini++;
                fin--;
            }
            else if(dp[ini + 1][fin] >= dp[ini][fin - 1])
                ini++;
            else
                fin--;
        }
        if(ini < fin) {
            if(dp[ini][fin] == 2) {
                q.push(s[ini]);
                st.push(s[fin]);
            }
            else q.push(s[fin]);
        }
        else q.push(s[ini]);
        while(!q.empty()) {
            cout << q.front(); q.pop();
        }
        while(!st.empty()) {
            cout << st.top(); st.pop();
        }
        cout << '\n';
    }
    return 0;
}