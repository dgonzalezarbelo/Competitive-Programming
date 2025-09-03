#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	int t = 0;
	while (n--) {
		int a, b, c;
		cin >> a >> b >> c;
		t += (a + b + c >= 2);
	}
	cout << t << '\n';
	return 0;
}