#include <iostream>
#include <fstream>
#include <vector>
#pragma warning (disable:4996)
using namespace std;

long long int resolver(long long int x, long long int y, long long int radio, long long int cx, long long int cy) {
	if (radio == 1) {
		if ((x - cx) * (x - cx) + (y - cy) * (y - cy) <= radio * radio) return 1;
		else return 0;
	}
	else {
		long long int sol = 0;
		if ((x - cx) * (x - cx) + (y - cy) * (y - cy) <= radio * radio) sol++;
		if (x - cx >= y - cy) {
			if (x - cx >= cy - y) return sol + resolver(x, y, radio / 2, cx + radio, cy);
			else return sol + resolver(x, y, radio / 2, cx, cy - radio);
		}
		else {
			if (x - cx >= cy - y) return sol + resolver(x, y, radio / 2, cx, cy + radio);
			else return sol + resolver(x, y, radio / 2, cx - radio, cy);
		}
	}

}

bool resuelveCaso() {
	long long int radio, x, y;
	if (scanf("%lld %lld %lld", &radio, &x, &y) == EOF) return false;
	printf("%lld\n", resolver(x, y, radio, 0, 0));
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}