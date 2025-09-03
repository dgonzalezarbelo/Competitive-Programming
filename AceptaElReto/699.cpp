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

bool solve() {
    string s; cin >> s;
    if(!cin) return false;
    cin.get();
    vector<string> v;
    string aux;
    for(char c : s) {
        if(c == '+') {
            v.push_back(aux);
            aux = "";
        }
        else aux += c;
    }
    v.push_back(aux);
    for(string & b : v) {
        if(b[b.size() - 1] == 'x'){
            if(b.size() > 1) b = b.substr(0, b.size() - 1);
            else b = "1";
        } 
        else {
            bool tiene_exp = false;
            for(char c : b) if(c == '^') tiene_exp = true;
            if(!tiene_exp) b = "0";
            else {
                string coef = "", exp = "";
                bool x = false;
                for(char c : b) {
                    if(c == 'x') x = true;
                    else if (c != '^') {
                        if(!x) coef += c;
                        else exp += c;
                    }
                }
                int m = 1;
                if(coef != "") m = stoi(coef);
                int n = stoi(exp);
                m *= n;
                n--;
                if(n > 1) b = to_string(m) + "x^" + to_string(n);
                else b = to_string(m) + "x";
            }
        }
        
    }
    cout << v[0];
    for(int i = 1; i < v.size(); i++) {
        if(v[i] != "0") cout << "+" << v[i];
    }
    cout << '\n';
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(solve());
    return 0;
}