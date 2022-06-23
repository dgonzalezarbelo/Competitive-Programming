#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	while (n--) {
		int a;
		cin >> a;
		if (a % 100 == 0) cout << a / 100 << '\n';
		else cout << a / 100 + 1 << '\n';
	}
	return 0;
}