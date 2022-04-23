#include <iostream>
using namespace std;

class T1;
class T2 {
    private:
      int num;
    public:
      // TO DO
      T2(int _num):num(_num){}
      friend int add(T2,T1);
};

class T1 {
    private:
       int num;
    public:
      // TO DO
      T1(int _num):num(_num){}
      friend int add(T2,T1);
};

int add(T2 classA, T1 classB)
{
   return (classA.num + classB.num);
}

int main()
{
	int n1,n2;
	cin >> n1 >> n2 ;
    T2 opA(n1);
    T1 opB(n2);
    cout<< add(opA, opB) ;
    return 0;
}