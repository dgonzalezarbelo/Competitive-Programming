#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable:4996)

vector<int> posibles(20001, -1);

bool solve(int operacion) {
	if (posibles[operacion] != -1) return posibles[operacion];
	else {
		if (operacion == 1) return true;
		else {
			if (operacion % 3 == 0 && solve(operacion / 3)) return posibles[operacion] = 1;
			else if (operacion > 5 && solve(operacion - 5)) return posibles[operacion] = 1;
			else return posibles[operacion] = 0;
		}
	}
}

bool resuelveCaso() {
	int num;
	scanf("%d", &num); 
	if (!num) return false;
	solve(num) ? printf("SI\n") : printf("NO\n");
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}