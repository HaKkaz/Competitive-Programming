#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);int T;cin >>T;while(T--){int a,b;cin>>a>>b;int c=(a+b)/2 , d=(a-b)/2;(a+b)%2||(a-b)%2||(b>a)?cout<<"impossible\n":(c>d?cout<<c<<' '<<d<<'\n':cout<<d<<' '<<c<<'\n');}
}