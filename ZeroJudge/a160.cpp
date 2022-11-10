#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define ll long long
#define pii pair<int,int>
#define Size(x) (int)x.size()
#define all(X) (X).begin(),(X).end()
#define F first
#define S second
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
int mp[12][12] , vis[12][12] , ans = 0;
void init(int n){
	for(int i=0 ; i<n ; ++i)
		for(int j=0 ; j<n ; ++j)
			mp[i][j] = 0 ,vis[i][j] = 0;
}
void modify(int x , int y , int n , int add){
	for(int i=0 ; i<n ; ++i){
		vis[x][i] += add , vis[i][y] += add;
	}
	vis[x][y] -= add;
	int a1=x , a2 = x , b1 = y , b2 = y;
	while(a1>0 && b1>0) vis[--a1][--b1] += add;
	while(a2<n-1 && b2<n-1) vis[++a2][++b2] += add;
	a1=x , a2 = x , b1 = y , b2 = y;
	while(a1>0 && b1<n-1) vis[--a1][++b1] += add;
	while(a2<n-1 && b2>0) vis[++a2][--b2] += add; 
}
void output(int n){
	for(int i=0 ; i<n ; ++i){
		for(int j=0 ; j<n ; ++j){
			if(mp[i][j] == 0) cout << "x";
			else cout << "Q";
		}
		cout <<'\n';
	}
	cout << '\n';
}
void dfs(int x, int y , int n , int cnt){	
	if(vis[x][y] == 0 && cnt && mp[x][y] == 0){
		int a,b;
		--cnt , mp[x][y] = 1 , modify(x,y,n,1);
		if(cnt){
			if(y+1 < n) a=x ,b=y+1 , dfs(a,b,n,cnt);
			else if(x+1 < n) b=0 , a=x+1 , dfs(a,b,n,cnt);
		}
		else { output(n),++ans; }

		++cnt , mp[x][y] = 0 , modify(x,y,n,-1) ;
	}
	int a,b;
	if(y+1 < n) a=x,b=y+1,dfs(a,b,n,cnt);
	else if(x+1<n) b=0,a=x+1,dfs(a,b,n,cnt);
	else return ;
}
int main(){
__IO
	int n ;
	while(cin >> n && n){
		ans = 0;init(n);
		dfs(0,0,n,n);
		cout<< ans <<'\n'<<'\n';
	}
}