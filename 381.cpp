#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable:4996)

int mcd(int a, int b) {
	int A = a, B = b, R;
	while ((A % B) > 0) {
		R = A % B;
		A = B;
		B = R;
	}
	return B;
}

bool resuelveCaso() {
	int num;
	scanf("%d", &num);
	if (!num) return false;
	vector<int> v(num);
	for (int& x : v) scanf("%d", &x);
	int MCD = v[0], MCM = v[0];
	for (int i = 1; i < num; i++) {
		MCD = mcd(MCM, v[i]);
		MCM = (MCM * v[i]) / MCD;
	}
	printf("%d\n", MCM);
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}