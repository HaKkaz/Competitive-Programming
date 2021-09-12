#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define _ <<' '<<
#ifdef DEBUG
#define fast
#else
#define fast ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define cerr if(0);else cerr
#endif

constexpr int size = 20;
string ans , s;
void solve(int a,int b,int c,int d){
    vector<int> cnt(size,0);
    int hav = 0;
    for(int i=0 ; i<7 ; ++i){
        if(i != a && i != b && i != c && i != d)
          hav += (++cnt[s[i]-'A'+1] == 1);
    }
    int A = s[a]-'A'+1 + s[b]-'A'+1;
    int B = s[c]-'A'+1 + s[d]-'A'+1;

    hav += (++cnt[A] == 1 and A <= 5);
    hav += (++cnt[B] == 1 and B <= 5);
    if(hav == 5) ans = "YES"; 
}

void solve2(int a , int b){
    vector<int> cnt(size,0);
    int hav = 0;
    for(int i=0 ; i<7 ; ++i){
        if(i != a && i != b)
          hav += (++cnt[s[i]-'A'+1] == 1);
    }
    int A = s[a]-'A'+1 + s[b]-'A'+1; 
    hav += (++cnt[A] == 1 and A <= 5);
    if(hav == 5) ans = "YES"; 

}
void solve3(){
    vector<int> cnt(size,0);
    int hav = 0;
    for(int i=0 ; i<7 ; ++i){
          hav += (++cnt[s[i]-'A'+1] == 1);
    }
    if(hav == 5) ans = "YES"; 
}
signed main(){
    fast;
    int t; cin >> t;
    while(t--){
        ans = "NO";
        cin >> s;

        for(int i=0 ; i<7 ; ++i)
            for(int j=0 ; j<7 ; ++j)
                for(int x=0 ; x<7 ; ++x)
                    for(int y=0 ; y<7 ; ++y)
                        if(i != j && i != x && i != y && j != x && j != y && x != y)
                            solve(i , j , x , y);

        for(int i=0 ; i<7 ; ++i)
            for(int j=i+1 ; j<7 ; ++j)
                solve2(i,j);
        
        solve3();

        cout << ans << '\n';
    }
	;

}
