#include<iostream>
using namespace std;
int main()
{	
	char a[15];
	cin >> a;
	int n = 0;
	for(int i = 0;a[i];i++){
		if(a[i] >= '0' && a[i] <= '9')
			n = n * 16 +a[i] - '0'; 
		else
			n = n * 16 + a[i] - 'A' + 10;
	
	}
		
	cout << n << endl;
	return 0;
} 
