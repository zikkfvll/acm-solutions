#include<iostream>
using namespace std;
int main()
{
    int a;
    cin >> a;
    
    if(a & 1 ){
    	a <<= 2;
		a |= 0xf;
		a ^= 0xff; 
	}
	else {
		a >>= 2;
		a |= 0xff;
		a ^= 0xf; 
	}
	cout << a << endl;
    return 0;
}

