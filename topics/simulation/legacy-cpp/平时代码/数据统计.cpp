#include <iostream>
using namespace std;
int main (){
	int num = 0, i = 0;
	int a[10] = {};
  	cin >> num; 
    while(num) 
	{
        a[num % 10]++; 
        num /= 10;
    }

    for (i = 0; i < 10; i++) 
	{
        if(a[i] != 0)
		{
			cout << i <<  a[i];
		}   
    }
	
	return 0;
}
