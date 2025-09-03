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
using vll = vector<ll>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;
using vb = vector<bool>;
using vvb = vector<vb>;
using db = double;
using vdb = vector<db>;
using ldb = long double; //100 ceros pero poca precision decimal

unordered_map<int, char> m;

int solve(string & s, int i) {
    if(i == s.size() - 1) {
        int a = stoi(s);
        if(m[a % 23] == s.back()) return 1;
        else return 0;
    }
    else {
        if(s[i] == '?') {
            int sol = 0;
            for(int j = 0; j < 10; j++) {
                s[i] = '0' + j;
                sol += solve(s, i + 1);
            }
            s[i] = '?';
            return sol;
        }
        else return solve(s, i + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    m[0] = 'T';
    m[1] = 'R';
    m[2] = 'W';
    m[3] = 'A';
    m[4] = 'G';
    m[5] = 'M';
    m[6] = 'Y';
    m[7] = 'F';
    m[8] = 'P';
    m[9] = 'D';
    m[10] = 'X';
    m[11] = 'B';
    m[12] = 'N';
    m[13] = 'J';
    m[14] = 'Z';
    m[15] = 'S';
    m[16] = 'Q';
    m[17] = 'V';
    m[18] = 'H';
    m[19] = 'L';
    m[20] = 'C';
    m[21] = 'K';
    m[22] = 'E';
    int t; cin >> t;
    cin.get();
    while(t--) {
        string s;
        getline(cin, s);
        cout << solve(s, 0) << '\n';
    }
    return 0;
}