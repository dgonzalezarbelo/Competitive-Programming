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

int M = 24;
int N = 5;

bool resuelveCaso() {
    int A;
    cin >> A;
    if (!A) return false;
    int a, b, c, d, e;
    a = A % 19;
    b = A % 4;
    c = A % 7;
    d = (19 * a + M) % 30;
    e = (2 * b + 4 * c + 6 * d + N) % 7;
    int dia;
    string mes;
    if (d + e < 10) {
        dia = d + e + 22;
        mes = "marzo";
    }
    else {
        dia = d + e - 9;
        mes = "abril";
    }
    if (dia == 26 && mes == "abril") dia = 19;
    else if (dia == 25 && mes == "abril" && d == 28) dia = 18;
    cout << dia << " de " << mes << '\n';
    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}