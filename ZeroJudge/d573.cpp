#include<bits/stdc++.h>
#define test_
#define PB push_back
#define S second
#define F first
#define all(x) (x).begin(),(x).end()
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define pii pair<int,int>
#define endl cout<<'\n';
const long long llMAX=2e18+20020522;
const unsigned long long ullMAX=1e19+20020522;
const int imax = 2e9+20020522;
using namespace std;
int p[100005];
int main(){
//__IO
	int n;
	while(cin >> n){
		for(int i=1 ; i<=n ; ++i){
			int x , y; cin >> x >> y;
			for(int j=1 ; j<=y ; ++j){
				int a ; cin >>a ;
				p[a]=i;
			}
		}
		
		int q;
		cin >> q;
		cout<<p[q]<<'\n';
	}
}