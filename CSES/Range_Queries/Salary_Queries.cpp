#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#define pb push_back
#define MP make_pair
#define pii pair<int,int>
#define F first
#define S second
#define SZ(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define debug(x) cerr << #x << " = "  << x << '\n';
using namespace std;

const int maxn = 800050;
int a[200050] , bit[maxn];

void upd(int i , int k){
	for( ; i<maxn ; i+=(i&-i)){
		bit[i] += k;
	}
}

int qry(int i){
	int ret = 0 ;
	for( ; i ; i-=(i&-i))
		ret += bit[i];
	return ret;
}

vector< tuple<char,int,int> > Q;

signed main(){
	IOS;
	int n , q; cin >> n >> q;
	vector<int> dec;
	for(int i=0 ; i<n ; ++i) {
		cin >> a[i];
		dec.emplace_back(a[i]);
	}
	for(int i=0 ; i<q ; ++i){
		char opt;
		int a,b; 
		cin >> opt >> a >> b;
		if(opt == '!'){
			--a;
			dec.emplace_back(b);
		}
		if(opt == '?'){
			dec.emplace_back(a);
			dec.emplace_back(b);
		}
		Q.emplace_back(opt , a , b);
	}
	sort(all(dec)) , dec.resize(unique(all(dec)) - dec.begin());
	for(int i=0 ; i<n ; ++i){
		a[i] = upper_bound(all(dec) , a[i]) - dec.begin();
		upd(a[i] , 1);
 	}

 	for(auto [opt , x , y] : Q){
 		if(opt == '!'){
	 		y = upper_bound(all(dec) , y) - dec.begin();
	 		upd(a[x] , -1);
	 		a[x] = y;
	 		upd(a[x] , 1);
 		}
 		else{
 			x = upper_bound(all(dec) , x) - dec.begin();
 			y = upper_bound(all(dec) , y) - dec.begin();
 			int L = qry(x-1);
 			int R = qry(y);
 			// cout << "L = " << L << " R = " << R << endl;
 			cout << R - L << '\n';
 		}
 	}

}