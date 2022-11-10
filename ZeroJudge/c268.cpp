#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define Sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair<int,int>
#define all(X) (X).begin(),(X).end()
#define F first
#define S second
#define endl cout<<'\n';
#define __IO ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
vector<int> v;
int x;
int main(){
__IO
	int T ;
	cin >> T;
	while(T--){
		v.clear();
		int n;
		cin >> n >> ws;
		if(n > 40){
			cout <<"YES\n";
			cin.ignore(1e9,'\n');
			continue;
		}
		for(int i=0 ; i<n ; ++i){
			cin >> x , v.pb(x);
		}
		sort(all(v));
		for(int i=0 ; i<Sz(v)-2 ; ++i){
			if(v[i]+v[i+1] > v[i+2]){
				cout << "YES\n";
				v[0] = 594879487;
				break;
			}
		}
		if(v[0] == 594879487) continue;
		cout << "NO\n";
	}	
}