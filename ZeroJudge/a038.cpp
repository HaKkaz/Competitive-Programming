#include<bits/stdc++.h>

#define Vi vector<int>
#define Vs vector<string>
#define Mii map<int,int>
#define Msi map<string,int>
#define Mis map<int,string>
#define Mss map<string,string>
#define Si set<int>
#define PB push_back
#define PF push_front


typedef long long ll;
using namespace std;
int main(){
	int first=1;
	string a;
	cin>>a;
	reverse(a.begin(),a.end());
	for(int i=0;i<=a.size()-1;i++) {
		if(a[i]=='0'&&first){
			continue;
		}
		else{
			first=0;
			cout<<a[i];
		}
	}
	if(first==1) cout<<0<<endl;
	
}