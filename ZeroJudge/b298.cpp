#include<bits/stdc++.h>
#define ED end()
#define BG begin()
#define PB push_back
#define MP make_pair
#define ll long long
#define pii pair<int,int>
#define Size size()
#define test_
using namespace std;
const int MAXN=100010;
vector<int>  v[MAXN];
bool chk[MAXN];
bool find(int a){
	if(chk[a]) return true;
	for(int i=0;i<(int)v[a].Size;i++){
		if(find(v[a][i])) return true;
	}
	return false;
}
int main(){
 	int N,M,L,Q;
 	cin>>N>>M>>L>>Q;

 	for(int i=0;i<M;i++){	//表示x供應原料給y
 		int x,y;	cin>>x>>y;
 		v[y].PB(x);
 	}

 	for(int i=0;i<L;i++){	//表示此廠商是有問題的的
 		int x;	cin>>x;
 		chk[x]=true;
 	}
 	for(int i=0;i<Q;i++){	//詢問此廠商是否有問題
 		int x; cin>>x;
 		if(find(x)) cout<<"TUIHUOOOOOO"<<'\n';
 		else cout<<"YA~~"<<'\n';
 	}

 	//for(int i=1;i<=N;i++){ cout<<v[i]<<" "<<chk[i]<<'\n'; }

}