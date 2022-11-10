#include<bits/stdc++.h>
#define test_
#define PB push_back
#define S second
#define F first
#define all(x) (x).begin(),(x).end()
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define pii pair<int,int>
using namespace std;
const int MOD = 10007;
long long fpow(long long x,long long p){
	if(p==1) return x%MOD;
	if(p%2) return ((x%MOD)*(fpow((x%MOD)*(x%MOD),p/2)%MOD)%MOD);
	return (fpow((x%MOD)*(x%MOD),p/2)%MOD);
}
int main(){
//__IO
	long long  n , k; cin >> n >> k;
	long long ans = fpow(n,k)%MOD;
	cout << ans%MOD <<'\n';
}