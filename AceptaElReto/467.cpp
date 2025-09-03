#include <iostream>
#include <string>
using namespace std;
#pragma warning (disable : 4996)
void resuelveCaso(){
	string A, B;
	string aux;
	string a, b;
	cin >> A >> aux >> B;
	for (int i = 0; i < A.size(); i++) {
		a.push_back(tolower(A[i]));
	}
	for (int i = 0; i < B.size(); i++) {
		b.push_back(tolower(B[i]));
	}
	a == b ? printf("TAUTOLOGIA\n") : printf("NO TAUTOLOGIA\n");
}

int main() {
	int num;
	scanf("%d", &num);
	scanf("\n");
	for (int i = 0; i < num; i++) resuelveCaso();
	return 0;
}