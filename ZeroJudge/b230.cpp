#include<bits/stdc++.h>
#define test_
#define pb push_back
#define S second
#define F first
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define pii pair<int,int>
#define et cout<<'\n';
#define rep(i , n) for(int mm=i ; mm<n ; ++mm)
using namespace std;
bool num[1000000];
vector<int> v;
int main(){
//__IO
	for(int i=1 ; i<65; ++i)
		for(int j=1 ; j<65 ; ++j)
			for(int k=1 ; k<65 ; ++k)
				if(i!=j && j!=k && i!=k)
					num[i*j+i*k+j*k] = true;
	for(int i=1 ; i<=2000 ; ++i)
		if(v.size() > 65) break;
		else if(!num[i])
			v.pb(i);
	int n; cin >> n;
	cout << v[n-1] << '\n';
}