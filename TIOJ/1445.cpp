#include <iostream>
#include <bitset>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#define int long long
#define all(v) (v).begin(),(v).end()
#define Size(v) (int)(v).size()
#define F first
#define S second
using namespace std;
const int INF = 1e18+7;

int n , m , f[1005] , in[1005] , out[1005] , ac[30][1005] , mx[30][1005] , L , ans = INF;
long long tot = 0;
struct vertex{ long long b , w;	};
struct edge{
	int a , b , w , id;
	bool operator <(const edge &x)const{
		return w > x.w;
	}
};
bitset<5000005> used;
vector<edge> E;
vector<vertex> v[1005];

inline void init(){
	for(int i=1 ; i<=1003 ; ++i) f[i] = i;
}
int query(int x){
	if(f[x] == x) return x;
	return f[x] = query(f[x]);
}
inline bool Union(int a, int b){
	a = query(a) , b = query(b);
	if(a == b) return false;
	f[b] = f[a];
	return true;
}
inline bool kru(){
	priority_queue<edge> pq(E.begin(),E.end());
	int ct = 0;
	while(pq.size()){
		edge x = pq.top(); pq.pop();
		if(Union(x.a,x.b)){
			++ct;
			used[x.id] = 1;
			tot += x.w;
			v[x.a].push_back(vertex{x.b , x.w});
			v[x.b].push_back(vertex{x.a , x.w});
		}
	}
	if(ct == n-1) return true;
	return false;
}

int cnt = 0;
void dfs(int now , int last){
	in[now] = ++cnt;
	for(auto &c : v[now]){
		if(c.b!=last) ac[0][c.b] = now , mx[0][c.b] = c.w , dfs(c.b , now);
	}
	out[now] = ++cnt;
}

inline bool ancestor(int a , int b){
	if(in[a] <= in[b] && out[a] >= out[b]) return true;
	else return false;
}
inline void bulidLCA(){
	L = __lg(n)+1;
	ac[0][1] = 1 , mx[0][1] = 0;
	for(int i=1 ; i<=L ; ++i){
		for(int j=1 ; j<=n ; ++j){
			ac[i][j] = ac[i-1][ac[i-1][j]];
			mx[i][j] = max(mx[i-1][j] , mx[i-1][ac[i-1][j]]);
		}
	}
}
#define endl cout<<'\n';
inline void checklog(){
	for(int i=1 ; i <= n ; ++i) cout<<setprecision(3)<< i << " ";
		endl
	for(int i=0 ; i <= L ; ++i){
		for(int j=1 ; j<=n ; ++j){
			cout<<setprecision(3)<<mx[i][j]<<' ';
		}
		endl
	}
}
inline int LCA(int a , int b){
	int mxx = 0;
	if(ancestor(a , b)) return 0;

	for(int i=L ; i>=0 ; --i)
		if(!ancestor(ac[i][a],b)) mxx = max(mxx , mx[i][a]) , a = ac[i][a];
	mxx = max(mxx , mx[0][a]);
	return mxx;
}
inline void solve(){
	for(int i=0 ; i<m ; ++i){
		int sum = tot ;
		if(!used[i]){
			int x = LCA(E[i].a , E[i].b);
			int y = LCA(E[i].b , E[i].a);
			x = max(x , y);
			//cout << x << ' ' << y << ' ' <<E[i].w << '\n';
			sum = sum - x +E[i].w; //原邊-路徑最大+添加上來的邊
		}
		if(sum != tot) ans = min(ans , sum);//判斷跟最小生成樹一樣就不要
	}
	if(ans != INF) cout<<tot<< ' ' << ans<<'\n';
	else cout<<tot<<' '<<-1<<'\n';
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(0);
	cin >> n >> m ;
	for(int i=0 ; i<m ; ++i){
		int a , b , w; 
		cin >> a >> b >> w;
		E.push_back(edge{a,b,w,i});
	}

	init();
	if(!kru()) return cout<<"-1 -1\n" , 0;
	dfs(1,0);
	bulidLCA();
	//checklog();
	solve();
}