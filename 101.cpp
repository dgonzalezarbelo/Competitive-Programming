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
#include <bitset>
#pragma warning (disable : 4996)
using namespace std;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<pair<int, int>>;
using ll = long long;
using vll = vector<long long int>;

int main() {
    while (true) {
        int n;
        scanf("%d", &n);
        if (!n) break;
        vector<vi> mat(n, vi(n));
        int cuad = n * n;
        vector<bool> marks(cuad + 1, false);
        bool esoterico = true;
        bool diabolico = true;
        int cm = -1, cm2 = 0;
        int suma, aux;
        for (int i = 0; i < n; i++) {
            suma = 0;
            for (int j = 0; j < n; j++) {
                scanf("%d", &aux);
                suma += aux;
                mat[i][j] = aux;
                if (aux > cuad || marks[aux]) {
                    esoterico = false;
                }
                else {
                    marks[aux] = true;
                }
            }
            if (cm == -1) {
                cm = suma;
            }
            else if (suma != cm) diabolico = false;
        }
        if (diabolico) {
            suma = 0;
            for (int i = 0; i < n; i++) {
                suma += mat[i][i];
            }
            diabolico = (suma == cm);
            if (diabolico) {
                suma = 0;
                for (int i = 0; i < n; i++) {
                    suma += mat[i][n - i - 1];
                }
                diabolico = (suma == cm);
            }
        }
        if (diabolico) {
            if (esoterico) {
                cm2 = (4 * cm) / n;
                esoterico = ((mat[0][0] + mat[0][n - 1] + mat[n - 1][0] + mat[n - 1][n - 1]) == cm2);
                if (esoterico) {
                    if (n & 1) {    //Impar
                        esoterico = ((4 * mat[n / 2][n / 2]) == cm2);
                        if (esoterico)
                            esoterico = ((mat[0][n / 2] + mat[n / 2][0] + mat[n - 1][n / 2] + mat[n / 2][n - 1]) == cm2);
                    }
                    else {  //Par
                        esoterico = ((mat[n / 2 - 1][n / 2 - 1] + mat[n / 2 - 1][n / 2] + mat[n / 2][n / 2 - 1] + mat[n / 2][n / 2]) == cm2);
                        if (esoterico)
                            esoterico = ((mat[0][n / 2 - 1] + mat[0][n / 2] + mat[n / 2 - 1][0] + mat[n / 2][0]
                                + mat[n - 1][n / 2 - 1] + mat[n - 1][n / 2] + mat[n / 2 - 1][n - 1] + mat[n / 2][n - 1]) == 2 * cm2);
                    }
                }
            }
        }
        if (esoterico && diabolico) printf("ESOTERICO\n");
        else if (diabolico) printf("DIABOLICO\n");
        else printf("NO\n");
    }
    return 0;
}