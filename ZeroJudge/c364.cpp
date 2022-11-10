#include<bits/stdc++.h>
#define int long long
using namespace std;

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
	
	int n = read();
	vector<int> a(n+2,0) , psum(n+2,0);
	vector<int> cnt(n+2,0);
	for(int i=1 ; i<=n ; ++i) a[i] = read();
	for(int i=1 ; i<=n ; ++i) psum[i] = psum[i-1] + a[i];

	deque<int> dq;
	for(int i=1 ; i<=n ; ++i){
		while(dq.size() and a[dq.back()] < a[i]) dq.pop_back();
		if(dq.size()) cnt[i] += psum[i-1] - psum[dq.back()];
		else cnt[i] += psum[i-1];
		dq.push_back(i);
	}

	dq.clear();
	for(int i=n ; i>=1 ; --i){
		while(dq.size() and a[dq.back()] < a[i]) dq.pop_back();
		if(dq.size()) cnt[i] += psum[dq.back()-1] - psum[i];
		else cnt[i] += psum[n] - psum[i];
		dq.push_back(i);
	}

	for(int i=1 ; i<=n ; ++i) cout << cnt[i] << '\n';
}