#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define ll long long
#define pii pair<int,int>
#define Size(x) (int)x.size()
#define all(X) (X).begin(),(X).end()
#define F first
#define S second
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
int main(){
__IO
	int T ;cin >> T;
	while(T--){
		vector<int> v;
		bitset<100000> vis;
		int n , k ; cin >> n >> k;
		for(int i=0 ; i<n ; ++i){
			int x; cin >> x ;
			v.push_back(x);
		}
		sort(all(v));
		int l = 0  , r = (v[v.size()-1]-v[0])*2-1 , mid , chk , cnt;
		while(l!=r){
			vis.reset();
			mid = (l+r)/2;
			cnt = 0;
			for(int i=0 ; i<n ; ++i){
				if(!vis[i]){
					chk = v[i]+mid , ++cnt;
					bool ok = true;
					for(int j=i ; j<n ; j++){
						if(v[j] <= chk) vis[j] = 1 ;
						else if(ok) ok = false , chk = v[i]+mid*2 , --j;
						else break; 
					}
				}
			}
			//cout << l <<' '<<mid<<" "<<r<<' '<<cnt<<'\n';
			if(cnt <= k) r = mid;
			else l = mid+1;
		}
		cout << l <<'\n';
	}
}
//1 3 4 9 15