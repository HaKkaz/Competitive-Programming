#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair<int,int>
#define all(X) (X).begin(),(X).end()
#define F first
#define S second
#define endl cout<<'\n';
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
char mat[100][100][100];
int l , r , c;
struct id
{
	int n , m , x , dis;
};
queue<id> q;
bool ok;
id ed;
inline void init(){
	while(q.size()) q.pop();
	ok = true;
}
inline void bfs(){
	while(q.size()){
		id tmp = q.front() ;q.pop();
		if(tmp.n==ed.n && tmp.m==ed.m && tmp.x==ed.x){
			cout<<"Escaped in "<<tmp.dis<<" minute(s).\n";
			ok = false;
			return;
		}
		if(tmp.n+1<l && mat[tmp.n+1][tmp.m][tmp.x]!='#') mat[tmp.n+1][tmp.m][tmp.x]='#' , q.push(id{tmp.n+1,tmp.m,tmp.x,tmp.dis+1});
		if(tmp.n-1>=0 && mat[tmp.n-1][tmp.m][tmp.x]!='#') mat[tmp.n-1][tmp.m][tmp.x]='#' , q.push(id{tmp.n-1,tmp.m,tmp.x,tmp.dis+1});
		if(tmp.m+1<r && mat[tmp.n][tmp.m+1][tmp.x]!='#') mat[tmp.n][tmp.m+1][tmp.x]='#' , q.push(id{tmp.n,tmp.m+1,tmp.x,tmp.dis+1});
		if(tmp.m-1>=0 && mat[tmp.n][tmp.m-1][tmp.x]!='#') mat[tmp.n][tmp.m-1][tmp.x]='#' , q.push(id{tmp.n,tmp.m-1,tmp.x,tmp.dis+1});
		if(tmp.x+1<c && mat[tmp.n][tmp.m][tmp.x+1]!='#') mat[tmp.n][tmp.m][tmp.x+1]='#' , q.push(id{tmp.n,tmp.m,tmp.x+1,tmp.dis+1});
		if(tmp.x-1>=0 && mat[tmp.n][tmp.m][tmp.x-1]!='#') mat[tmp.n][tmp.m][tmp.x-1]='#' , q.push(id{tmp.n,tmp.m,tmp.x-1,tmp.dis+1});
	}

}
int main(){
//__IO
	while(cin >> l >> r >> c&&(l+r+c)){
		init();
		for(int i=0 ; i<l ; ++i)
			for(int j=0 ; j<r ; ++j)
				for(int k=0 ; k<c ; ++k){
					cin >> mat[i][j][k];
					if(mat[i][j][k]=='S') q.push(id{i,j,k,0}) , mat[i][j][k]='#';
					if(mat[i][j][k]=='E') ed = id{i,j,k,0};
				}
		bfs();
		if(ok) cout<<"Trapped!\n";
	}
}