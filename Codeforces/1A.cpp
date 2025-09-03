#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <iomanip>
#include <climits>
#include <cmath>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>

using namespace std;

int main() {
	long long m, n, a;
	cin >> m >> n >> a;
	long long i, j;
	if (m % a == 0) i = m / a;
	else i = m / a + 1;
	if (n % a == 0) j = n / a;
	else j = n / a + 1;
	cout << i * j << '\n';
	return 0;
}