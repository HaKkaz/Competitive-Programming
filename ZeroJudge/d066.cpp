#include<iostream>
using namespace std;
int main(){
	int n,m;
	while(cin >> n >> m){
		if(n==7&&m<30) cout << "Off School"<<'\n';
		else if(n<7) cout << "Off School"<<'\n';
		else if(n>=17) cout << "Off School"<<'\n';
		else cout << "At School"<<'\n';
	}
}