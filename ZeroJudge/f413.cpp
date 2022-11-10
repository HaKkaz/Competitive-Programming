#include<cstdio>
#include<algorithm>
#pragma GCC optimize("Ofast,unroll-loops,fast-math")
using namespace std;
const int inf = 1e9;
inline int read(){
	int res = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f; ch=getchar();}
	while(ch>='0'&&ch<='9') res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
	return res*f;
}
inline void print(int x){
	if(x == 0) {putchar(48);return;}
	int len=0,dg[20];
	while(x>0){dg[++len]=x%10;x/=10;}
	for(int i=len ; i>=1 ; --i)putchar(dg[i]+48);
}
int now=0;
struct query
{
	int a,b,x,id;
	bool operator<(const query &tmp)const{
		return x < tmp.x;
	}
}q[100005],edge[10005];
int dis[105][105] , ans[100005];
inline void upd(int &a , int b){if(a > b) a = b;}
signed main(){
	int n=read(),m=read(),Q=read();
	for(int i=0 ; i<m ; ++i){
		edge[i].a=read() , edge[i].b=read() , edge[i].x=read();
	}
	for(int i=0 ; i<Q ; ++i){
		q[i].id = i , q[i].x=read() , q[i].a=read() , q[i].b=read();
	}
	sort(q , q+Q);
	for(int x=0 ; x<n ; ++x){
		if(now == Q) break;
		if(q[now].x != x) continue;
		for(int i=0 ; i<n ; ++i)for(int j=0 ; j<n ; ++j)if(i!=j)dis[i][j] = inf;
		for(int i=0 ; i<m ; ++i){
			int a = edge[i].a , b = edge[i].b , w = edge[i].x;
			if(a != x and b != x){
				upd(dis[a][b],w);
			}
		}
		for(int k=0 ; k<n ; ++k){
			for(int i=0 ; i<n ; ++i){
				for(int j=0 ; j<n ; ++j){
					upd(dis[i][j] , dis[i][k] + dis[k][j]);
				}
			}
		}
		while(now<Q && q[now].x == x){
			ans[q[now].id] = dis[q[now].a][q[now].b];
			++now;
		}
	}
	for(int i=0 ; i<Q ; ++i){
		if(ans[i] != inf) print(ans[i]) , putchar('\n');
		else puts("-1");
	}
}