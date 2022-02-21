#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#define pb push_back
#define MP make_pair
#define pii pair<int,int>
#define piii pair<int,pii>
#define F first
#define S second
#define SZ(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define debug(x) cerr << #x << " = "  << x << '\n';
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
const int maxn = 1e5+50;
const int inf = 1e9;
int ac[21][maxn] , mn[21][maxn] , fa[maxn];
int N , Q;
vector<int> v[maxn];
int Find(int x){
	if(x == fa[x]) return x;
	return fa[x] = Find(fa[x]);
}
bool Union(int a , int b){
	a = Find(a) , b = Find(b);
	if(a == b) return 1;
	fa[b] = a;
	return 0;
}
int t , in[maxn] , out[maxn];
void dfs(int now , int f){
	ac[0][now] = f;
	mn[0][now] = min(now , f);
	in[now] = ++t;
	for(int &c : v[now]){
		if(c != f){
			dfs(c , now);
		}
	}
	out[now] = ++t;
}
void build(){
	priority_queue<piii> pq;
	for(int i=1 ; i<=N ; ++i){
		for(int j=i ; j<=N ; j+=i){
			pq.push({i , {i , j}});
		}
	}
	for(int i=1 ; i<=N ; ++i) fa[i]=i;
	while(pq.size()){
		int a = pq.top().S.F , b = pq.top().S.S;
		pq.pop();
		if(!Union(a,b)){
			v[a].push_back(b);
			v[b].push_back(a);
		}
	}
	for(int i=0 ; i<21 ; ++i)for(int j=1 ; j<=N ; ++j)mn[i][j]=inf;
	dfs(1,1);
	for(int i=1 ; i<21 ; ++i){
		for(int j=1 ; j<=N ; ++j){
			ac[i][j] = ac[i-1][ac[i-1][j]];
			mn[i][j] = min(mn[i-1][j] , mn[i-1][ac[i-1][j]]);
		}
	}
}
bool is_ac(int a , int b){
	return in[a] <= in[b] && out[a] >= out[b];
}
int query(int a , int b){
	int res = inf;
	for(int i=20 ; i>=0 ; --i){
		if(!is_ac(ac[i][a] , b)){
			res = min(res , mn[i][a]);
			a = ac[i][a];
		}
		if(!is_ac(ac[i][b] , a)){
			res = min(res , mn[i][b]);
			b = ac[i][b];
		}
	}
	if(!is_ac(a , b)) res = min(res , mn[0][a]);
	if(!is_ac(b , a)) res = min(res , mn[0][b]);
	return res;
}
signed main(){
	IOS;
	cin >> N >> Q ;
	build();
	while(Q--){
		int a,b;
		cin >> a >> b;
		cout << query(a,b) << '\n';
	}
}