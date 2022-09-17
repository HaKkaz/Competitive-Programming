#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define _ <<' '<<
#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second
#define tiii tuple<int,int,int>
using ll = long long;
using ld = long double;
using pii = pair<int,int>;

const int MAXN = 2e5+50;

int sn;
struct Query { 
  int id, L, R , Bk;
  Query(){}
  Query(int i, int l, int r):
    id(i), L(l), R(r){
    	Bk = l/sn;
    }
  bool operator<(const Query &b) const {
  	if(Bk != b.Bk) return Bk < b.Bk;
  	else return R < b.R;
  }
}qs[MAXN];


inline int read(){
	int res = 0 , f = 1; char ch = getchar_unlocked();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f; ch=getchar_unlocked();}
	while(ch>='0'&&ch<='9') res=(res<<3)+(res<<1)+(ch^48),ch=getchar_unlocked();
	return res*f;
}
inline void print(long long x){
	if(x == 0) {putchar_unlocked(48);return;}
	int len=0,dg[20];
	while(x>0){dg[++len]=x%10;x/=10;}
	for(int i=len ; i>=1 ; --i)putchar_unlocked(dg[i]+48);
}

long long cval[MAXN];
long long ans[MAXN];
int c[MAXN] , w[MAXN];
priority_queue< pair<long long,int> > pq;

inline void sub(const int &c , const int &w){
	while(pq.size() && cval[pq.top().sd] != pq.top().ft) pq.pop();
	cval[c] -= w;
	pq.emplace(cval[c] , c);
}

inline void add(const int &c , const int &w){
	while(pq.size() && cval[pq.top().sd] != pq.top().ft) pq.pop();
	cval[c] += w;
	pq.emplace(cval[c] , c);
}

signed main(){
	int n = read(); sn = sqrt(n*3/2);
	for(int i=0 ; i<n ; ++i) c[i] = read();
	for(int i=0 ; i<n ; ++i) w[i] = read();

	int q = read();
	for(int i=0 ; i<q ; ++i){
		int l = read(), r = read();
		--l,--r;
		qs[i] = Query(i,l,r);
	}
	sort(qs , qs + q);
	pq.emplace(0,0);
	int L = 0 , R = -1;
	for(int i=0 ; i<q ; ++i){
	    while(R < qs[i].R) ++R,add(c[R],w[R]);
	    while(L > qs[i].L) --L,add(c[L],w[L]);
	    while(R > qs[i].R) sub(c[R],w[R]),--R;
	    while(L < qs[i].L) sub(c[L],w[L]),++L;
	    ans[qs[i].id] = pq.top().ft;
	}

	for(int i=0 ; i<q ; ++i){
		print(ans[i]);
		puts("");
	}
}