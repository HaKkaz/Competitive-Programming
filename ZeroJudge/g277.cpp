#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define _ <<' '<<
#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second
#define tiii tuple<int,int,int>
using ll = long long;
using ld = long double;
using pii = pair<int,int>;

using namespace std;
const int maxn = 3e5+50;
int arr[maxn] , psum[maxn];
vector<int> MN;
int pos = -1;

void solve(int l , int r){
    if(l == r){
        pos = l;
        return ;
    }

    while(MN.size() && (MN.back() < l || MN.back() > r)) MN.pop_back();
    int m = MN.back();
    MN.pop_back();

    int Rsum = (r >= m ? psum[r] - psum[m] : 0);
    int Lsum = (m-1 >= l-1 ? psum[m-1] - psum[l-1] : 0);

    if(Lsum > Rsum) solve(l , m-1);
    else solve(m+1 , r);
}

signed main(){
    fast;
    int n; cin >> n;
    for(int i=1 ; i<=n ; ++i){
        cin >> arr[i];
        psum[i] = psum[i-1] + arr[i];
        MN.push_back(i);
    }
    
    sort(ALL(MN) , [&](const int &a , const int &b){
        return arr[a] > arr[b];
    });

    solve(1,n);

    cout << arr[pos] << '\n';
}