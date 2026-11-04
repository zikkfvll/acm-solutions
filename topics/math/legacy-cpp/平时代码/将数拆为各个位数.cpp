#include <iostream>
using namespace std;
int main (){
	int a = 342768;
	cout << a % 10 << endl;//个位 
	cout << a / 10 % 10 << endl;//十位 
	cout << a / 100 % 10 << endl;//百位 
	cout << a / 1000 % 10 << endl;//千位 
	cout << a / 10000 % 10 << endl;//万位
	cout << a / 100000 % 10 << endl;//十万位
	
	for(int unit = 1; unit <= 100000 ; unit *= 10) {
		cout << a / unit % 10 << endl; 
	} 
	return 0;
} 
