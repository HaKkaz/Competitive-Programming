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

int a[1005];
signed main(){
	IOS;
	int n; while(cin >> n){
	int ans=0;
	for(int i=1 ; i<=n ; ++i){
		cin >> a[i];
		for(int j=1 ; j<i ; ++j){
			if(a[j] > a[i]) ++ans;
		}
	}
	cout << "Minimum exchange operations : "<< ans << '\n';
}
}