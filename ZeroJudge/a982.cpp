#include<iostream>
#include<math.h>
#include<queue>
using namespace std;
struct T
{
	int x , y , dis;
};
int dx[]={1,-1,0,0} , dy[]={0,0,1,-1};
int main(){
	int n ;
	while(cin >> n){
		char G[102][102];
		for(int i=0 ; i<n ; ++i){
			for(int j=0 ; j<n ; ++j){
				cin >> G[i][j];
			}
		}
		queue<T> q;
		q.push({1,1,1});
		G[1][1] = '#';
		while(q.size()){
			int x = q.front().x , y = q.front().y , d = q.front().dis;
			q.pop();
			if(x == n-2 && y == n-2) return cout<<d<<'\n' , 0;
			for(int i=0 ; i<4 ; ++i){
				if(G[x+dx[i]][y+dy[i]]=='.') q.push({x+dx[i] , y+dy[i] , d+1}) , G[x+dx[i]][y+dy[i]] = '#';
			}
		}
		cout<<"No solution!\n";
	}
}