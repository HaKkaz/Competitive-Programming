#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int A,B,C;
	cin >> A >> B >> C;
	for(;A<=B;++A)
		if(A%C==0)
			return cout << A ,0;
	cout << -1 << '\n';   
}