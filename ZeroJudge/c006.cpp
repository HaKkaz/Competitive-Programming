#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int now , a, b ,c ;
	while(cin >> now >> a >> b >>c){
		if(!(now||a||b||c)) return 0;
		int sum = 0;
		if(now<a) sum += (now+40-a);//順
		else sum += (now-a);
		now = a;
		if(now>b) sum += (40-now+b);//逆
		else sum += (b-now);
		now = b;
		if(now<c) sum += (now+40-c);//順
		else sum += (now-c);
		sum += 120;
		cout << sum*9 <<'\n';
	}
}