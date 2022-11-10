#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
const int mod = 10007;
int pow2[500005];
signed main(){
	IOS;
	int L;
	pow2[0]=1;
	for(int i=1,j=2 ; i<=500004 ; ++i,j<<=1 , j %= mod) pow2[i]=j%mod;
	while(cin >> L){
		int ans = 0ll;		
		for(int i=0 ; i<=L ; ++i){
			if(i%2 != L%2) continue;
			if(L/2 - i/2 == 0) ++ans;
			else if(L/2-i/2 >= 0) ans += pow2[L/2-i/2-1] , ans %= mod;
		}
		cout << ans << '\n';
	}
}