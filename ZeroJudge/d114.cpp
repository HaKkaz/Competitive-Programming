#include<iostream>

short int ans[10000] = {0};//十進位大數 
int length = 3;

void carry()
{
    int i=0;
    for(int i=0; i<length; i++)
    {
        if(ans[i]>=10)
        {
            ans[i+1] += (ans[i]/10);
            ans[i]%=10;
        }
    }
    
    while(ans[length])
    {
        if(ans[length]>=10)
        {
            ans[length+1] += (ans[length]/10);
            ans[length]%=10;
        }
        length++;
    }
}

void mult(int n)
{

    for(int i=0; i<length; i++)
    {
        ans[i] *= n;
    }
    
    carry();
}

int main()
{
     ans[2] = 1;
     for(int i=2; i<=99; i++)
        for(int j=0; j<=100-i; j++)
        {
            mult(i);
        }
        
    for(int i=length-1; i>=0; i--)
        printf("%d\n",ans[i]);

}