#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#define int long long
#define pb push_back
#define MP make_pair
#define pii pair<int,int>
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
signed main(){
	int n = read() , m = read();
	vector<int> mx[m+1];
	for(int i=0 ; i<n ; ++i){
		int a=read() , b=read();
		if(a > m) continue;
		mx[a].push_back(b);
	}
	for(int i=0 ; i<m ; ++i) while(mx[i].size() < 4) mx[i].push_back(0);
	for(int i=0 ; i<m ; ++i){
		sort(all(mx[i]));
		while(mx[i].size() >= 2){
			int x1 = mx[i].back(); mx[i].pop_back();
			int x2 = mx[i].back(); mx[i].pop_back();
			mx[i+1].push_back(x1+x2);
		}
	}
	sort(all(mx[m]));
	print(mx[m].back());
}