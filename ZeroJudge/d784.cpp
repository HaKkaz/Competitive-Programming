#include<bits/stdc++.h>
#define test_
#define PB push_back
#define S second
#define F first
#define all(x) (x).begin(),(x).end()
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define pii pair<int,int>
#define endl cout<<'\n';
const long long llMAX=2e18+20020522;
const unsigned long long ullMAX=1e19+20020522;
const int imax = 2e9+20020522;
using namespace std;
unsigned long long  p[101];
int main(){__IO
	int T; cin >> T;
	while(T--){
		int num[105]={0} , n , x;
		cin >> n;
		for(int i=1 ; i<=n ; ++i) cin >> x , num[i] = num[i-1]+x;
		int ans = -111111111;
		for(int i=1 ; i<=n ; ++i){
			for(int j=0 ; j<i ; ++j){
				ans = max(num[i]-num[j] , ans);
			}
		}
		cout << ans <<'\n';
	}	
}