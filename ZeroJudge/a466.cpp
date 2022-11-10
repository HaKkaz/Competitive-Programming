#include<iostream>
#include<string>
#define endl '\n'
using namespace std;
int main(){
    string str;
    int n,str1,str2,str3;
    cin>>n;
    while(n--){
        cin>>str;
        if(str.size()==5){
        	cout<<3<<endl;
        	continue;
        }
        str1=(str[0]=='o')+(str[1]=='n')+(str[2]=='e');
        str2=(str[0]=='t')+(str[1]=='w')+(str[2]=='o');
        if(str1>=2) cout<<"1"<<endl;
        else cout<<"2"<<endl;
    }
}