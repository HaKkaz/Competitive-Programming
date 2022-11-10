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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n , m;
    while(cin >> n >> m){
    	string str="";
    	for(int i=0 ; i<n ; i++){
    		string s;
    		cin >> s;
    		str += s;
    	}
    	string ans="";
    	for(int i=0 ; i<m ; i++){
    		int x; cin >> x;
    		ans += str[x-1];
    	}
    	cout << ans <<'\n';
    }
}