#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool resuelveCaso(){
    ll n, k; cin >> n >> k;
    if(!cin) return false;
    vector<ll> puntos(n), beneficios(n);
    for(ll & x : puntos) cin >> x;
    for(ll & x : beneficios) cin >> x;
    vector<ll> dp(n);
    vector<int> next(n, -1);
    queue<int> q;
    for(int i = 0; i < n; i++) {
        while(!q.empty() && puntos[i] >= puntos[q.front()] + k) {
            next[q.front()] = i;
            q.pop();
        }
        q.push(i);
    }
    dp[n - 1] = beneficios[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        if(next[i] != -1) dp[i] = max(dp[i + 1], dp[next[i]] + beneficios[i]);
        else dp[i] = max(beneficios[i], dp[i + 1]);
    }
    cout << dp[0] << '\n';
    return true;
}

int main(){
    while(resuelveCaso());
    return 0;
}