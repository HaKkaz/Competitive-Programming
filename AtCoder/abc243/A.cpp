#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#define int long long
#define pb push_back
#define MP make_pair
#define pii pair<int,int>
#define F first
#define S second
#define SZ(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define debug(x) cerr << #x << " = "  << x << '\n';
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
signed main(){
	IOS;
	int v; cin >> v;
	int a[3]; cin >> a[0] >> a[1] >> a[2];
	for(int i=0 ;  ; i = (i+1)%3){
		if(v < a[i]){
			if(i == 0) cout << 'F';
			if(i == 1) cout << 'M';
			if(i == 2) cout << 'T';
			break;
		}
		else v -= a[i];
	}
}