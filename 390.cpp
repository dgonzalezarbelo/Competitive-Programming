#include <iostream>
#pragma warning (disable :4996)
#include <string>

using namespace std;

int main() {
	int num;
	scanf("%d", &num);
	while (num--) {
		int M, A, C;
		scanf("%d %d %d", &M, &A, &C);
		string cad;
		cin >> cad;
		for (int i = 0; i < cad.size(); i++) {
			if (cad[i] == 'M') M--;
			else if (cad[i] == 'A') A--;
			else if (cad[i] == 'C') C--;
			else if (cad[i] == 'R') {
				A--;
				M--;
			}
			else if (cad[i] == 'N') {
				M--;
				A--;
				C--;
			}
			else if (cad[i] == 'V') {
				A--;
				C--;
			}
			else if (cad[i] == 'L') {
				M--;
				C--;
			}
			if (A < 0 || M < 0 || C < 0) break;
		}
		if (A < 0 || M < 0 || C < 0) printf("NO\n");
		else printf("SI %d %d %d\n", M, A, C);
	}
	return 0;
}