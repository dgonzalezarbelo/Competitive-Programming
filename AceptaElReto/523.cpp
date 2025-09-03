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

bool menor(string & s1, string & s2) {
    string c1 = s1.substr(4, 3) + s1.substr(0, 4);
    string c2 = s2.substr(4, 3) + s2.substr(0, 4);
    return c1 < c2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int menores = 0, mayores = 0;
        string s; cin >> s;
        string c; cin >> c;
        while(c != "0") {
            if(menor(c, s)) menores++;
            else mayores++;
            cin >> c;
        }
        cout << menores << ' ' << mayores << '\n';
    }
    return 0;
}