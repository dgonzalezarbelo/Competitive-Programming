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
    vvi mat(8, vi(8));
    auto torre = [&mat](int x, int y) {
        for(int i = y + 1; i < 8 && mat[x][i] != -1; i++) mat[x][i] = 0;
        for(int i = x + 1; i < 8 && mat[i][y] != -1; i++) mat[i][y] = 0;
        for(int i = y - 1; i >= 0 && mat[x][i] != -1; i--) mat[x][i] = 0;
        for(int i = x - 1; i >= 0 && mat[i][y] != -1; i--) mat[i][y] = 0;
    };
    auto alfil = [&mat] (int x, int y) {
        for(int i = 1; i < 8; i++) {
            if(!(x + i >= 0 && x + i < 8 && y + i >= 0 && y + i < 8)) break;
            if(mat[x + i][y + i] == -1) break;
            mat[x + i][y + i] = 0;
        }
        for(int i = 1; i < 8; i++) {
            if(!(x + i >= 0 && x + i < 8 && y - i >= 0 && y - i < 8)) break;
            if(mat[x + i][y - i] == -1) break;
            mat[x + i][y - i] = 0;
        }
        for(int i = 1; i < 8; i++) {
            if(!(x - i >= 0 && x - i < 8 && y + i >= 0 && y + i < 8)) break;
            if(mat[x - i][y + i] == -1) break;
            mat[x - i][y + i] = 0;
        }
        for(int i = 1; i < 8; i++) {
            if(!(x - i >= 0 && x - i < 8 && y - i >= 0 && y - i < 8)) break;
            if(mat[x - i][y - i] == -1) break;
            mat[x - i][y - i] = 0;
        }
    };
    vii cab_dirs = {{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
    auto caballo = [&mat, &cab_dirs] (int x, int y) {
        for(auto p : cab_dirs)
            if(x + p.fi >= 0 && x + p.fi < 8 && y + p.se >= 0 && y + p.se < 8)
                if(mat[x + p.fi][y + p.se] != -1) mat[x + p.fi][y + p.se] = 0;
    };
    auto peon = [&mat] (int x, int y, bool arriba) {
        int dir = arriba ? -1 : 1;
        if(y - 1 >= 0 && x + dir >= 0 && x + dir < 8) 
            if(mat[x + dir][y - 1] != -1) mat[x + dir][y - 1] = 0;
        if(y + 1 < 8 && x + dir >= 0 && x + dir < 8)
            if(mat[x + dir][y + 1] != -1) mat[x + dir][y + 1] = 0;
    };
    vii rey_dirs = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
    auto rey = [&mat, &rey_dirs] (int x, int y) {
        for(auto p : rey_dirs)
            if(x + p.fi >= 0 && x + p.fi < 8 && y + p.se >= 0 && y + p.se < 8)
                if(mat[x + p.fi][y + p.se] != -1) mat[x + p.fi][y + p.se] = 0;
    };
    int t; cin >> t; cin.get();
    while(t--) {
        mat.assign(8, vi(8, 1));
        vector<vector<char>> tablero(8, vector<char>(8, 'x'));
        string s; getline(cin, s);
        stringstream ss(s);
        string item;
        int x = 0, y = 0;
        while(getline(ss, item, '/')) {
            y = 0;
            for(char c : item) {
                if(isdigit(c)) {
                    y += c - '0';
                    continue;
                }
                tablero[x][y] = c;
                mat[x][y] = -1;
                y++;
            }
            x++;
        }
        for(int x = 0; x < 8; x++) {
            for(int y = 0; y < 8; y++) {
                char c = tablero[x][y];
                if(c == 'x') continue;
                if(c == 'p') peon(x, y, false);
                if(c == 'P') peon(x, y, true);
                if(c == 'n' || c == 'N') caballo(x, y);
                if(c == 'r' || c == 'R') torre(x, y);
                if(c == 'b' || c == 'B') alfil(x, y);
                if(c == 'q' || c == 'Q') {
                    torre(x, y); alfil(x, y);
                }
                if(c == 'k' || c == 'K') rey(x, y);
            }
        }
        int sol = 0;
        for(int i = 0; i < 8; i++) for(int j = 0; j < 8; j++) if(mat[i][j] == 1) sol++;
        cout << sol << '\n';
    }
    return 0;
}