#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
signed main(){
	IOS;
	int n,A,B,C,D,E,F; 
	char who[100];
	A = (1<<2)|(1<<0);
	B = (1<<2)|(1<<1)|(1<<0);
	C = (1<<1);
	D = (1<<3)|(1<<2)|(1<<0);
	E = (1<<3);
	F = (1<<3)|(1<<2);
	who[A]='A';
	who[B]='B';
	who[C]='C';
	who[D]='D';
	who[E]='E';
	who[F]='F';
	while(cin >> n){
		for(int i=0 ; i<n ; ++i){
			int w,x=0;
			for(int j=3 ; j>=0 ; j--) cin >> w , x |= (w<<j);
			cout << who[x];		
		}
		cout << '\n';
	}
}