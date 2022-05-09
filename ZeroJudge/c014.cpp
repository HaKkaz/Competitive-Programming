#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define _ <<' '<<
#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second
#define tiii tuple<int,int,int>
using ll = long long;
using ld = long double;
using pii = pair<int,int>;

signed main(){
	fast;
	int a,b;
	while(cin >> a >> b , a+b){
		int carry=0 , answer=0;
		while(a || b){
			answer += (a%10 + b%10 + carry) > 9;
			carry = (a%10 + b%10 + carry)/10;
			a /= 10;
			b /= 10;
		}
		cout << (answer == 0 ? "No" : to_string(answer)) << " carry operation" << (answer>1 ? "s" : "") << ".\n";
	}
}