#include<bits/stdc++.h>
#define test_
#define PB push_back
#define S second
#define F first
#define all(x) (x).begin(),(x).end()
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define pii pair<int,int>
#define endl cout<<'\n';
const long long llMAX=2e18+20020522;
const unsigned long long ullMAX=1e19+20020522;
const int imax = 2e9+20020522;
using namespace std;
char mp[505][505];
int n , m ,cnt = 0 ,ans = 0, dx[]={1,0,-1,0} , dy[]={0,1,0,-1};
void init(){
	cnt=0 , ans = 0;
}
struct T
{
	int x , y;
};
bool check(int a , int b){
	if(a>=0&&a<=n&&b>=0&&b<=m&&mp[a][b]=='J') return true;
	return false;
}
void BFS(){
	for(int i=0 ; i<n ; ++i){
		for(int j=0 ; j<m ; ++j){
			int ct=0;
			if(mp[i][j]=='J'){
				queue<T> q;
				q.push(T{i,j}) , mp[i][j]='#' , ++cnt , ++ct;
				while(q.size()){
					T now=q.front(); q.pop();
					for(int i=0 ; i<4 ; ++i){
						if(check(now.x+dx[i],now.y+dy[i])) 
							q.push(T{now.x+dx[i],now.y+dy[i]}) , mp[now.x+dx[i]][now.y+dy[i]]='#', ++ct;
					}
				}
				while(q.size()) q.pop();
			}
			ans = max(ans , ct);
		}
	}

}
int main(){
__IO
	while(cin >> n >> m){
		init();
		for(int i=0;  i<n; ++i)
			for(int j=0 ; j<m ; ++j)
				cin >> mp[i][j];
		BFS();
		cout<<cnt<<' '<<ans<<'\n';
	}
}