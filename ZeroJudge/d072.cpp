#include <cstdlib>
#include <iostream>

int pd(int in0 ){
    
    if (in0 %400 ==0 )
       return 1 ;
    else if (in0 %100 ==0 )
         return 0 ;
    else if (in0 %4 ==0 )
         return 1 ;
    else 
         return 0 ;
}

using namespace std;
int main()
{
    int in0 ;
    
    cin >>in0 ;
    int in[in0] ;
    for (int i=0 ;i<in0 ;i++)
        cin >>in[i] ;
    
    for (int i=0 ;i<in0 ;i++)
        cout <<"Case " <<i+1 <<": " <<(pd(in[i])==1?"a leap year" :"a normal year" ) <<endl ;
        
    return EXIT_SUCCESS;
}