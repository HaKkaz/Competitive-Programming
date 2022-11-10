#include"bits/stdc++.h"
#define pb push_back
#define mp make_pair
#define int long long
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define rz(x) resize(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define endl cout<<'\n';
#define LINE cout<<"--------------------------\n";
#define loli ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
const int maxn = 500001;
vector<int> aa , bb;
int x;
inline void latina(){
	//loli;
	for(int i=0 ; i<10 ; ++i) cin >> x , aa.pb(x);
	sort(all(aa));
	for(int a=0 ; a<=50 ; ++a){
		for(int b=a ; b<=50 ; ++b){
			for(int c=b ; c<=50 ; ++c){
				for(int d=c ; d<=50 ; ++d){
					for(int e=d ; e<=50 ; ++e){
						bb.clear();
						bb.pb(a+b) ,bb.pb(a+c) ,bb.pb(a+d) ,bb.pb(a+e);
						bb.pb(b+c) ,bb.pb(b+d) ,bb.pb(b+e) ;
						bb.pb(c+d) ,bb.pb(c+e);
						bb.pb(d+e) ;
						sort(all(bb));
						if(aa == bb){
							cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';
							break;
						}
					}
				}
			}
		}
	}
}
signed main(){latina();}
//32 38 35 37 31 33 36 34 33 35