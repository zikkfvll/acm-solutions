#include <iostream>
using namespace std;
int main ()
{
   int a = 1;  // 局部变量定义 
   while( true )   { // while 循环执行   
      cout << "a = " << a << endl; 
      a = a + 1;
      if(a == 101){
      	break;
	  }
    }
   return 0;
}

