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
int main(){
	vector< pair<char,int> > mp;
	mp.PB(MP('A',10));
	mp.PB(MP('B',11));
	mp.PB(MP('C',12));
	mp.PB(MP('D',13));
	mp.PB(MP('E',14));
	mp.PB(MP('F',15));
	mp.PB(MP('G',16));
	mp.PB(MP('H',17));
	mp.PB(MP('I',34));
	mp.PB(MP('J',18));
	mp.PB(MP('K',19));
	mp.PB(MP('L',20));
	mp.PB(MP('M',21));
	mp.PB(MP('N',22));
	mp.PB(MP('O',35));
	mp.PB(MP('P',23));
	mp.PB(MP('Q',24));
	mp.PB(MP('R',25));
	mp.PB(MP('S',26));
	mp.PB(MP('T',27));
	mp.PB(MP('U',28));
	mp.PB(MP('V',29));
	mp.PB(MP('W',32));
	mp.PB(MP('X',30));
	mp.PB(MP('Y',31));
	mp.PB(MP('Z',33));
	string str;
	while(cin>>str){
			for(int i=0;i<26;i++){
				if(str[0]-'A'==mp[i].first-'A'){
					if(((mp[i].second/10)+((mp[i].second%10)*9)+(str[1]-'0')*8+(str[2]-'0')*7+(str[3]-'0')*6+(str[4]-'0')*5+(str[5]-'0')*4+(str[6]-'0')*3+(str[7]-'0')*2+(str[8]-'0')+(str[9]-'0'))%10==0){
						cout<<"real"<<'\n';
						break;
					}
					else{
						cout<<"fake"<<'\n';
						break;
					}
				}
			}
	}
}