#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define ll long long
#define pii pair<int,int>
#define Size(x) (int)x.size()
#define all(X) (X).begin(),(X).end()
#define F first
#define S second
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
const int INF = 1000000007;
int main(){
__IO
	int n; cin >> n;
	int num[100005];
	int mx[100005] , mn[100005] , mxx =-INF , mnn=INF;
	for(int i=0 ; i<n ; ++i){
		cin >> num[i];
		mxx = max(mxx , num[i]),mx[i]=mxx;
	}
	for(int i=n-1 ; i>=0 ; --i){
		mnn = min(mnn , num[i]),mn[i]=mnn;
	}
	int ans = 0;
	for(int i=0 ; i<n ; i++){
		ans = max(ans,mx[i]-mn[i]);
	}
	cout << ans <<'\n';
}