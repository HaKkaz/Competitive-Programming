#include<bits/stdc++.h>
#define int long long
//#define test_
#define MP make_pair
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
signed main(){
//__IO
	int n;
	while(cin >> n){
		long long tot = 1;
		for(int i=1 , j=1 , k = 0 ; k<49 ; i+=j , j+=n, ++k){
			tot += (i+j);
		}
		cout << tot << '\n';
	}
}