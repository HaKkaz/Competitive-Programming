#include<iostream>
using namespace std;
int main(){
	int a, b;
	while(cin >> a >> b){
		int ans=0;
		bool ok = true;
		if(a == 1) a++;
		for(int i = a ; i<=b ; ok = true,i++){
			for(int j = 2 ; (j*j<=i && ok ); j++){
				if(!(i%j)) ok = false;
			}
			if(ok) ++ans;
		}
		cout << ans << '\n';
	}
}