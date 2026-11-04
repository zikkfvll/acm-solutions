#include <iostream>
using namespace std;
int main ()
{
   int a = 1;  // 局部变量定义 
   while( a < 101 )   { // while 循环执行   
      cout << "a = " << a << endl; 
      a++;
   }
   return 0;
}

