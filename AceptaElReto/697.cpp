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
    int n; cin >> n;
    if(!n) return false;
    vvi mat(n, vi(n));
    for(auto & v : mat) {
        for(int & x : v) cin >> x;
    }
    ii up = {-1, 0}, down = {1, 0}, left = {0, -1}, right = {0, 1};
    vii directions = {up, right, down, left};
    int dir_index = 0;
    int fila = n / 2, col = n / 2;
    ll sum = mat[fila][col];
    int avance = 1;
    bool seguir = true;
    while(seguir) {
        ii dir = directions[dir_index];
        dir_index++;
        dir_index %= 4;
        for(int i = 0; i < avance; i++) {
            fila += dir.first;
            col += dir.second;
            if(fila < n && col < n && fila >= 0 && col >= 0)    sum += mat[fila][col];
            else seguir = false;
        }
        avance++;
    }
    cout << sum << '\n';
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(solve());
    return 0;
}