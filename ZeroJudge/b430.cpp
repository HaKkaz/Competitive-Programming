#include<iostream>
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
int main(){
__IO
	unsigned long long a , b , mod;
	while(cin >> a >> b >> mod){
		unsigned long long ret = 0;
		for(a%=mod , b%=mod ; b ; b>>=1 , a<<=1 , a = (a>=mod)?(a-mod):(a)){
			if(b&1) ret = (ret+a>=mod) ? (ret+a-mod) : (ret+a);
		}
		cout <<ret<<'\n';
	}
}