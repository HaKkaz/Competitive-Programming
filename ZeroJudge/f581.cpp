#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[400005];	
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n , m ; cin >> n >> m ;
	for(int i=0 ; i<n ; ++i) {
		cin >> a[i];
		a[i+n] = a[i];
	}
	//prefix sum
	for(int i=1 ; i<n*2 ; ++i){
		a[i] = a[i-1] + a[i];
	}
	int now = 0;
	while(m--){
		int need ; cin >> need;
		if(now != 0) need += a[now-1];
		int pos = lower_bound(a , a+n+n , need) - a;
		now = (pos+1)%n;
	}
	cout << now << '\n';
}