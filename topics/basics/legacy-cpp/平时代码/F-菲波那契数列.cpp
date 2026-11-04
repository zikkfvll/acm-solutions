#include <iostream>
using namespace std;
int main ()
{
	int n[50] = {0,1} , a ;
	cin >> a;
	cout << n[0] << endl << n[1] <<endl;
	for(int i= 2; i < a ;i++){
   		n[i] = n[i -2] + n[i - 1];
   		cout << n[i];
   		cout << endl;	
   }
   return 0;
}

