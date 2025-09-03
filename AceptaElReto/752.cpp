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
    int p, n;
    while(cin >> p >> n && p && n) {
        vi v(n);
        int sum = 0;
        rep(i,0,n) {
            cin >> v[i];
            sum += v[i];
        }
        if(sum < p) {
            cout << "NO ENTRAN\n";
            continue;
        }
        sum = v[0];
        int i = 0, j = 0;
        int total = INT_MAX, primero = -1;
        while(j < n) {
            if(sum < p) {
                j++;
                if(j < n)
                    sum += v[j];
            }
            else {
                if(j - i + 1 < total) {
                    total = j - i + 1;
                    primero = i + 1;
                }
                else if(j - i + 1 == total && i < primero) {
                    primero = i + 1;
                }
                sum -= v[i];
                i++;
            }
        }
        cout << total << ' ' << primero << '\n'; 
    }
    return 0;
}