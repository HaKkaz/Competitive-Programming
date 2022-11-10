#include"bits/stdc++.h"
#define pb push_back
#define int long long
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define LINE cout<<"--------------------------\n";
#define IOS ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
const int maxn = 1e6+50;
signed main(){
    IOS;
   string str; getline(cin,str);
int n=str.size();
for(int i=0  ;i<str.size() ; ++i){
cout << (int)str[i] ;if(i != n-1) cout << '_';
}
}