#include <iostream>
#include <array>
using namespace std;
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int n,x; cin >> n;
	array<int,501> cnt;
	cnt.fill(0);
	for(int i=0 ; i<n ; ++i){
		cin >> x;
		cnt[x]++;
	}
	int tot=0;
	for(int i=1 ; i<=500 ; ++i){
		tot += cnt[i];
		if(tot >= n/2+1){
			cout << i ;
			return 0;
		}
	}
}