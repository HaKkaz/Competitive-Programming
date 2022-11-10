#include"bits/stdc++.h"
#define pb push_back
#define mp make_pair
#define int long long
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define rz(x) resize(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define endl cout<<'\n';
#define LINE cout<<"--------------------------\n";
#define loli ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
const int maxn = 500001;
char ch[505][505] , need;
bool vis[505][505];
map<char , int> ans;
int dx[]={0 , 0 , 1 , -1} , dy[]={1 , -1 , 0 , 0} , n , m;
inline bool check(int x , int y){return(x>=0 and x<n and y>=0 and y<m and !vis[x][y]);}
inline void bfs(int x ,int y){
	queue<pii> q;
	q.push({x , y});
	vis[x][y] = 1;
	need = ch[x][y];
	while(q.size()){
		int a = q.front().F , b = q.front().S;
		q.pop();
		for(int i=0 ; i<4 ; ++i){
			if(check(a+dx[i],b+dy[i]) and ch[a+dx[i]][b+dy[i]] == need){
				vis[a+dx[i]][b+dy[i]]=1;
				q.push({a+dx[i],b+dy[i]});
			}
		}
	}
	ans[need]++;
}
bool cmp(const pair<int,char> &x , const pair<int,char> &y){
	if(x.F != y.F) return x.F > y.F;
	else return x.S < y.S;
}
inline void latina(){
	loli;
	int t ; cin >> t;
	int cnt = 1;
	while(t--){
		ans.clear();
		cin >> n >> m ;
		for(int i=0 ; i<n ; ++i)
			for(int j=0 ; j<m ; ++j)
				cin >> ch[i][j] , vis[i][j]=0;
		for(int i=0 ; i<n ; ++i){
			for(int j=0 ; j<m ; ++j){
				if(!vis[i][j]){
					bfs(i,j);
				}
			}
		}
		vector<pair<int,char>> p;
		for(auto &c : ans) p.pb({c.S , c.F});
		sort(all(p),cmp);
		cout << "World #" << cnt++ << '\n';
		for(auto &c : p) cout << c.S << ": " << c.F << '\n';
	}

}
signed main(){latina();}