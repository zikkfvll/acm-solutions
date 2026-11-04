#include <bits/stdc++.h>
using namespace std;

int a[1024][1024] = {0};

void f(int n , int r,int c) 
{
	if(n == 0) {
		return ;
	} else {
		int b = pow(2 , n - 1);
		for(int i = 0; i < b ; i++ ){
			for(int j = 0;j < b ; j++) {
				a[r + i][c + j] = 1;
			}
		}
		
		f(n - 1 , r , c + b);
		
		f(n - 1 , r + b , c);
		
		f(n -1 ,r + b , c + b);
	}
}
int main()
{
	int n;
	cin >> n;
	f(n, 0, 0);
	for(int i = 0 ; i < pow(2 , n) ; i++) {
		for(int j = 0 ; j < pow(2 , n) ; j++) {
		cout << !a[i][j] << " ";
		}
		cout <<endl;
	}
	return 0;
}

