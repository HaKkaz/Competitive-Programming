#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
int dis[500005];
int n , m , k ;
struct tiii{int x ,y ,w;};
vector<tiii> v;


int f(int x){
	return ( (dis[x]==x) ? (x) : (dis[x]=f(dis[x])) );
}

bool Greater(const tiii &a,const tiii &b){
		return a.w==b.w ? (a.x==b.x ? a.y<b.y : a.x<b.x) : a.w<b.w ;
}
bool Less(const tiii &a,const tiii &b){
		return a.w==b.w ? (a.x==b.x ? a.y<b.y : a.x<b.x) : a.w>b.w ;
}

int krl(){
	for(int i=1 ; i<=n ; ++i) dis[i]=i;
	int cnt=1 , ans=0;
	for(auto i:v){
		int a=f(i.x),b=f(i.y);	
		if(a==b) continue;
		dis[b]=dis[a];
		ans+=i.w;
		if(++cnt==n) return ans;
	}
	return -1;
}
int main(){
__IO
	cin >> n >> m >> k;
	while(m--){
		int x ,y ,w;
		cin >> x >> y >> w;
		v.push_back((tiii){x,y,w});
	}
	sort(all(v),Greater);
	int mn =krl();
	sort(all(v),Less);
	int mx=krl();
	if(k<=mx && k>=mn) puts("TAK\n");
	else puts("NIE\n");
}
