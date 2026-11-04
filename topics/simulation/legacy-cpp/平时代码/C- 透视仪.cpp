#include <iostream>
#include<stdio.h>
using namespace std;
#define N 20
int main (){
	int n , a[N][N];
	char t[N][N];
    cin >> n;
    while( n-- ){
    	int a[N] = {0};
		int b[N] = {0};
    	getchar();
    	for(int i = 0;i < 10;i++)	
			gets(t[i]);
		for(int i = 0;i < 10;i++){
			for(int j = 0;j < 15;j++){
				if(t[i][j] == '#'){
					a[i] ++;
					b[j] ++; 
				}
			}
		}
		for(int i = 0;i < 10;i++)
			cout<< a[i] << " ";
		cout << endl;
		for(int j = 0;j < 15;j++)
			cout << b[j] << " ";
		cout << endl;
	} 
   return 0;
} 
