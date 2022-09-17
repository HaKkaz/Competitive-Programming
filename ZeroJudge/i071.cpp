#include<bits/stdc++.h>
using namespace std;
int h[1005];
int main(){
	int n , p;
	cin >> n >> p ;
	for(int i=1 ; i<=n ; ++i) cin >> h[i];

	int ans = 0;
	int mxh = h[p];
	for(int i=p-1 ; i>=1 ; --i){
		if(h[i] > mxh){
			mxh = h[i];
			++ans;
		}
	}
	mxh = h[p];
	for(int i=p+1 ; i<=n ; ++i){
		if(h[i] > mxh){
			mxh = h[i];
			++ans;
		}
	}

	cout << ans << '\n';
}
