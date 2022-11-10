#include"bits/stdc++.h"
#define int long long
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define rz(x) resize(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
using namespace std;
vector<pii> a;
inline int read(){
	int f=1 , res=0; char ch = getchar_unlocked();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-f; ch=getchar_unlocked();}
	while(ch>='0'&&ch<='9') res=(res<<3)+(res<<1)+(ch^48) , ch=getchar_unlocked();
	return res*f;
}
inline void latina(){
	int t;
	cin >> t;
	while(t--){
		int n , k , ans = 0 , tot = 0; n=read(),k=read() ;
		a.rz(n);
		for(int i=0 ; i<n ; ++i) a[i].F=read();
		for(int i=0 ; i<n ; ++i) a[i].S=read() , tot+=a[i].S;
		stable_sort(all(a));
		for(int i=0,now=0 ; i<n ; ++i){
			while(now<n and a[now].F - a[i].F <= k) tot -= a[now].S , now++;
			ans += tot * a[i].S;
		}
		cout << ans << '\n';
	}
}
signed main(){latina();}