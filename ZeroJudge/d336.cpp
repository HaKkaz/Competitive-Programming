#include<bits/stdc++.h>
#define test_
#define PB push_back
#define MP make_pair
#define Size size()
#define ED end()
#define BG begin()
#define St first
#define Nd second
#define ll long long
#define vi vector<int>
#define vs vector<string>
#define pii pair<int,int>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	while(n--){
		int now=0;
		string str; cin >> str;
		reverse(str.begin(),str.end());
		for(int i=0 ; i<(int)str.size() ; i++){
			if(str[i]-'0' == 1 ){
				if(!(i%2))	now--;
				else now++;
			}
		}
		if(!(now % 3)) cout<<"Yes"<<'\n';
		else cout<<"No"<<'\n';
	}
}