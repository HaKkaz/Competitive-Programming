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
vector<vector<int>> v;
int n , k, x; 
bool cmp(vector<int> &a , vector<int> &b){
	for(int i=0 ; i<k ; ++i){
		if(a[i] != b[i]) return a[i] < b[i];
	}
}
int main(){
__IO
	cin >> n >> k;
	for(int i=0 ; i<n ; ++i){
		vector<int> tmp;
		for(int j=0 ; j<k ; ++j){

			cin >> x , tmp.pb(x);
		}
		v.pb(tmp);
	}
	sort(v.begin() , v.end() , cmp);
	for(int i=0 ; i<n ; ++i){
		for(auto &c : v[i]){
			cout << c << ' ';
		}
		et
	}
}