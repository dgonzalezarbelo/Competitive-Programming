#include <iostream>
#include <vector>
using namespace std;

bool solve(){
	long long n,d; cin >> n >> d;
	if(!n && !d) return false;
	int sol = 0;
	long long i = 0;
	for(long long h = 2; i < 10000; h++) {
		i = n * h;
		bool ok =true;
		vector<bool> v(10,false);
		long long m = i;
		while(m) {
			if(v[m%10]) ok = false;
			v[m%10] = true;
			m/=10;
		}
		if(!ok) continue;
		if(i % n != 0 && n % i != 0) continue;
		if(i > n) {
			m = i / n;
			m *= d;
		}
		else {
			m = n / i;
			if(d%m!=0) continue;
			m = d / m;
		}
		while(m) {
			if(v[m%10]) ok = false;
			v[m%10] = true;
			m/=10;
		}
		if(!ok) continue;
		for(int b = 1; b <10;b++)
			if(!v[b]) ok = false;
		if(v[0]) continue;
		if(ok)sol++;
	}
	cout<<sol<<"\n";
	return true;
}

int main(){
	while(solve());
	return 0;
}