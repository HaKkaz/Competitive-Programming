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
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int n ;
    while(cin >> n){
        long long  f[30005],g[30005];
        f[1]=g[1]=1;
        for(int i=2 ; i<=n ; i++){
            f[i]=i+f[i-1];
            g[i]=f[i]+g[i-1];
        }
        cout << f[n] << ' ' << g[n] << '\n';
    }
}