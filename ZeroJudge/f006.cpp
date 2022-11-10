#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
int n; 
while(cin >> n){
for(int i=1 ; i<=n ; ++i) cin >> a[i];
sort(a+1,a+1+n);
cout << a[n] << ' ' << a[1] << '\n';
}
}