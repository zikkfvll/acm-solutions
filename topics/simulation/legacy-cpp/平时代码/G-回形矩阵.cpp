#include <iostream>
using namespace std;
#define N 110
int main (){
	int n , a[N][N];
    cin >> n;
    int k = 1 , x = 0 , y = n - 1;
    while(k < (n*0.5)+1){
    	for(int i = x;i <= y;i++)
    		a[x][i] = k;
    	for(int i = x + 1;i <= y;i++)
    		a[i][y] = k;
    	for(int i = y-1;i >= x;i--)
    		a[y][i] = k;
    	for(int i = y-1;i >= x +1;i--)
    		a[i][x] = k;
    	y--;
		x++;
		k++;
	}
    
	for(int i = 0;i < n;i++)  {
		for(int j = 0;j < n;j++)
        	cout << a[i][j] << " ";
    	cout << endl;
	}
   return 0;
} 
