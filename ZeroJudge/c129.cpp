#include<iostream>
#include<queue>
#include<utility>//pair
#include<algorithm>
using namespace std;
int n , m; 
int dx[]={0,1,1,1,0,-1,-1,-1} , dy[]={1,1,0,-1,-1,-1,0,1};
bool v[101][101];
char c;
int ans = 0 ;
void DFS(int i , int j){
	v[i][j] = 1 ;//造訪過改0
	for(int a=0 ; a<8 ; ++a){
		if(!v[i+dy[a]][j+dx[a]] && i+dy[a]>=0 && i+dy[a]<n && j+dx[a]>=0 && j+dx[a]<m) DFS(i+dy[a] , j+dx[a]);
	}
}
inline void init(){
	for(int i=0 ; i<101 ; ++i)
		for(int j=0 ; j<101 ; ++j) 
			v[i][j] = 0;
	ans = 0;
}
int main(){ios::sync_with_stdio(false),cin.tie(0);
	while(cin >> n >> m&&n+m){
		init();//初始化陣列
		for(int i=0 ; i<n ; ++i){
			for(int j=0 ; j<m ; ++j){
				cin >> c;
				if(c == '*') v[i][j] = 1;//把*當作造訪過
			}
		}
		for(int i=0 ; i<n ; ++i)
			for(int j=0 ; j<m ; ++j)
				if(!v[i][j]) ++ans , DFS(i,j);
			
		cout << ans <<'\n';
	}
}