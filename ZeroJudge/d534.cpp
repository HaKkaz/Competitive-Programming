#include <bits/stdc++.h>
using namespace std;

int a[]={0,1,2,3};

int main(){
	int x[2] , y[2];
	cin >> x[0] >> x[1];
	cin >> y[0] >> y[1];

	bool solve = false;

	do{
		if(a[0] + a[1] == x[0] && a[2] + a[3] == x[1] && a[0] + a[2] == y[0] && a[1] + a[3] == y[1]){
			cout << a[0] << ' ' << a[1] << endl;
			cout << a[2] << ' ' << a[3] << endl;
			solve = true;
			break;
		}
	}while(next_permutation(a , a + 4));

	if(!solve) cout << "No solutions." << endl;
}
