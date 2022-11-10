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
int n , x , ans;
signed main(){__IO
	cin >> n >> x;
	for(int i=1 ; i<=n ; ++i){
		int now = i;
		while(now){
			if(now%10 == x) ++ans;
			now /= 10;
		}
	}
	cout << ans << '\n';
}