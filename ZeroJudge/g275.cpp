#include<iostream>
using namespace std;
int main(){
	int n; cin >> n;
	for(int i=0 ; i<n ; ++i)
	{
		int a[7];
		int b[7];
		for(int j=0 ; j<7 ; ++j) cin >> a[j];
		for(int j=0 ; j<7 ; ++j) cin >> b[j];

		string ans = "";
		//A
		if(a[1]==a[3] || a[1]!=a[5] || b[1]==b[3] || b[1]!=b[5]) ans += 'A';

		//B
		if(!a[6] || b[6]) ans += 'B';

		//C
		if(a[1]==b[1] || a[3]==b[3] || a[5]==b[5]) ans += 'C';

		cout << (ans == "" ? "None" : ans) << '\n';
	}
}