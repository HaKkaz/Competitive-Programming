#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define int long long
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
const int maxn = 5005;
struct T
{
	int x , y , id;
	T(){}
	T(int _x , int _y , int _id):x(_x),y(_y),id(_id){}
	bool operator<(const T &tmp)const{
		return x < tmp.x;
	}
}v[maxn];
int ans = 0ll , res[2];
bool has[maxn][maxn];
signed main(){
	IOS;
	int n;
	while(cin >> n){
		for(int i=1 ; i<=n ; ++i)for(int j=1 ; j<=n ; ++j)has[i][j]=0;
		ans=0ll , res[0]=res[1]=0;
		for(int i=1 ; i<=n ; ++i){
			cin >> v[i].x >> v[i].y , v[i].id = i;
		}
		set<T> pts;
		for(int i=1 ; i<=n ; ++i){
			int x = v[i].x , y = v[i].y;
			vector<T> a,b,c,d;
			for(auto &tmp : pts){
				if(tmp.x < x && tmp.y > y){
					while(sz(a) && a.back().y > tmp.y) a.pop_back();
					a.push_back(tmp);
				}
				if(tmp.x < x && tmp.y < y){
					while(sz(b) && b.back().y < tmp.y) b.pop_back();
					b.push_back(tmp);
				}
				if(tmp.x > x && tmp.y > y && (c.empty() || c.back().y > tmp.y)){
					c.push_back(tmp);
				}
				if(tmp.x > x && tmp.y < y && (d.empty() || d.back().y < tmp.y)){
					d.push_back(tmp);
				}
			}
			for(auto &tmp : a) has[tmp.id][v[i].id] = 1 , ++ans;
			for(auto &tmp : b) has[tmp.id][v[i].id] = 1 , ++ans;
			for(auto &tmp : c) has[tmp.id][v[i].id] = 1 , ++ans;
			for(auto &tmp : d) has[tmp.id][v[i].id] = 1 , ++ans;
			for(int ii=0 ; ii<sz(a) ; ++ii){
				for(int jj=0 ; jj<sz(d) ; ++jj){
					int id1 = a[ii].id , id2 = d[jj].id;
					if(id1 > id2) swap(id1 , id2);
					if(has[id1][id2]) --ans , has[id1][id2] = 0;
				}
			}
			for(int ii=0 ; ii<sz(b) ; ++ii){
				for(int jj=0 ; jj<sz(c) ; ++jj){
					int id1 = b[ii].id , id2 = c[jj].id;
					if(id1 > id2) swap(id1 , id2);
					if(has[id1][id2]) --ans , has[id1][id2] = 0;
				}
			}
			pts.insert(v[i]);
			res[i&1] += ans;
		}
		cout << res[1] << ' ' << res[0] << '\n';
	}
	
}