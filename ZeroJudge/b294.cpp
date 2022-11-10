#include<bits/stdc++.h>
#define int long long
//#define test_
#define MP make_pair
#define pb push_back
#define S second
#define F first
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define pii pair<int,int>
#define et cout<<'\n';
#define rep(i , n) for(int mm=i ; mm<n ; ++mm)
using namespace std;
#define int long long
signed main(){
//__IO
	int n;
	while(cin >> n){
		long long ans = 0;
		for(int i=1 ; i<=n ; ++i){
			int x; cin >> x;
			ans += x * i;
		}
		cout << ans << '\n';
	}
}