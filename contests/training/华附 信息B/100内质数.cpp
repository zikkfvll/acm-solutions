#include<bits/stdc++.h>
using namespace std;

int main(){
	int i;
	for(i = 2; i <= 100 ; i++){
		int k = 0;
		for(int w = 2; w < i ;w++){
			if(i % w == 0){
				k = 1;
				break;
			}
		}
		if(k == 0){
			cout << i << " ";
		}
	} 
	return 0;
} 
