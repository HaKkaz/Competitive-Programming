#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
using namespace std;
int a[100005];
signed main(){
	int n;
	while(~scanf("%d" , &n)){
		long long sum = 0 , ans = 0;
		for(int i=0 ; i<n ; ++i) scanf("%d" , &a[i]);
		sort(a , a+n);
		for(int i=0 ; i<n ; ++i){
			ans += 1ll * i * a[i] - sum;
			sum += a[i];
		}
		printf("%lld\n" , ans);
	}
}