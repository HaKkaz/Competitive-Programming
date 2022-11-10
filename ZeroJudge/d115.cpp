#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
vector<int> v , __;
void dfs(int now , int num){
	__.push_back(v[now]);
	if(num == 1){
		for(int i=0 ; i<(int)__.size() ; ++i) cout<<__[i]<<' ';
		cout<<'\n';
	}
	else for(int i=now+1 ; i<n ; ++i) dfs(i , num-1);
	__.pop_back();
}
bool cmp(int a, int b){return a<b;}
main(){
	ios::sync_with_stdio(false) , cin.tie(0);
	while(cin >> n&&n){
		v.clear();
		for(int i=0 ; i<n ; ++i) cin >> m , v.push_back(m);
		sort(v.begin(),v.end(),cmp);
		cin >> m;
		for(int i=0 ; i<n ; ++i) dfs(i , m);
			cout << '\n';
	}
}