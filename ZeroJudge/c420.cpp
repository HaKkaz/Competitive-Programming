#include<bits/stdc++.h>
#define test_
#define pb push_back
#define S second
#define F first
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define pii pair<int,int>
#define et cout<<'\n';
#define rep(i , n) for(int mm=i ; mm<n ; ++mm)
using namespace std;
int main(){
__IO
	int n;
	cin >> n;
	for(int i=n-1 , j=1 ; i>=0 ; --i , j+=2){
		for(int a = 0 ; a < i ; ++a) cout << '_';
		for(int a = 0 ; a < j ; ++a) cout << '*';
		for(int a = 0 ; a < i ; ++a) cout << '_';
		et;
	}
}