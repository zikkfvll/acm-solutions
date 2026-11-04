#include <bits/stdc++.h>
using namespace std;

#define H 2
#define W 4

char unit[2][5] = {" /\\ ",
				   "/__\\"};
				   
char a[512*H][512*W] = {0};

void f(int n , int r,int c) 
{
	if(n == 1) {
		for(int i = 0; i < H ; i++ ){
			for(int j = 0;j < W ; j++) {
				a[r + i][c + j] = unit[i][j];
			}
		} 
	}
	else {
		f(n - 1 , r , c + pow(2 , n - 3)* W);
		
		f(n - 1 , r + pow(2 , n - 2) * H , c);
		
		f(n - 1 ,r + pow(2 , n - 2) * H , c + pow(2 , n - 2) * W);
	}	
	
}
int main()
{
	int n;
	cin >> n;
	memset(a,' ',sizeof(a));
	f(n, 0, 0);
	for(int i = 0 ; i < pow(2 , n - 1) * H; i++) {
		for(int j = 0 ; j < pow(2 , n - 1) * W; j++) {
		cout << a[i][j];
		}
		cout <<endl;
	}
	return 0;
}

