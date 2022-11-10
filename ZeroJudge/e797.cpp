#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
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
vector<bool> ans[3];
int a[500][500];
signed main(){
	// IOS;
	int n , t;
	cin >> n >> t;
	int And,Or,Xor;
	for(int i=0 ; i<n ; ++i)for(int j=0 ; j<t ; ++j)cin>>a[i][j];
	for(int i=0 ; i<t ; ++i){
		int x = a[0][i];
		And=x , Or=x , Xor=x;
		for(int j=1 ; j<n ; ++j){
			x = a[j][i];
			And &= x , Or |= x , Xor ^= x;
		}
		ans[0].push_back(And);
		ans[1].push_back(Or);
		ans[2].push_back(Xor);
	}
	for(int i=0 ; i<3 ; ++i){
		if(i == 0) cout << "AND: ";
		if(i == 1) cout << " OR: ";
		if(i == 2) cout << "XOR: ";
		for(auto j : ans[i]){
			cout << j << ' ';
		}
		cout << '\n';
	}
}