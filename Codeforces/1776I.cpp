#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <deque>
#include <numeric>
#include <algorithm>
#include <climits>
#pragma warning (disable : 4996)
using namespace std;

#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define mp make_pair

const double EPS = 1e-9;
const double INF = 1e18; //1e18 tambien suele ir bien
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

void solve(){
    int n; cin >> n;
    bool turn;
    if(n % 2 == 0){
        cout << "Alberto\n" << flush;
        turn = true;
    }
    else{
        cout << "Beatrice\n" << flush;
        turn = false;
    }
    vector<pair<ll,ll>> v(n);
    vi remaining;
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
        remaining.push_back(i);
    }
    for(int i = 0; i < n - 2; i++){
        if(turn){
            double minimo = INF;
            int index = -1;
            for(int j = 0; j < sz(remaining); j++){
                ii a = v[remaining[j]], b = v[remaining[(j + 1) % sz(remaining)]], c = v[remaining[(j + sz(remaining) - 1) % sz(remaining)]];
                double la, lb, lc;
                la = sqrt(ll(b.fi - c.fi) * ll(b.fi - c.fi) + ll(b.se - c.se) * ll(b.se - c.se));
                lb = sqrt(ll(a.fi - c.fi) * ll(a.fi - c.fi) + ll(a.se - c.se) * ll(a.se - c.se));
                lc = sqrt(ll(b.fi - a.fi) * ll(b.fi - a.fi) + ll(b.se - a.se) * ll(b.se - a.se));
                double p = (la + lb + lc) / 2.0;
                double area = sqrt(p*(p-la)*(p-lb)*(p-lc));
                if(area < minimo){
                    minimo = area;
                    index = remaining[j];
                }
            }
            cout << index + 1 << '\n' << flush;
            vi aux;
            for(int j = 0; j < sz(remaining); j++){
                if(remaining[j] != index) aux.push_back(remaining[j]);
            }
            remaining = aux;
        }
        else{
            int index; cin >> index;
            index--;
            vi aux;
            for(int j = 0; j < sz(remaining); j++){
                if(remaining[j] != index) aux.push_back(remaining[j]);
            }
            remaining = aux;
        }
        turn = !turn;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}