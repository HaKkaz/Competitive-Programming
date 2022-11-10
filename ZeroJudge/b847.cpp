#include<bits/stdc++.h>
using namespace std;
int times[30];
const char x0='A'^'a';
double per[30];
void init()
{
	fill(per,per+27,0);
	fill(times,times+27,0);
}
int main(){
	string str;
	while(getline(cin,str))
	{
		init();
		for(int i=0;i<(int)str.size();i++)
			if(str[i]=str[i]|x0,str[i]>='a'&&str[i]<='z')
				times[str[i]-'a']++;
		int tot=0;
		for(int i=0;i<26;i++){
			tot+=times[i];
		}
		for(int i=0;i<26;i++)
		{
			if(times[i])	per[i]=(double)times[i]/(double)tot;
		}
		
		for(int i=0;i<26;i++)	cout<<times[i]<<' ';
		cout<<'\n';
		for(int i=0;i<26;i++)	cout<<fixed<<setprecision(2)<<per[i]*100<<' ';
		cout<<'\n';
	}
}