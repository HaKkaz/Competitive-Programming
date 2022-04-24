#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define _ <<' '<<
#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second
#define tiii tuple<int,int,int>
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
	
signed main(){
	fast;
	int t; cin >> t;
	int Case = 1 ;
	while(t--){
		int n; cin >> n ;
		deque<int> dq(n);
		for(int &c : dq) cin >> c;
		int mx = 0 , ans = 0;
		while(dq.size()){
			while(dq.size() && dq.front() < mx) dq.pop_front();
			while(dq.size() && dq.back() < mx) dq.pop_back();

			if(dq.size() > 1){
				int a = dq.front();
				int b = dq.back();
				if(a <= b){
					dq.pop_front();
					++ans;
					mx = a;
				}
				else{
					dq.pop_back();
					++ans;
					mx = b;
				}
			}
			else if(dq.size() == 1){
				int a = dq.front();
				++ans;
				mx = a;
				dq.pop_front();
			}
		}
		cout << "Case #" << Case++ << ": " << ans << '\n';
	}
}