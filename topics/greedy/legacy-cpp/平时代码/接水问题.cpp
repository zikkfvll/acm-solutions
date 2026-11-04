#include<iostream>
using namespace std;
#define N 110000
int main(){
	int n , m , x , k , b[N];
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
    	cin >> x;
    	k = 1;
    	for(int j = 2 ; j <= m ; j++){
    		if(b[j] < b[k]){
    			k = j;
			}
		}
    	b[k] += x;
	}
	k = 1;
	for(int i = 2 ; i <= m ; i++){
		if(b[i] > b[k]){
			k = i;	
		}	
	}
    cout << b[k];
    return 0;
}
