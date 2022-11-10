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
#define matrix vector<vector<int>>
const int mod = 10000;
matrix operator*(const matrix &a , const matrix &b){
	matrix c = matrix(a.size(),vector<int>(b[0].size(),0));
	for(int i=0 ; i<c.size() ; ++i)for(int j=0 ; j<c.size() ; ++j)c[i][j]=0;
	for(int i=0 ; i<a.size() ; ++i){
		for(int j=0 ; j<b[0].size() ; ++j){
			for(int k=0 ; k<a[0].size() ; ++k)
				c[i][j] += (a[i][k]*b[k][j])%mod , c[i][j] %= mod;
		}
	}
	return c;
}
matrix trans , A;
matrix fpow(matrix a , int p){
	matrix c = a;
	for(int i=0 ; i<c.size() ; ++i)
		for(int j=0 ; j<c[0].size() ; ++j)
			c[i][j] = i==j;
	for( ; p ; p>>=1 , a = a*a)
		if(p&1) c = c*a;
	return c;
}
signed main(){
	// IOS;
	int P , Q , R , A0 , A1 , N;
	cin >> P >> Q >> R >> A0 >> A1 >> N;
	A = {{A1} , {A0} , {R}};
	trans = 
	{
		{P , Q , 1},
		{1 , 0 , 0},
		{0 , 0 , 1}
	};
	trans = fpow(trans , N-1);
	matrix ans = trans * A;
	int k = to_string(ans[0][0]).size();
	while(k<4){
		cout << 0 , ++k;
	}
	cout << ans[0][0] << '\n';
}