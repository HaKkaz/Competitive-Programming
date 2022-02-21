#include<cstdio>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
inline void read(int &res){
	res=0; char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
}
void write(int x){
    if(!x) return;
    write(x/10);
    putchar(x%10+'0');
}
const int maxn = 2e5+50;
inline int min(const int &a , const int &b){return a<b?a:b;}
inline void swap(int &a , int &b){int tmp=a; a=b,b=tmp;}
struct tree
{
	struct edge
	{
		int to , nxt;
		edge(){to=nxt=0;}
		edge(int _to , int _nxt):to(_to),nxt(_nxt){}
	};
	int depth[maxn<<1]={0} , pos[maxn<<1]={0} , id[maxn<<1];
	int head[maxn]={0} , cnt=0 , cnt2=0;
	edge v[maxn<<1];
	tree(){}
	inline void addedge(const int &a , const int &b){
		v[++cnt].nxt = head[a];
		v[cnt].to = b;
		head[a] = cnt;
		v[++cnt].nxt = head[b];
		v[cnt].to = a;
		head[b] = cnt;
	}
	void dfs(int now=0 , int fa=0){
		depth[now] = depth[fa]+1;
		pos[now] = ++cnt2;
		id[cnt2] = now;
		for(int i=head[now] ; i ; i = v[i].nxt){
			if(v[i].to != fa){
				dfs(v[i].to , now);
				id[++cnt2] = now;
			}
		}
	}
}G;
int f[22][maxn];
void build_ST(){
	for(int i=1 ; i<=G.cnt2 ; ++i) f[0][i] = G.depth[G.id[i]];
	for(int i=1 ; i<=21 ; ++i){
		for(int j=1 ; j+(1<<i) <= G.cnt2 ; ++j){
			f[i][j] = min(f[i-1][j] , f[i-1][j+(1<<(i-1))]);
		}
	}
}
int query(int a , int b){
	if(a > b) swap(a,b);
	int k = 31-__builtin_clz(b-a+1);
	return min(f[k][a] , f[k][b-(1<<k)+1]);
}
int a , b;
signed main(){
	int n, m ; read(n),read(m);
	// if(n >= 2000) return 0;
	for(int i=1 ; i<n ; ++i){
		read(a),read(b);
		G.addedge(a , b);
	}
	G.dfs();
	build_ST();
	while(m--){
		read(a),read(b);
		int sum = G.depth[a] + G.depth[b];
		a=G.pos[a] , b=G.pos[b];
		if(a > b) swap(a,b);
		printf("%d",sum - (query(a,b)<<1));
		// write(sum-(ans<<1));
		putchar('\n');
	}
}	