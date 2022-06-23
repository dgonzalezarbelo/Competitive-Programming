#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable :4996)

typedef pair<int, int> ii;

struct comp {
	bool operator ()(ii const& p1, ii const& p2) {
		return p1.first - p1.second < p2.first - p2.second;
	}
};

void resuelveCaso() {
	int longitud, num;
	scanf("%d %d", &longitud, &num);
	vector<ii> v(num);
	for (ii& p : v) scanf("%d %d", &p.first, &p.second);
	sort(v.begin(), v.end(), comp());
	int inicio = 0;
	for (ii p : v) {
		if (p.first - p.second > inicio) {
			printf("NO\n");
			return;
		}
		if (p.first + p.second + 1 > inicio) inicio = p.first + p.second + 1;
	}
	if (inicio > longitud) printf("SI\n");
	else printf("NO\n");
}

int main() {
	int num;
	scanf("%d", &num);
	while (num--) resuelveCaso();
	return 0;
}