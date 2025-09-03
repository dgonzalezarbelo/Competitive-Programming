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

class UnionFind {
private:
    vector<int> p, rank;
    int numSets;
public:
    UnionFind(int N) {
    rank.assign(N, 0);
    p.assign(N, 0);
    for (int i = 0; i < N; ++i) p[i] = i;
        numSets = N;
    }
    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) p[y] = x;
        else {
            p[x] = y;
            if (rank[x] == rank[y]) ++rank[y];
        }
        --numSets;
        }   
    }   
    int numDisjointSets() {
        return numSets;
    }
    int sizeOfSet(int i) {
        int res = 0;
        for (int j = 0; j < p.size(); ++j) {
            if (isSameSet(i, j)) ++res;
        }
        return res;
    }
};

bool resuelveCaso(){
    int n, m; cin >> n >> m;
    if(!cin) return false;
    string s;
    UnionFind ufds(n * m);
    int maximo = 0;
    for(int i = 0; i < n; i++){
        getline(cin, s);
        for(int j = 0; j < n; j++){
            
        }
    }
    return true;
}

int main() {
    while(resuelveCaso());
    return 0;
}