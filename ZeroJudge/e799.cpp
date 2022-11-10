#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

 	int n , m ;
 	char c;
 	cin >> n >> m >> c;
 	char ans[n][m];
 	for(int i=0 ; i<n ; ++i){
 		int x; cin >> x;
 		for(int j=0 ; j<m ; ++j){
 			ans[i][j] = '.';
 			if(x >> j & 1){
 				ans[i][j] = c;
 			}
 		}
 	} 
 	for(int i=0 ; i<n ; ++i){
 		for(int j=m-1 ; j>=0 ; --j){
 			cout << ans[i][j] << " \n"[j==0];
 		}
 	}
}