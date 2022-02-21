#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define ll long long
#define pii pair<int,int>
#define Size(x) (int)x.size()
#define all(X) (X).begin(),(X).end()
#define F first
#define S second
using namespace std;
vector<int> v[1001];
bitset<1001> bt;
int ans = 0;
int BFS(int now){
	queue<int> q;
	q.push(now);
	while(!q.empty()){
		now=q.front();
		q.pop();
		for(int i=0 ; i<v[now].size() ; ++i)
			if(bt[v[now][i]]==0) q.push(v[now][i]),bt[v[now][i]]=1;
	}
	return now;
}
void dfs(int now,int cnt){
	ans = max(ans , cnt);
	for(int i=0 ; i<v[now].size() ; ++i){
		if(!bt[v[now][i]]){
			bt[v[now][i]] = 1;
			dfs(v[now][i],cnt+1);
		}
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n , x; cin >> n;

	for(int i=0 ; i<n ; ++i){
		while(cin >> x){
			if(x == -1) break;
			v[i].push_back(x);
			v[x].push_back(i);
		}
	}
	int a = BFS(0);
	bt.reset();
	dfs(a,0);
	cout << ans <<'\n';
}