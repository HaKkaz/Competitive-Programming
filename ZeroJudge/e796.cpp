#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
int a[200000];
signed main(){
	IOS;
	int B , P; cin >> B >> P;
	for(int i=0 ; i<P ; ++i){
		int l ,r ; cin >> l >> r;
		if(l > r)swap(l , r);
		for(int j=l ; j<=r ; ++j) a[j]++;
	}
	int MX = -1 , pos = 0 , MN = 1e9 , pos2 = 0;
	for(int i=1 ; i<=B ; ++i){
		if(a[i] < MN) MN = a[i] , pos2 = i;
	}
	for(int i=B ; i>=1 ; --i){
		if(a[i] > MX) MX = a[i] , pos = i;
	}
	swap(pos , pos2);
	cout << pos << ' ' << pos2 << '\n';
}