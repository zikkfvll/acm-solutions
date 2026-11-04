#include <iostream>
using namespace std;

int main (){
	int n , a[60][60];
    cin >> n;
    int k = 1 , m = n ,x = 0 , y = n - 1;
    for(m;m > 0;m = m-2){
    	for(int i = 0;i < m;i++)
    		a[x++][y] = k++;
    	x--;y--;
    	for(int i = 0;i < m- 1;i++)
    		a[x][y--] = k++;
    	x--;y++;
    	for(int i = 0;i < m- 1;i++)
    		a[x--][y] = k++;
    	x++;y++;
    	for(int i = 0;i < m- 2;i++)
    		a[x][y++] = k++;
    	y--;
    	x++;
	}
	for(int i = 0;i < n;i++)  {
		for(int j = 0;j < n;j++)
        	cout << a[i][j] << " ";
    	cout << endl;
	}
   return 0;
} 
