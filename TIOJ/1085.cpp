#include"bits/stdc++.h"
#define loli ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
int X , Y , Z , dx[]={1,-1,0,0,0,0} , dy[]={0,0,1,-1,0,0} , dz[]={0,0,0,0,1,-1};
struct T{int x , y , z;};
T ans[55][55][55];
bool ok[55][55][55];
void dfs(int x, int y ,int z){
	if(x==1 and y==1 and z==1){
		cout << '('<< x << ',' << y << ',' << z << ')';
		return;
	}
	int a=ans[x][y][z].x , b=ans[x][y][z].y , c=ans[x][y][z].z;
	dfs(a,b,c);
	cout << "->(" << x << ',' << y << ',' << z << ')'; 
}
inline bool check(int x , int y ,int z){return(x>0 and x<=X and y>0 and y<=Y and z>0 and z<=Z and !ok[x][y][z]);}
inline void latina(){
	loli;
	cin >> X >> Y >> Z ;
	for(int i=1 ; i<=Z ; ++i)
			for(int k=1 ; k<=Y ; ++k)
				for(int j=1 ; j<=X ; ++j)
				cin >> ok[j][k][i];
	queue<T> q;
	if(ok[1][1][1] || ok[X][Y][Z]) cout <<"no route\n",exit(0);
	if(check(1,1,1)) q.push({1,1,1}),ok[1][1][1]=1;
	bool tag = 0;
	while(q.size()){
		int x=q.front().x , y=q.front().y , z=q.front().z;
		q.pop();
		if(x==X and y==Y and z==Z){
			tag=1;break;
		}
		for(int i=0 ; i<6 ; ++i){
			if(check(x+dx[i] , y+dy[i] , z+dz[i])){
				q.push({x+dx[i] , y+dy[i] , z+dz[i]});
				ok[x+dx[i]][y+dy[i]][z+dz[i]]=1;
				ans[x+dx[i]][y+dy[i]][z+dz[i]]={x,y,z};
			}
		}
	}
	if(tag) dfs(X,Y,Z);
	else cout <<"no route\n";
}
signed main(){latina();}