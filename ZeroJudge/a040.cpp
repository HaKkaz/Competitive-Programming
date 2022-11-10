#include<iostream>
using namespace std;
int count[10];
int fpow(int a , int p){
	int ret = 1;
	for( ; p ; p>>=1 , a = a * a)
		if(p & 1)
			ret = ret * a;
	return ret;
}
int main(){
	int l,r;
	cin >> l >> r;
	bool have = 0 ;
	for(int i=l ; i<=r ; ++i){
		int k = 0 , x = i;
		while(x) x/=10 , ++k;

		int sum = 0;
		x = i;
		while(x){
			int y = x % 10 , ret = 0;
			sum += fpow(y , k);
			x /= 10; 
		}
		if(i == sum){
			have = true;
			cout << i << ' ';
		}
	}
	if(!have) cout << "none\n";
	cout << '\n';
}