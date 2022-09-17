#include<bits/stdc++.h>
#define test_
#define pb push_back
#define S second
#define F first
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define pii pair<int,int>
#define et cout<<'\n';
#define rep(i , n) for(int mm=i ; mm<n ; ++mm)
using namespace std;
int dx[]={-1,-1,-1,0,0,1,1,1} , dy[]={1,0,-1,-1,1,0,-1,1};
int G[1005][1005] , ans , cnt , nowcolor[4] , n;
bool vis[3][1005][1005];
struct P
{
	int x , y , t;
};
queue<P> q[5];
int color(char c){
	if(c == 'Y') return 1;
	if(c == 'R') return 3;
	if(c == 'B') return 5;
	if(c == 'O') return 4;
	if(c == 'P') return 8;
	if(c == 'G') return 6;
	if(c == 'D') return 18;
}
bool check(int a , int b , int now){
	if(a>=0 && a<n && b>=0 && b<n && vis[now][a][b] == 0) return 1;
	return 0;
}
void init(int n){
	ans = cnt = 0;
	for(int j=0 ; j<n ; ++j){
		for(int k=0 ; k<n ; ++k){
			vis[0][j][k] = 0;
			vis[1][j][k] = 0;
			vis[2][j][k] = 0;
			G[j][k] = 0;
		}
	}
	for(int i=0 ; i<3 ; ++i){
		nowcolor[i] = 0;
		while(q[i].size()) q[i].pop();
	}
}
int main(){
__IO
		cin >> n;
		for(int i=0 ; i<3 ; ++i){
			char c;
			int x , y;
			cin >> c >> x >> y;
			G[x][y] = color(c);
			q[i].push({x , y , 0});
			if(c == 'Y') nowcolor[i] = 1;
			if(c == 'R') nowcolor[i] = 3;
			if(c == 'B') nowcolor[i] = 5;
			vis[i][x][y] = 1;
		}
		char c;
		cin >> c;
		int need = color(c);
		if(c == 'Y' || c == 'R' || c == 'B') cnt = 1;
		for(int tms=0 ; tms<=n ; ++tms)
		{
			for(int now = 0 ; now<3 ; ++now)
			{
				while(q[now].size() && q[now].front().t == tms){
					int a = q[now].front().x , b = q[now].front().y;
					q[now].pop();
					for(int i=0 ; i<8 ; ++i){
						int x = a+dx[i] , y = b+dy[i];
						if(check(x , y , now)){
							q[now].push({x , y , tms+1});
							if(G[x][y] == need) --cnt;
							G[x][y] += nowcolor[now];
							if(G[x][y] == need) ++cnt;
							vis[now][x][y] = 1;
						}
					}
				}
			}
			ans = max(ans , cnt);
		}
		cout << ans << '\n';
	
}