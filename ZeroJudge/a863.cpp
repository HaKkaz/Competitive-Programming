#include<bits/stdc++.h>
#define test_
#define pb push_back
#define S second
#define F first
#define Sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define pii pair<int,int>
#define endl cout<<'\n';
#define rep(i , n) for(int mm=i ; mm<n ; ++mm)
using namespace std;
int main(){
//__IO
	long long n;
	while(cin >> n){
		long long st , cnt = 0;
		st = n;
		while(n != 1 && cnt < 101){
			int tot = 0 , a;
			while(n){
				a = n % 10;
				tot += a*a;
				n /= 10;
			}
			n = tot , ++cnt;
		}
		if(n == 1) cout << st << " is a happy number\n";
		else cout << st << " is an unhappy number\n";
	}
}