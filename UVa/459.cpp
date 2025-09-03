#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <unordered_set>
using namespace std;
#pragma warning (disable:4996)

vector<bool> marks;

void dfs(vector<unordered_set<int>> const& v, int num) {
	marks[num] = true;
	for (int a : v[num]) {
		if(!marks[a])
			dfs(v, a);
	}
}

void solve() {
	char max;
	cin >> max;
	cin.get();
	int size = int(max - 'A') + 1;
	vector<unordered_set<int>> v(size);
	marks.assign(size, false);
	string line;
	getline(cin, line);
	while (line != "") {
		v[int(line[0] - 'A')].insert(int(line[1] - 'A'));
		v[int(line[1] - 'A')].insert(int(line[0] - 'A'));
		getline(cin, line);
	}
	int total = 0;
	for (int i = 0; i < size; ++i) {
		if (!marks[i]) {
			++total;
			dfs(v, i);
		}
	}
	printf("%d\n", total);
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		solve();
		if (n) printf("\n");
	}
	return 0;
}