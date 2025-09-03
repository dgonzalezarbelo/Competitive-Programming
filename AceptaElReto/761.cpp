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

const ll inf = LLONG_MAX;
struct Ed { int a, b, w; int s() { return a < b ? a : -a; }};
struct Node { ll dist = inf; int prev = -1;};

void bellmanFord(vector<Node>& nodes, vector<Ed>& eds, int s) {
	nodes[s].dist = 0;
	sort(all(eds), [](Ed a, Ed b) { return a.s() < b.s(); });

	int lim = sz(nodes) / 2 + 2; // /3+100 with shuffled vertices
	rep(i,0,lim) for (Ed ed : eds) {
		Node cur = nodes[ed.a], &dest = nodes[ed.b];
		if (abs(cur.dist) == inf) continue;
		ll d = cur.dist + ed.w;
		if (d < dest.dist) {
			dest.prev = ed.a;
			dest.dist = (i < lim-1 ? d : -inf);
		}
	}
	rep(i,0,lim) for (Ed e : eds) {
		if (nodes[e.a].dist == -inf)
			nodes[e.b].dist = -inf;
	}
}

vector<vector<char>> mat;

vii dirs_exterior = {{1,0},{0,1}, {-1,0},{0,-1}};

bool resuelveCaso() {
    int w, h; cin >> w >> h;
    if(!cin) return false;
    mat.assign(h, vector<char>(w, '0'));
    set<ii> agujeros;
    vector<Node> nodes(w * h);
    vector<Ed> eds;
    rep(i,0,h) {
        rep(j,0,w) {
            cin >> mat[i][j];
            if(mat[i][j] == 'O') {
                agujeros.insert(mp(i,j));
            }
        }
    }
    rep(i,0,h) {
        rep(j,0,w) {
            if(mat[i][j] == '#') continue;
            if(agujeros.count(mp(i,j))) {
                int a, b, c; cin >> a >> b >> c;
                a--; b--;
                eds.push_back({i * w + j, b * w + a, c});
            }
            else {
                if(i == h - 1 && j == w - 1) continue;
                for(auto d : dirs_exterior) {
                    ii next = {i + d.first, j + d.second};
                    if(next.first >= 0 && next.first < h && next.second >= 0 && next.second < w) {
                        if(mat[next.first][next.second] == '#') continue;
                        eds.push_back({i * w + j, next.first * w + next.second, 1});
                    }
                }
            }
        }
    }
    bellmanFord(nodes, eds, 0);
    rep(i,0,h) {
        rep(j,0,w) {
            if(nodes[i * w + j].dist == -inf) {
                cout << "EXPLOSION\n";
                return true;
            }
        }
    }
    if(nodes[w * h - 1].dist == inf) cout << "IMPOSIBLE\n";
    else cout << nodes[w * h - 1].dist << '\n';
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(resuelveCaso());
    return 0;
}