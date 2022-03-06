#include"bits/stdc++.h"
#define pb push_back
#define mp make_pair
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
struct query
{
	int l , r , id , bk;
	query(int _l , int _r , int _id):l(_l) , r(_r) , id(_id) , bk(0){}
	query(){}
}Qs[maxn];

int a[maxn] , cnt[maxn] , num[maxn] , ans[maxn] , mx = 0;


void add(int x){
	cnt[x]++;
	num[cnt[x]-1]--;
	num[cnt[x]]++;
	mx = max(cnt[x] , mx);
}
void sub(int x){
	cnt[x]--;
	num[cnt[x]+1]--;
	num[cnt[x]]++;
	if(!num[cnt[x]+1] and cnt[x]+1 == mx) mx = cnt[x];
}

signed main(){
	int n , q;
	cin >> n >> q;
	const int sn=sqrt(n);

	for(int i=1 ; i<=n ; ++i) cin >> a[i];
	for(int i=0 ; i<q ; ++i){
		int l , r; cin >> l >> r;
		Qs[i] = query(l,r,i);
		Qs[i].bk = l / sn;
	}

	sort(Qs , Qs+q , [](const query &a , const query &b){
		if(a.bk != b.bk) return a.bk < b.bk;
		else return a.r < b.r;
	});

	int L=0 , R=-1;
	for(int i=0 ; i<q ; ++i){
		while(L>Qs[i].l) L--,add(a[L]);
		while(R<Qs[i].r) R++,add(a[R]);
		while(R>Qs[i].r) sub(a[R]),R--;
		while(L<Qs[i].l) sub(a[L]),L++;
		ans[Qs[i].id] = mx;
	}

	for(int i=0 ; i<q ; ++i){
		cout << ans[i] << '\n';
	}
}