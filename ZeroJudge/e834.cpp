#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
 	int n; cin >> n;
 	int x;
 	while(cin >> x){
 		if(x == 0) break;
 		if(x % n == 0) cout << x / n << '\n';
 		else cout << (x+n-1)/n*n - x << '\n';
 	} 
}