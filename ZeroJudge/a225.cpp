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
bool cmp(const pair<int,int> &a,const pair<int,int> &b){
	if(a.first != b.first) return a.first < b.first;
	else return a.second > b.second ;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    while(cin >> n){
    	vector<pair<int ,int > > num ;
    	for(int i=0 ; i<n ; i++){
    		int x; cin >> x; 
    		num.push_back({x%10,x});
    	}
    	sort( num.begin() , num.end() , cmp );
    	for(auto &l:num) cout << l.second <<' ';
    	cout<<'\n';
    }
}