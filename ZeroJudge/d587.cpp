#include<iostream>
using namespace std;
signed cnt[10];
int main(){
	int n; cin >> n ;
	int x;
	for(int i=0 ; i<n ; ++i) cin >> x , cnt[x]++;
	while(cnt[1]) cout << 1 << ' ' , cnt[1]--;
	while(cnt[2]) cout << 2 << ' ' , cnt[2]--;
	while(cnt[3]) cout << 3 << ' ' , cnt[3]--;
}