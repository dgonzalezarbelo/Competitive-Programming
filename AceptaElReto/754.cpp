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
        map<char, int> m;
        for(char c : s) m[c]++;
        char impar = '#';
        bool ok = true;
        for(auto p : m) {
            if(p.second % 2 == 1) {
                if (impar != '#') {
                    ok = false;
                }
                impar = p.first;
            }
        }
        if(!ok) {
            cout << "NO HAY\n";
            continue;
        }
        vector<char> v;
        for (auto p : m) v.push_back(p.first);
        for(char c : v) {
            for(int j = 0; j < m[c] / 2; j++) cout << c;
        }
        if(impar != '#') cout << impar;
        for(int i = sz(v) - 1; i >= 0; i--) {
            for(int j = 0; j < m[v[i]] / 2; j++) cout << v[i];
        }
        cout << '\n';
    }
    return 0;
}