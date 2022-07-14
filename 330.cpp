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
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<pair<int, int>>;
using ll = long long;
using vll = vector<long long int>;

unordered_map <string, int> posiciones;

bool resuelveCaso() {
    int n;
    cin >> n;
    if (!n) return false;
    string nota;
    int primero = 100, ultimo = -1;
    vector<int> cantidades(100);
    int posicion;
    while (n--) {
        cin >> nota;
        string subnota = nota.substr(0, nota.size() - 1);
        posicion = posiciones[subnota] + int(nota[nota.size() - 1] - '0') * 12;
        if (subnota == "Si#") posicion += 12;
        if (subnota == "Dob") posicion -= 12;
        cantidades[posicion]++;
        if (posicion < primero) primero = posicion;
        if (posicion > ultimo) ultimo = posicion;
    }
    for (int i = primero; i <= ultimo; i++) {
        if (i != primero) cout << " ";
        cout << cantidades[i];
    }
    cout << '\n';
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    posiciones["Do"] = 0;
    posiciones["Do#"] = 1;
    posiciones["Reb"] = 1;
    posiciones["Re"] = 2;
    posiciones["Re#"] = 3;
    posiciones["Mib"] = 3;
    posiciones["Mi"] = 4;
    posiciones["Fab"] = 4;
    posiciones["Mi#"] = 5;
    posiciones["Fa"] = 5;
    posiciones["Fa#"] = 6;
    posiciones["Solb"] = 6;
    posiciones["Sol"] = 7;
    posiciones["Sol#"] = 8;
    posiciones["Lab"] = 8;
    posiciones["La"] = 9;
    posiciones["La#"] = 10;
    posiciones["Sib"] = 10;
    posiciones["Si"] = 11;
    posiciones["Si#"] = 0;
    posiciones["Dob"] = 11;
    while (resuelveCaso());
    return 0;
}