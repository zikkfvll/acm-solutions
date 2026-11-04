#include <iostream>
#include <iomanip>
using namespace std;
#define N 110
int main (){
	int a[N][N] , n , m;
	cin >> m;
	for(int t = 0 ; t < m ; t++){
		cin >> n;
		int  k = 1 , x = 0 , y = n-1 ;
		for(int s = n;s > 0 ; s-=2){	
			for(int i = 0 ;i < s  ; i++){
				a[x][y++] = k++;
			}
			x++;
			y--;
		/*	
			for(int i = 0; i < s; i++){
				a[x++][y] = k++;
			}
			x--;
			y--;
			
			for(int i = 0 ;i < s - 1 ;i++) {
				a[x--][y] = k++;
			}
			x++;
			y++;
			for(int i = 0 ;i < s - 2  ;i++) {
				a[x][y++] = k++;
			}
			y--;
			x++;
			
	*/	}
	
		for(int i = 0;i < n;i++)  {
			for(int j = 0;j < n;j++)
      		  	cout << setw(4) << a[i][j] << " ";
    		cout << endl;
		}
	}
   return 0;
	} 
