#include <iostream>
using namespace std;
int main ()
{
   int a[50];
   for(int i = 0; i < 30; i++){
		cin >> a[i];
   } 
   for(int i = 29; i >=0 ; i--){
   		cout << a[i] << endl;
   }
   return 0;
}

