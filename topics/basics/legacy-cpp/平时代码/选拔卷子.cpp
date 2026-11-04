#include<iostream>
using namespace std;

int main(){   
	int N,c,b;
	cin >> N >> c >> b;
	b /= 100;
	if(b == 7){
		if(c >= N){
			cout << "Yes";
		}
		else{
			cout << "No";
		}
	}
	else if(b == 8){
		if(c >= N + 10){
			cout << "Yes";
		}
		else{
			cout << "No";
		}
	}
      return 0;
}

