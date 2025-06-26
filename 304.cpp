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
    while(t--) {
        int a, b; cin >> a >> b;
        if(b == 0) {
            cout << "DIV0\n";
            continue;
        }
        if(a == 0) cout << "0 0\n";
        else {
            int signo = 1;
            if(a*b < 0) signo = -1;
            if (a > 0)
                cout << signo * (abs(a) / abs(b)) << ' ' << abs(a) % abs(b) << '\n';
            else
                cout << signo * (abs(a) / abs(b) + 1) << ' ' << abs(b) - (abs(a) % abs(b)) << '\n';
        }
    }
    return 0;
}