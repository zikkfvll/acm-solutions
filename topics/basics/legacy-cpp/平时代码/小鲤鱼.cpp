#include <iostream>
using namespace std;

int f(int n){
	cout << "dog" << " ";
	for(int i = 0; i < n ; i++) {
		cout << "hug" << " ";
	}
	cout << "fish" << " ";
	for(int i = 0; i < n ; i++) {
		cout << "me" << " ";
	}
}

int main (){
	int n;
	cin >> n;
	f(n);
	return 0;
} 
