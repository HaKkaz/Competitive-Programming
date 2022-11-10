#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
 	int n;
 	while(cin >> n , n){
 		long long ans = 0 ;
 		for(int i=1 , j=n*2-1 ; i <= n ; ++i,j-=2)
 			ans += 1LL * i * j;
 		cout << ans << '\n';
 	}   
}