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
#pragma warning (disable : 4996)
using namespace std;

vector<pair<int, char>> basura;
int k;

bool comprobar(int m) {
    int maxE = 2 * m, maxR = m;
    int pesoE = 0, pesoR = 0;
    int total = 0;
    for (auto p : basura) {
        if (p.second == 'E') {
            if (pesoE + p.first <= maxE) pesoE += p.first;
            else {
                if (p.first > maxE) return false;
                pesoE = p.first;
                pesoR = 0;
                total++;
            }
        }
        else {
            if (pesoR + p.first <= maxR) pesoR += p.first;
            else {
                if (p.first > maxR) return false;
                pesoE = 0;
                pesoR = p.first;
                total++;
            }
        }
        if (total > k) return false;
    }
    if (pesoE || pesoR) total++;
    return total <= k;
}

bool resuelveCaso() {
    int n;
    cin >> k >> n;
    if (!k && !n) return false;
    int peso;
    char tipo;
    basura.clear();
    int maxE = 0, maxR = 0;
    int sumaE = 0, sumaR = 0;
    int i, f;
    while (n--) {
        cin >> peso >> tipo;
        basura.push_back({ peso, tipo });
        if (tipo == 'E') {
            sumaE += peso;
            if (peso > maxE) maxE = peso;
        } 
        else {
            sumaR += peso;
            if (peso > maxR) maxR = peso;
        }
    }
    i = max(maxE / 2 + maxE % 2, maxR);
    f = max(sumaE / 2 + sumaE % 2, sumaR) + 1;
    int m = f;
    while (i + 1 < f) {
        m = (i + f - 1) / 2;
        if (comprobar(m)) {
            f = m + 1;
        }
        else {
            i = m + 1;
        }
    }
    if (!comprobar(i)) i++;
    cout << i << '\n';
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (resuelveCaso());
    return 0;
}