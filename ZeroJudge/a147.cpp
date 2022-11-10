#include<bits/stdc++.h>
#define ED end()
#define BG begin()
#define PB push_back
#define MP make_pair
#define ll long long
#define pii pair<int,int>
#define Size(x) (int)x.size()
#define BtoE(X) (X).begin(),(X).end()
#define test_
using namespace std;
int main(){
	int a;
	while(cin >> a){
		for(int i=1 ; i<a ; i++){
			if(i%7) cout<<i<<' ';
		}
		cout<<'\n';
	}
}