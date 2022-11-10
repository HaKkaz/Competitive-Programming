#include<bits/stdc++.h>
//#include<cstdio>
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
/*
inline int read(){
    int res=0; char ch=getchar_unlocked();
    while(ch<'0'||ch>'9') ch=getchar_unlocked();
    while(ch>='0'&&ch<='9') res=(res<<3)+(res<<1)+(ch^48),ch=getchar_unlocked();
    return res;
}
*/
#define int long long
#define mp make_pair
#define pb push_back
#define S second
#define F first
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define IOS ios::sync_with_stdio(false),cin.tie(0);
#define pii pair<int,int>
#define endl cout<<'\n';
#define LINE cout << "-----------------------\n";
#define lb(x) (x&(-(x)))
using namespace std;
const int maxn = 1e5+5;
struct T
{
    int x , y , z , id;
    bool operator<(const T &a)const{
        if(x != a.x) return x > a.x;
        if(y != a.y) return y < a.y;
        return z < a.z;
    }
}element[maxn];
int bit[maxn] , sum_of_bit , ans[maxn];
void bit_update(int i,int k){
    for(sum_of_bit+=k ; i<maxn ; i+=lb(i)) bit[i]+=k;
}
int bit_query(int i){
    int res=0;
    for(;i;i-=lb(i))res+=bit[i];
    return res;
}
void CDQ(int l , int r){
    if(l==r)return;
    int mid = (l+r)>>1;
    CDQ(l , mid);
    CDQ(mid+1 , r);
    int a=l , b=mid+1;
    stack<pii,vector<pii>> stk;
    queue<T> q;
    while(a<=mid || b<=r){
        if(a<=mid && (b>r || element[a].y > element[b].y)){
            bit_update(element[a].z , 1);
            stk.push({element[a].z , -1});
            q.push(element[a++]);
        }
        else{
            ans[element[b].id] += sum_of_bit - bit_query(element[b].z);
            q.push(element[b++]);
        }
    }
    while(stk.size()) bit_update(stk.top().F , stk.top().S) , stk.pop();
    for(int x=l ; x<=r ; ++x) element[x]=q.front(),q.pop();

}
signed main(){
    IOS;
    int n;
    cin >> n ;
    for(int i=0 ; i<n ; ++i) cin >> element[i].x >> element[i].y >> element[i].z , element[i].id = i;
    sort(element,element+n);
    CDQ(0 , n-1);
    for(int i=0 ; i<n ; ++i) cout << ans[i] << '\n';
}