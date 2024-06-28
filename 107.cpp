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

const int MAX_PR = 100000;
bitset<MAX_PR> isprime;
vi eratosthenesSieve(int lim) {
    isprime.set(); isprime[0] = isprime[1] = 0;
    for (int i = 4; i < lim; i += 2) isprime[i] = 0;
    for (int i = 3; i*i < lim; i += 2) if (isprime[i])
        for (int j = i*i; j < lim; j += i*2) isprime[j] = 0;
    vi pr;
    rep(i,2,lim) if (isprime[i]) pr.push_back(i);
    return pr;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    vi primes = eratosthenesSieve(MAX_PR);
    vector<double> inv = {1, .1, .01, .001, .0001, .00001};
    while(cin >> n >> m && n) {
        if(m == 1) {
            cout << "Menor\n";
            continue;
        }
        auto it = upper_bound(all(primes), n);
        int pi = it - primes.begin();
        double error = abs((double) pi / n - (double) 1 / log(n));
        if(error < inv[m])
            cout << "Menor\n";
        else if(error == inv[m])
            cout << "Igual\n";
        else
            cout << "Mayor\n";
    }
    return 0;
}