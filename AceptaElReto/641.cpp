#include <iostream>
#include <queue>
using namespace std;
using lli = long long int;
#pragma warning (disable : 4996)

bool resuelveCaso() {
	int i, n;
	scanf("%d %d", &i, &n);
	if (!i && !n) return false;
	queue<lli> q;
	lli acum = 0;
	lli max = -1;
	lli nuevo;
	while (n--) {
		scanf("%lld", &nuevo);
		acum += nuevo;
		q.push(nuevo);
		if (q.size() > i) {
			acum -= q.front();
			q.pop();
		}
		if (acum > max) max = acum;
	}
	printf("%lld\n", max);
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}