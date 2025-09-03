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
    int t; cin >> t;
    while(t--) {
        string s;
        vector<string> dic;
        while(cin >> s && s != ".") dic.push_back(s);
        vector<string> linea;
        while(cin >> s && s != ".") linea.push_back(s);
        for(int i = 0; i < linea.size(); i++) {
            int c = 0;
            string cur = linea[i];
            string match = "";
            for(int j = 0; j < dic.size(); j++) {
                string comp = dic[j];
                if(cur.size() == comp.size() && cur[0] == comp[0] && cur.back() == comp.back()) {
                    map<char, int> a, b;
                    for(int i = 0; i < cur.size(); i++) {
                        a[cur[i]]++;
                        b[comp[i]]++;
                    }
                    bool ok = true;
                    for(char c : cur) {
                        if(a[c] != b[c]) ok = false;
                    }
                    if(ok && comp != match){
                        c++;
                        match = comp;
                    }
                }
            }
            if(c == 1) cout << match << ' ';
            else cout << cur << ' ';
        }
        cout << ".\n";
    }
    return 0;
}