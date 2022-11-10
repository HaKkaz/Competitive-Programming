#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,fast-math")
#define int long long
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
signed main(){
	IOS;
	int n , m ; 
	while(cin >> n >> m){
		if(m == 0){
			cout << "Go Kevin!!\n";
			// else cout << "No Stop!!\n";
			continue;
		}
		for(int i=1 ; n>0 ; i+=m){
			n -= i;
		}
		if(n == 0) cout << "Go Kevin!!\n";
		else cout << "No Stop!!\n";
	}
}