#include <bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
#define endl cout<<'\n';
#define fast ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
int dx[]={0 , 0 , 1 , -1} , dy[]={1 , -1 , 0 , 0} , n , m , MN = 1e9;
int num[105][105];
bool vis[105][105];
pair<int,int> pos;

bool check(int x , int y){
	return(x >= 0 and x<n and y>=0 and y<m and !vis[x][y]);
}

int main(){fast;
	cin >> n >> m ;
	for(int i=0 ; i<n ; ++i){
		for(int j=0 ; j<m ; ++j){
			cin >> num[i][j];
			if(num[i][j] < MN) pos = {i , j} , MN = num[i][j];
		}
	}
	int ans = 0;
	while(1){
		int x = pos.F , y = pos.S;
		vis[x][y] = 1;
		ans += num[x][y];
		pos.F = -1 , pos.S = -1 , MN = 1e9;
		for(int i=0 ; i<4 ; ++i){
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(check(xx , yy)){
				if(num[xx][yy] < MN){
					MN = num[xx][yy];
					pos.F = xx , pos.S = yy;
				}
			}
		}
		if(pos.F == -1) break;
	}
	cout << ans << '\n';
}