#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define int long long
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
signed main(){
	int value; cin >> value;
	int a = value - value/2000*200;
	int b = value - value/1000*100;
	if(a <= b){
		cout << a << ' ' << 0 << '\n';
	}
	else{
		cout << b << ' ' << 1 << '\n';
	}
}