#include<bits/stdc++.h>
#define pii pair<int,int>
#define ft first
#define sd second
using namespace std;

const int dx[]={1,1,1,0,-1,-1,-1,0};
const int dy[]={1,0,-1,-1,-1,0,1,1};

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n , m;
	while(cin >> n >> m , n+m){
		vector< vector< char > > a(n , vector<char>(m));
		for(int i=0 ; i<n ; ++i)
			for(int j=0 ; j<m ; ++j)
				cin >> a[i][j];

		int ans = 0;
		for(int i=0 ; i<n ; ++i){
			for(int j=0 ; j<m ; ++j){
				if(a[i][j] == '0') continue;
				++ans;
				queue< pii > q;
				q.emplace(i,j);
				while(q.size()){
					int x = q.front().ft;
					int y = q.front().sd;
					q.pop();
					for(int d=0 ; d<8 ; ++d){
						int xx = x + dx[d];
						int yy = y + dy[d];
						if(xx >= 0 && xx < n && yy >= 0 && yy < m && a[xx][yy] == '1'){
							q.emplace(xx,yy);
							a[xx][yy] = '0';
						}
					}
				}
			}
		}
		cout << ans << '\n';
	}
}