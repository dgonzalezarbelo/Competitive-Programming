#include <iostream>
using namespace std;
#pragma warning(disable:4996)
int resolver(int num) {
	if (num < 10) {
		printf("%d", num);
		return num;
	} 
	else {
		int sol = resolver(num / 10);
		printf(" + %d", num % 10);
		sol += num % 10;
		return sol;
	}
}
bool resuelveCaso() {
	int num;
	scanf("%d", &num);
	if (num < 0)return false;
	printf(" = %d\n", resolver(num));
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}