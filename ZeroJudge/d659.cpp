#include<bits/stdc++.h>
using namespace std;
int cnt = 1;
int main(){
int t;cin>>t;
while(t--){
int a , b , c;cin >> a >> b >> c;
int tot = a+b+c;
cout << "Case " << cnt++ << ": " << tot-min({a,b,c})-max({a,b,c}) << '\n';
}
}