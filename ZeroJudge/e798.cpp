#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
 	int n; cin >> n;
 	int a[n][n];
 	for(int i=0 ; i<n ; ++i){
 		for(int j=0 ; j<n ; ++j){
 			cin >> a[i][j];
 		}
 	}  
 	int ans[n/2][n/2];
 	for(int i=0 ; i<n/2 ; ++i)for(int j=0 ; j<n/2 ; ++j) ans[i][j] = -2147483648;
 	for(int i=0 ; i<n ; ++i){
 		for(int j=0 ; j<n ; ++j){
 			ans[i/2][j/2] = max(ans[i/2][j/2] , a[i][j]);
 		}
 	}
 	for(int i=0 ; i<n/2 ; ++i){
 		for(int j=0 ; j<n/2 ; ++j){
 			cout << ans[i][j] << ' ';
 		}
 		cout << '\n';
 	}
}