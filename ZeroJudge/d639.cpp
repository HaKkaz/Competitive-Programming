#include<iostream>
#pragma GCC optimize ("Ofast")
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
const long long mod = 10007 ;
struct matrix
{
	long long m[3][3];
	void init(){
		for(int i=0 ; i<3; ++i)
			for(int j=0 ; j<3 ; ++j)
				m[i][j] = 0;
	}
	matrix operator*(const matrix &a)const{
		matrix c = {0};
		for(int i=0 ; i<3 ; ++i)
			for(int j=0 ; j<3 ; ++j)
				for(int k=0 ; k<3 ; ++k)
					c.m[i][j] = (c.m[i][j]%mod + ((m[i][k]%mod) * (a.m[k][j]%mod))%mod)%mod;
		return c;
	}
	void check(){
		for(int i=0 ; i<3 ; ++i)
		{
			for(int j=0 ; j<3 ; ++j){
				cout << m[i][j] << ' ';
			}
			cout << '\n';
		}
	}
};
matrix fpow(matrix n,long long p){
	matrix ans;
	ans.init();
	for(int i=0 ; i<3 ; ++i)
		ans.m[i][i] = 1;
	for( ; p ; p>>=1 , n = n*n)
		if(p&1)
			ans = ans * n;
	return ans;
}
int main(){__IO
	int n; cin >> n;
	matrix c  , base; c.init() , base.init();
	base.m[0][0] = base.m[1][0] = base.m[2][0] = 1;
	c.m[0][0] = c.m[0][1] = c.m[0][2] = c.m[1][0] = c.m[2][1] = 1;
	c = fpow(c,n-3);
	matrix ans = c * base;
	cout << ans.m[0][0] << '\n';
}