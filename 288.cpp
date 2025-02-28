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

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

vii dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int f, c;
    while(cin >> f >> c) {
        cin.get();
        vector<vector<char>> mat(f, vector<char>(c));
        UF ufds(f * c);
        rep(i,0,f) {
            string s;
            getline(cin, s);
            rep(j,0,c) mat[i][j] = s[j];
        }
        int maximo = 0;
        rep(i,0,f) rep(j,0,c) {
            if(mat[i][j] != '#') continue;
            for(ii d : dirs) {
                int x = i + d.first, y = j + d.second;
                if(x >= 0 && x < f && y >= 0 && y < c && mat[x][y] == '#') ufds.join(i * c + j, x * c + y);
            }
            maximo = max(maximo, ufds.size(i * c + j));
        }
        cout << maximo;
        int q; cin >> q;
        while(q--) {
            int i, j; cin >> i >> j;
            i--; j--;
            mat[i][j] = '#';
            for(ii d : dirs) {
                int x = i + d.first, y = j + d.second;
                if(x >= 0 && x < f && y >= 0 && y < c && mat[x][y] == '#') ufds.join(i * c + j, x * c + y);
            }
            maximo = max(maximo, ufds.size(i * c + j));
            cout << ' ' << maximo;
        }
        cout << '\n';
    }
    return 0;
}