#include"bits/stdc++.h"
#define int long long
using namespace std;
inline int read() {
	int ret=0,f=1;char ch=getchar_unlocked();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-f;ch=getchar_unlocked();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar_unlocked();
	return ret*f;
}
int dp[(1<<3)][(1<<3)];
inline void latina(){
	ios::sync_with_stdio(false),cin.tie(0);
	int n=read();
	dp[0][0]=1;
	for(int i=1 ; i<=n ; ++i){
		int k=read() , a=read() , b=read() , c=read() , x=0,y=0;
		k--;
		if(a) y|=1; 
		if(b) y|=2; 
		if(c) y|=4;
		x |= (1<<k);
		for(int A=(1<<3)-1 ; A>=0 ; --A){
			for(int B=(1<<3)-1 ; B>=0 ; --B){
				if((A|x) != A){
					dp[A|x][B|y] += dp[A][B];
				}
			}
		}
	}
	cout << dp[(1<<3)-1][(1<<3)-1] << '\n';
}
signed main(){latina();}