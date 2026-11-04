#include<iostream>
using namespace std;
int main()
{
	int n , begin[1100] , end[1100] , tail , cnt;
	
	cin >> n;
	for(int i = 0; i < n ; i++){
		cin >> begin[i] >> end[i];
	}
	
	
	for(int i = 0; i < n ; i++){
		for(int  j = 0;j < n - i- 1 ;j++){
			if(end[j] > end[j + 1]){
				swap(end[j] , end[j + 1])
				w
			}
		}
	}
    return 0;
}
