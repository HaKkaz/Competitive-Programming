#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define ll long long
#define pii pair<int,int>
#define Size(x) (int)x.size()
#define all(X) (X).begin(),(X).end()
#define F first
#define S second
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
const long long MOD = 1000000007;
struct matrix
{
	long long mat[100][100]={{0}} , n=0 , m=0;
	matrix operator* (const matrix &x){
		matrix c;
		c.m = m , c.n=x.n;
		for(int i=0 ; i<c.m ; ++i)
			for(int j=0 ; j<c.n ; ++j)
				for(int k=0 ; k<n ; ++k){
					c.mat[i][j] += (( (mat[i][k]%MOD)*(x.mat[k][j]%MOD) )%MOD);
					c.mat[i][j]%=MOD;
				}
		return c;
	}
	void chk(){
		for(int i=0 ; i<m ; ++i){
			for(int j=0 ; j<n ; ++j){
				cout << mat[i][j] <<' ';	
			}
			cout<<'\n';
		}
	}
};
matrix fpow(matrix c,long long p){
	if(p==1) return c;
	if(p%2) return c*fpow(c*c,p/2);
	return fpow(c*c,p/2);
}
int main(){
//__IO
	int Q , n;
	cin >> Q;
	while(Q--){
		cin >> n;
		if(n==1){
			cout<<5<<'\n'; continue;
		}
		if(n==2){
			cout<<24<<'\n'; continue;
		}
		matrix m1 , m2 ,c;
		m1.mat[0][0]=4,m1.mat[0][1]=4,m1.mat[1][0]=1,m1.n=2,m1.m=2;
		m2.mat[0][0]=24,m2.mat[1][0]=5,m2.n=1,m2.m=2;
		c=fpow(m1,n-2);
		c = c*m2;
		cout << c.mat[0][0] <<'\n';
	}
}