#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long int dif(long long int A, long long int B, long long int C) {
	long long int maximo = abs(A - B);
	maximo = max(maximo, abs(A - C));
	maximo = max(maximo, abs(B - C));
	return maximo;
}

bool solve() {
	int n;
	cin >> n;
	if (!cin) return false;
	vector<int> v(n);
	long long int A = 0, B = 0, C = 0;
	int b = n, c = n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		A += v[i];
	}
	B = v[n - 2]; b = n - 2;
	C = v[n - 1]; c = n - 1;
	A -= v[n - 1]; A -= v[n - 2];
	long long int maxDif = dif(A, B, C);
	while (b > 0) {
		b--;
		B += v[b];
		A -= v[b];
		maxDif = min(maxDif, dif(A, B, C));
		while (abs(B - C) >= abs(B - v[c] - C - v[c]) && b < c) {
			B -= v[c - 1];
			C += v[c - 1];
			c--;
			maxDif = min(maxDif, dif(A, B, C));
		}
		if (maxDif == 0) break;
	}
	cout << maxDif << '\n';
	return true;
}

int main() {
	while (solve());
	return 0;
}