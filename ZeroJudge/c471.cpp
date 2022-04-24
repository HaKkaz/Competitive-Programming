#include<bits/stdc++.h>
#define test_
#define PB push_back
#define S second
#define F first
#define all(x) (x).begin(),(x).end()
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define pii pair<int,int>
using namespace std;

struct item{
	long long w , f;
	bool operator<(const item &a)const{
		return w*a.f < a.w*f;
	}
};
int main(){
__IO
	int n; cin >> n;
	int ww[100005] , ff[100005];
	vector<item> thing;
	for(int i=0 ; i<n ; ++i) cin >>ww[i];
	for(int i=0 ; i<n ; ++i) cin >>ff[i];
	for(int i=0 ; i<n ; ++i){
		item data;
		data.w=ww[i] , data.f=ff[i] , thing.PB(data);
	}
	sort(all(thing));
	long long tot=thing[0].w  , ans = 0;
	for(int i=1 ; i<n ; ++i) ans += tot*thing[i].f , tot += thing[i].w;
	cout << ans <<'\n';
}