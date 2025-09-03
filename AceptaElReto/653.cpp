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
using lli = long long int;
using vlli = vector<long long int>;

bool resuelveCaso() {
	int n;
	cin >> n;
	if (!n) return false;
	int inicio = 1;
	queue<int> q;
	int actual = 0;
	int mejorTiempo = INT_MAX;
	int mejorInicio = 1;
	int mejorPunto = 0;
	int puntoActual = 0;
	while (n--) {
		int aux;
		cin >> aux;
		actual += aux;
		q.push(aux);
		puntoActual += 100;
		if (q.size() > 10) {
			actual -= q.front();
			inicio += q.front();
			q.pop();
		}
		if (q.size() == 10) {
			if (actual <= mejorTiempo) {
				mejorTiempo = actual;
				mejorInicio = inicio;
				mejorPunto = puntoActual - 1000;
			}
		}
	}
	printf("%d-%d %d:", mejorPunto, mejorPunto + 1000, mejorTiempo / 60);
	if (mejorTiempo % 60 < 10) printf("0");
	printf("%d\n", mejorTiempo % 60);
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}