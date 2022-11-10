//LCA 2018/12/16 nA-lIN - HaKkaz.an
#include<bits/stdc++.h>
#define PB push_back
#define S second
#define F first
#define Size(v) (int)(v).size()
#define all(x) (x).begin(),(x).end()
#define __IO ios::sync_with_stdio(false),cin.tie(0);
#define endl cout<<'\n';
using namespace std;

const int L =20, R=1000005 ;
int times , n , q , lg , depth[1000005] , in[1000005] , out[1000005] , ac[L][R];
vector<int> v[1000005];

inline void dfs(int now,int dis,int last){
	depth[now]=dis; 
	in[now] = ++times;
	for(auto &c:v[now])
		if(c!=last) ac[0][c] = now , dfs(c,dis+1,now);
	out[now] = times;
}

inline void addedge(int a , int b){
	v[a].PB(b) , v[b].PB(a);
}

//build prefix n->test maxn
inline void build(int n){
	ac[0][1] = 1;//as vertex 1 to be the root
	for(int i=1 ; i<=lg ; ++i){
		for(int j=1 ; j<=n ; ++j){
			ac[i][j] = ac[i-1][ac[i-1][j]];
		}
	}
}
//check a,b if in the same subtree
inline bool ancestor(int a,int b){
	if(in[a]<=in[b] && out[a]>=out[b]) return true;
	return false;
}
//return a,b LCA
inline int LCA(int a ,  int b){
	if(ancestor(a,b)) return a;
	for(int i=lg ; i>=0 ; --i){
		if(!ancestor(ac[i][a] , b)) a = ac[i][a];
	}
	return ac[0][a];
}

int main(){
__IO
	cin >> n >> q ;
	lg = (floor)(log(n)/log(2));

	for(int i=1 ; i<=n ; ++i){
		int x;
		while(cin >> x && x){
			addedge(i,x);
		}
	}
	dfs(1,1,0);
	build(n);
	/*
	cout<<"------------------------------------\n";
	for(int i=1; i<=12 ; ++i) cout<<i<<' ';endl
	for(int i=0 ; i<=4 ; ++i){
		for(int j=1 ; j<=n ; ++j){
			cout<<ac[i][j]<<' ';
		}
		endl
	}
	*/
	
	for(int i=0 ; i<q ; ++i){	
		int a , b;
		cin >> a >> b;
		int diss , ans = LCA(a , b);
		diss=depth[a]+depth[b]-depth[ans]*2;
		cout<<ans<<' '<<diss<<'\n';
	}
}