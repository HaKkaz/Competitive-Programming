#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define cerr if(0);else cerr
#define _ << ' ' << 
#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second
using ll = long long ;
using ld = long double ;
using pii = pair<int,int> ;

int boss[36];

int Find(int x){
    return x == boss[x] ? x : boss[x] = Find(boss[x]);       
}

void Merge(int a , int b){
    a = Find(a) , b = Find(b);
    if(a!=b) boss[b] = a;
}

const int dx[]={1,0};
const int dy[]={0,1};
signed main(){
	fast;
    int need=0;
    for(int i=0 ; i<4 ; ++i){
        for(int j=0 ; j<4 ; ++j){
            int x; cin >> x;
            if(x & 1){
                need |= (1 << (i * 4 + j));
            }
        }
    }
    
    int ans = 0 ;

    for(int i=0 ; i<(1<<16) ; ++i){
        if( (i & need) == need ){
            array< array<bool,6>,6 > A;
            for(int j=0;j<6;++j) A[j].fill(false);
            iota(boss , boss+36 , 0);

            for(int j=0 ; j<16 ; ++j){
                if( i>>j & 1 ){
                    int x = j/4+1 , y = j%4+1;
                    A[x][y] = 1;
                }
            }

            

            for(int x=0 ; x<6 ; ++x){
                for(int y=0 ; y<6 ; ++y){
                    for(int d=0 ; d<2 ; ++d){
                        int xx = x + dx[d];
                        int yy = y + dy[d];
                        if(xx < 0 || xx >= 6 || yy < 0 || yy >= 6) continue;
                        if(A[x][y] == A[xx][yy]) 
                            Merge(x*6+y , xx*6+yy);
                    }
                }
            }     
            
            set<int> s;
            for(int j=0 ; j<36 ; ++j) s.insert(Find(j));
            if(s.size() == 2) ++ans;
        }
    }
    
    cout << ans << '\n';
    ;
}

