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

bool is_vowel(char c) {
    char low = tolower(c);
    return low == 'a' || low == 'e' || low == 'i' || low == 'o' || low == 'u';
}

bool resuelveCaso() {
    int n;
    string s;
    cin >> n >> s;
    if(n == 9999 && s == "ZZZ") return false;
    if(n < 9999) n++;
    else {
        n = 0;
        if(s[2] != 'Z') s[2]++;
        else {
            s[2] = 'B';
            if(s[1] != 'Z') s[1]++;
            else {
                s[1] = 'B';
                if(s[0] != 'Z') s[0]++;
                else s[0] = 'B';
            }
        }
    }
    if(is_vowel(s[0])) s[0]++;
    if(is_vowel(s[1])) s[1]++;
    if(is_vowel(s[2])) s[2]++;
    if(n < 1000) cout << 0;
    if(n < 100) cout << 0;
    if(n < 10) cout << 0;
    cout << n << ' ' << s << endl;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(resuelveCaso());
    return 0;
}