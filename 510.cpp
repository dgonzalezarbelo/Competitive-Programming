#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

bool resuelveCaso() {
	int num;
	scanf("%d", &num);
	if (!num) return false;
	vector <int> pos, neg;
	vector <bool> signos(num, false);
	int aux;
	for (int i = 0; i < num; i++){
		scanf("%d", &aux);
		if (aux > 0) {
			pos.push_back(aux);
			signos[i] = true;
		} 
		else neg.push_back(aux);
	}
	int a = 0, b = neg.size() - 1;
	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());
	for (int i = 0; i < num - 1; i++) {
		if (signos[i]) {
			printf("%d ", pos[a]);
			a++;
		}
		else {
			printf("%d ", neg[b]);
			b--;
		}
	}
	if (signos[signos.size() -1]) printf("%d\n", pos[pos.size() - 1]);
	else printf("%d\n", neg[0]);
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}