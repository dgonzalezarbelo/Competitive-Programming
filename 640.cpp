#include <iostream>

using namespace std;

using lli = long long int;

bool resuelveCaso() {
	lli N;
	int D;
	cin >> N >> D;
	if (!N && !D) return false;
	string num;
	lli pot = 1;
	while (pot * 9 <= N) {
		pot *= 9;
	}
	while (pot != 0) {
		num += N / pot + '0';
		N %= pot;
		pot /= 9;
	}
	for (char c : num) {
		if (int(c) - '0' >= D) cout << int(c) - '0' + 1;
		else cout << c;
	}
	cout << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}