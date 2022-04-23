#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define pb push_back
#define pii pair<int,int>
#define S second
#define F first
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
const int maxn = 1e6+50;
int val[maxn] , bit[maxn];
//BIT
#define lb(x) (x&-x)
void upd(int i){
	for( ; i<maxn ; i+=lb(i))
		bit[i]++;
}
int qry(int i,int res=0){
	for( ; i ; i-=lb(i))
		res += bit[i];
	return res;
}
signed main(){
	IOS;
	int n; cin >> n , n<<=1;
	long long ans = 0ll;
	fill(val , val+n+1 , -1);
	for(int i=1 ; i<=n ; ++i){
		int x; cin >> x;
		if(val[x] == -1){
			val[x] = qry(x-1);
		}
		else{
			ans += qry(x-1) - val[x];
		}
		upd(x);
	}
	cout << ans << '\n';
}