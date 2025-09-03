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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, b;
    while(cin >> a >> b && a && b) {
        ll ini = a, fin = b, sol = a;
        while(ini <= fin) {
            ll mid = (ini + fin) / 2;
            ll ca = 0, cb = 0, cmid = 0;
            
            ll pow = 1;
            while(pow <= b) {
                cb += b - pow + 1;
                pow *= 10;
            }

            pow = 1;
            while(pow <= mid) {
                cmid += mid - pow + 1;
                pow *= 10;
            }

            a--;
            pow = 1;
            while(pow <= a) {
                ca += a - pow + 1;
                pow *= 10;
            }
            a++;

            cb -= cmid;
            cmid -= ca;

            // cout << "mid  -> " << mid << endl;
            // cout << "cmid -> " << cmid << endl;
            // cout << "cb   -> " << cb << endl;

            if(cmid <= cb) {
                sol = mid;
                ini = mid + 1;
            }
            else fin = mid - 1;
        }
        cout << sol << '\n';
    }   
    return 0;
}