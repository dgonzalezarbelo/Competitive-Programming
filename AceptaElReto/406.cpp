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
    while(cin >> s) {
        int i = sz(s) - 1;
        while(i >= 0 && s[i] != '|') {
            s[i] = '.';
            i--;
        }
        int fin = i, movidos = 0;
        while(i >= 0) {
            if(s[i] == '|') {
                fin = i;
                movidos = 0;
            }
            else if(s[i] != '.') {
                s[fin - 1 - movidos] = s[i];
                if(fin - 1 - movidos != i)
                    s[i] = '.';
                movidos++;
            }
            i--;
        }
        
        int q; cin >> q;
        rep(qq,0,q) {
            int k; cin >> k; k--;
            if(qq) cout << ' ';
            cout << s[k];
        }
        cout << '\n';
    }   
    return 0;
}