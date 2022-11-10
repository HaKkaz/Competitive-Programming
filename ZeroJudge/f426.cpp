#define pii pair<int,int>
#define F first
#define S second
#include<bits/stdc++.h>
using namespace std;
const int maxn = 100000;
int is_prime[maxn];
signed main(){
	fill(is_prime , is_prime+maxn , 1);
	is_prime[1] = 0;
	is_prime[0] = 0;
	for(int i=2 ; i*i<maxn ; ++i){
		for(int j=i*i ; j<maxn ; j+=i){
			is_prime[j] = 0;
		}
	}
	int n , m; cin >> n >> m ;
	int ans = 0 , cnt = 0;
	for(int i=n ; i<=m ; ++i) ans += is_prime[i]?i:0 , cnt += is_prime[i];
	cout << cnt << '\n';
	cout << ans << '\n';
}