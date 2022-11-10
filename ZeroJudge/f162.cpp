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
vector<vector<int>> v , a;
signed main(){
	IOS;
	int K ; cin >> K;
	int n , m; cin >> n >> m;
	v.resize(n+1 , vector<int>(m+1,0));
	a=v;
	for(int i=1 ; i<=n ; ++i)
		for(int j=1 ; j<=m ; ++j)
			cin >> a[i][j];
	int mx = 0;
	for(int l=1 ; l<=n ; ++l){
		for(int r=l ; r<=n ; ++r){
			set<int> mst;
			mst.insert(0);
			int tot=0;
			for(int j=1 ; j<=m ; ++j){
				for(int i=l ; i<=r ; ++i){
					tot += a[i][j];
				}
				auto it = mst.lower_bound(-K+tot);
				if(it != mst.end()){
					mx = max(mx , tot - *it);
				}
				mst.insert(tot);
			}
		}
	}
	cout << mx << '\n';
}