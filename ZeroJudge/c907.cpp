#include<bits/stdc++.h>
#define S second
#define F first
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define pii pair<long long,long long>
using namespace std;
stack<pii> stk;
long long n ,ans = 0 , x;
int main(){
//__IO
	cin >> n;
	for(int i=0 ; i<=n ; ++i){
		if(i < n) cin >> x;
		else x = 0;
		if(stk.empty() || stk.top().F < x) stk.push({x , i});
		else{
			int last = i;
			while(stk.size() && stk.top().F > x){
				last = stk.top().S;
				ans = max(ans , stk.top().F * (i - stk.top().S));
				stk.pop();
			}
			stk.push({x , last});
		}
	}
	cout << ans << '\n';
}/*
13
2 3 4 8 8 8 4 3 3 4 5 1 0
*/