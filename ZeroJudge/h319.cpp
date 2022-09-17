#include<stdio.h>
#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")

inline int read(){
	int res = 0 , f = 1; char ch = getchar_unlocked();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f; ch=getchar_unlocked();}
	while(ch>='0'&&ch<='9') res=(res<<3)+(res<<1)+(ch^48),ch=getchar_unlocked();
	return res*f;
}
inline void print(int x){
	if(x == 0) {putchar_unlocked(48);return;}
	int len=0,dg[20];
	while(x>0){dg[++len]=x%10;x/=10;}
	for(int i=len ; i>=1 ; --i)putchar_unlocked(dg[i]+48);
}

const int maxn = 5000005;

//linked-list
int nxt[maxn];
int pre[maxn];


//disjoint set
int dsu[maxn];
bool sit[maxn];
int Find(int x){
	return (x == dsu[x] ? x : dsu[x] = Find(dsu[x]));
}
void merge(int a , int b){
	a = Find(a);
	b = Find(b);
	if(a == b) return;
	dsu[b] = a;
}

int main(){
	int n = read() , q = read();
	nxt[n] = -1;
	for(int i=1 ; i<=n ; ++i){
		dsu[i] = i;
		if(i > 1) pre[i] = i-1;
		if(i < n) nxt[i] = i+1;
	}
	while(q--){
		char ch = getchar_unlocked();
		int x = read();
		getchar_unlocked(); // read '\n'
		
		if(ch == '?'){
			x = Find(x);
			if(!sit[x]) print(x);
			else if(nxt[x] == -1) putchar_unlocked('-'),putchar_unlocked('1');
			else print(nxt[x]);
			putchar_unlocked('\n');
		}
		else{
			sit[x] = 1;
			if(nxt[x] != -1 && sit[nxt[x]]){
				int boss = Find(nxt[x]);
				merge(boss , x);
				if(pre[x] != -1) nxt[pre[x]] = boss;
				pre[boss] = pre[x];
			}
			if(pre[x] != -1 && sit[pre[x]]){
				int boss = Find(x);
				merge(boss , pre[x]);
				if(pre[x] != -1) nxt[pre[x]] = boss;
				pre[boss] = pre[x];
			}
		}
	}
}