#include<bits/stdc++.h>
using namespace std;

int main(){
	int a, b ; cin >> a >> b;
	unsigned long long ans = 0;
	if(a>b) swap(a,b);
	for(int i=a ; i<=b ; i++){
		if(!(i%2)) ans += i;
	}
	cout<<ans<<'\n';
}