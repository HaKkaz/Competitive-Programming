#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define ft first
#define sd second
#define ALL(v) v.begin(),v.end()
#define fast ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define cerr if(0);else cerr
#define _ << ' ' << 

int main(){
	fast;
    int k; cin >> k ;
    string a,b;
    cin >> a >> b;
    ll A=0,B=0;
    reverse(ALL(a));
    reverse(ALL(b));
    for(ll i=0,val=1 ; i<(int)a.size() ; val*=k,++i) A += (a[i]-'0') * (val);
    for(ll i=0,val=1 ; i<(int)b.size() ; val*=k,++i) B += (b[i]-'0') * (val);
    cout << A*B << '\n';
}

