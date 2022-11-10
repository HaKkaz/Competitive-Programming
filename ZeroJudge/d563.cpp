#include<bits/stdc++.h>	
#pragma GCC optimize ("Ofast")
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair<int,int>
#define all(X) (X).begin(),(X).end()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define et cout<<'\n';
#define __IO ios::sync_with_stdio(false),cin.tie(0);
#define rep(a , b , c) for(int c = a ; c < b ; ++c)
using namespace std;
vector<int> num;
vector<int> pre , suf;
int n , x , ans;
int main(){__IO
	cin >> n ;
	rep(0 , n , i) cin >> x , num.pb(x);
	pre.pb(num[0]);
	suf.pb(num[n-1]);
	rep(1 , n , i){
		pre.pb(pre.back()+num[i]);
	}
	for(int i=n-2 ; i>=0 ; --i){
		suf.pb(suf.back()+num[i]);
	}
	for(auto &c : suf){
		auto l = lower_bound(all(pre) , c);
		auto r = upper_bound(all(pre) , c);
		if(*l == c){
			ans += r - l;
		}
	}
	cout << ans << '\n';
}