#include<bits/stdc++.h>
using namespace std;
bitset<2500> tab[2500];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n; cin >> n; 
	for(int i=0 ; i<n ; ++i){
		int m; cin >> m;
		while(m--){
			int j; cin >> j;
			tab[i][j] = 1;
		}
	}
	int ans =0 ;
	for(int i=0 ; i<n ; ++i){
		for(int j=i+1 ; j<n ; ++j){
			if((tab[i] & tab[j]).any())
				++ans;
		}
	}
	cout << ans << '\n';
}