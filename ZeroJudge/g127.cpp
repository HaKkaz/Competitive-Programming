#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t; cin >> t;
    while(t--){
	 	int n; cin >> n ;
	 	vector<int> cnt(200000,0);
	 	bool ok = 0;   
	 	for(int x,i=0 ; i<n ; ++i) cin >> x , x += 60000 , cnt[x]++ , ok |= (cnt[x] > n/2);
	 	cout << (ok ? "No\n" : "Yes\n");
	}
}