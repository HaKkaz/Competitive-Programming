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
int main(){__IO
	int n;
	while(cin >> n){
		deque<int> dq;
		rep(0 , n , i){
			int x; cin >> x;
			dq.pb(x);
		}
		while(dq.size()){
			for(auto &c : dq) cout << c << ' ';
				et
			dq.pop_front();
				reverse(all(dq));
		}
	}
}