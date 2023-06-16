#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
vector<bool> visited;
vector<unordered_set<int>> al;
int ciclos;
vector<int> discovery;
int timer;

void dfs(int a,int prev){
	discovery[a]=timer++;
	visited[a]=true;
	int sol = 0;
	for(int b:al[a]){
		if(prev !=b) {
			if(visited[b] && discovery[b]<discovery[a]) ciclos++;
			if(!visited[b]) dfs(b,a);
		}
	}
}

bool solve(){
	int n;cin>>n;
	if(!n) return false;
	int sol=0;
	timer = ciclos = 0;
	al.assign(n+1,{});
	visited.assign(n+1,false);
	discovery.assign(n+1,-1);
	int a,b;
	cin >>a>>b;
	while(a && b){
		if(al[a].count(b)) sol++;
		else if (a==b) sol++;
		else{
			al[a].insert(b);
			al[b].insert(a);
		}
		cin>>a>>b;
	}
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			dfs(i,0);
		}
	}
	cout << sol + ciclos << '\n';
	return true;
}

int main(){
	while(solve());
	return 0;
}