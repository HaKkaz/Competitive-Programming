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
void GCD(int a, int b){
	while(a && b){
		if(b>a) swap( a , b );
		a%=b;
	}
	cout << max( a, b) <<'\n';
}
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    
    int a,b; 
    while(cin >> a >> b){
        GCD( a , b );
    }
}