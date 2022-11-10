#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c;
	cin >> a >> b >> c;
	if((b*b-4*a*c) > 0){
		int x1,x2;
		x1 = (-b+sqrt(b*b-4*a*c))/(2*a);
		x2 = (-b-sqrt(b*b-4*a*c))/(2*a);
		if(x2 > x1) swap( x1 , x2 );
		cout<<"Two different roots " << "x1=" << x1<< " , x2=" << x2 << '\n'; 
	}
	else if((b*b-4*a*c) == 0){
		int ans = (-b/(2*a));
		cout << "Two same roots x=" << ans << '\n';
	}
	else{
		cout << "No real root" << '\n';
	}
}