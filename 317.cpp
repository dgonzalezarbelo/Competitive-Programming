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

int MAXN = 10; // size alfabeto
class Trie{
public:
    int prefixes; // num prefijos a los que pertenece el nodo;
    int words; // palabras que terminan en el nodo
    vector <Trie*> child;
    Trie() : prefixes(0), words(0), child(MAXN, nullptr) {}
    ~Trie() {for(int i = 0; i < MAXN; ++i) delete child[i]; }
    void add(string const& s, int i = 0){
        if (i >= sz(s)) ++words;
        else{
            Trie* t;
            if (child[s[i] - '0'] == nullptr){
                t = child[s[i] - '0'] = new Trie();
                t->prefixes = 1;
            }
            else{
                t = child[s[i] - '0'];
                ++t->prefixes;
            }
            t->add(s, i + 1);
        }
    }
};
// numero de veces que s esta en t
int search(string const& s, Trie * t){
    Trie* aux = t;
    for(int i = 0; i < sz(s); ++i){
        int pos = s[i] - '0';
        if (aux->child[pos] == nullptr) return 0;
        aux = aux->child[pos];
    }
    return aux->words;
}

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while(cin >> n && n) {
        Trie t;
        string s;
        for(int i = 0; i < n; i++) {
            cin >> s;
            t.add(s);
        }
        cin >> s;
        vi dp(s.size());
        string cur = s.substr(s.size() - 1,1);
        if(search(cur, &t)) dp[s.size() - 1] = 1;
        for(int i = s.size() - 2; i >= 0; i--) {
            if(s[i] == '0') {
                dp[i] = dp[i+1];
                continue;
            }
            cur = s.substr(i, 1);
            if(search(cur, &t)) dp[i] = dp[i+1];
            for(int j = i + 1; j < s.size(); j++) {
                if(s[j] == '0') break;
                cur += s[j];
                if(search(cur, &t)) {
                    if(j < s.size() - 1) dp[i] += dp[j+1];
                    else dp[i]++;
                    dp[i] %= MOD;
                }
            }
        }
        cout << dp[0] << '\n';
    }
    return 0;
}