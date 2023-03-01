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

bool resuelveCaso(){
    string a, b, c;
    cin >> a >> b >> c;
    if(!cin) return false;
    while(sz(a) < 10) a = "0" + a;
    while(sz(b) < 10) b = "0" + b;
    while(sz(c) < 10) c = "0" + c;
    string sol;
    bool ok = true;
    for(int i = 0; i < 10 && ok; i++){
        if(a[i] != b[i] && a[i] != c[i] && b[i] != c[i]) ok = false;
        else{
            if(a[i] == b[i] || a[i] == c[i]) sol += a[i];
            else sol += b[i];
        }
    }
    if(ok){
        bool ponCero = false;
        for(char c : sol){
            if(c != '0') {
                cout << c;
                ponCero = true;
            }
            else if(ponCero) cout << c;
        }
        if(!ponCero) cout << "0";
        cout << '\n';
    }
    else cout << "RUIDO COSMICO\n";
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(resuelveCaso());
    return 0;
}