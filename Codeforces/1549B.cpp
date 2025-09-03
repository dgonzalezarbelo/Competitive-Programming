#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> up(n), down(n);
		int count = 0;
		for (int i = 0; i < n; i++) {
			char a;
			cin >> a;
			up[i] = a - '0';
		}
		for (int i = 0; i < n; i++) {
			char a;
			cin >> a;
			down[i] = a - '0';
		}
		for (int i = 0; i < n; i++) {
			if (down[i]) {
				if (i > 0 && up[i - 1] == 1) {
					up[i - 1] = 2;
					count++;
				}
				else if (up[i] == 0) {
					up[i] = 2;
					count++;
				}
				else if (i < n - 1 && up[i + 1] == 1) {
					up[i + 1] = 2;
					count++;
				}
			}
		}
		cout << count << '\n';
	}
	return 0;
}