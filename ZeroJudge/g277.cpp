#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+600;
long long p[maxn];
pair<int,int> a[maxn];
int main(){
    int n; cin >> n;
    for(int i=1 ; i<=n ; ++i) 
        cin >> a[i-1].first , p[i] = p[i-1] + a[i-1].first , a[i-1].second = i;
    sort(a , a+n);
    int l = 1 , r = n ;
    for(int i=0 ; i<n ; ++i){
        if(r == l) break;
        if(a[i].second >= l && a[i].second <= r){
            int pos = a[i].second;
            int A = p[pos-1] , B = p[n]-p[pos];
            if( A > B ){
                r = pos-1;
            }
            else{
                l = pos+1;
            }
        }
    }
    cout << p[l]-p[l-1] << '\n';
}
