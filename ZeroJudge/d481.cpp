#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define pb push_back
#define mp make_pair
#define Sz(x) (int)(x).size()
#define pii pair<int,int>
#define all(X) (X).begin(),(X).end()
#define F first
#define S second
#define endl cout<<'\n';
#define __IO ios::sync_with_stdio(false),cin.tie(0);
#define int long long 
using namespace std;
struct matrix{
	int m[101][101]={{0}} , nn , mm;
	matrix(int _nn , int _mm){
		nn = _nn , mm = _mm;
	}
	//nn = a.mm
	matrix operator*(const matrix &a)const{
		matrix c(nn , a.mm);
		for(int i=0 ; i<c.nn ; ++i){
			for(int j=0 ; j<c.mm ; ++j){
				for(int k=0 ; k<mm ; ++k){
					c.m[i][j] += m[i][k] * a.m[k][j];
				}
			}
		}
		return c;
	}
};
signed main(){
__IO
	int a , b , c , d;
	while(cin >> a >> b >> c >> d){
		if(b != c){
			cout << "Error\n";
			continue;
		}
		matrix A(a , b) , B(c , d) , C(a , d);
		for(int i=0 ; i<a ; ++i)
			for(int j=0 ; j<b ; ++j)
				cin >> A.m[i][j];
		for(int i=0 ; i<c ; ++i)
			for(int j=0 ; j<d ; ++j)
				cin >> B.m[i][j];
		C = A * B;

		for(int i=0 ; i<a ; ++i){
			for(int j=0 ; j<d ; ++j){
				cout << C.m[i][j] << ' ';
			}
			cout << '\n';
		}
	}
}