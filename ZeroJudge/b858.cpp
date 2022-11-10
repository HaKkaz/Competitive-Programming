#include<bits/stdc++.h>
#define test_
#define pb push_back
#define S second
#define F first
#define Sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define pii pair<int,int>
#define endl cout<<'\n';
#define rep(i , n) for(int mm=i ; mm<n ; ++mm)
using namespace std;
int main(){
__IO
	int n , T;
	cin >> T;
	while(T--){
		cin >> n;
		int tot = 0 ;
		bitset<100005> b;
		b[0] = 1;
		for(int i=0 ; i<n ;++i){
			int x;
			cin >> x;
			tot += x;
			for(int i=100000 ; i>=0 ; --i){
				if(b[i]){
					b[i+x] = 1;
				}
			}
		}
		int ans = 1e9+7;
		for(int i=0 ; i<100000 ; ++i){
			if(b[i] && max(i , tot - i) < ans){
				ans = max(tot - i , i);
			}
		}
		cout << ans << '\n';
	}	
}