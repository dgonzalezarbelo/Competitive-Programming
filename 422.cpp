#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


using ll = long long;
using vll = vector<ll>;
const ll mod = 46337;
vll dp;
vector<vll> comb;

ll combinatorio(int n, int m){
    if(m == 0 || m == n) return 1;
    if(comb[n][m] != -1) return comb[n][m];
    return comb[n][m] = (combinatorio(n - 1, m - 1) + combinatorio(n - 1, m)) % mod;
}

ll solve(int n){
    if(n < 0) return 0;
    if(dp[n] != -1) return dp[n];
    ll sol = 0;
    for(int i = 1; i <= n; i++){
        ll aux = ((solve(n - i) % mod) * combinatorio(n, i)) % mod;
        sol = (sol + aux) % mod;
    }
    return dp[n] = sol;
}

bool resuelveCaso(){
    int n; cin >> n;
    if(!cin) return false;
    cout << solve(n) << '\n';
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    dp.assign(3001,-1);
    comb.assign(3001, vll(3001,-1));
    dp[0] = 1;
    while(resuelveCaso());
    return 0;
}