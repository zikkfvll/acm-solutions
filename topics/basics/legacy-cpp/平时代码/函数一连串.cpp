#include <iostream>
using namespace std;

int F(int &x) {
    x ^= x & (x << 3);
    x ^= x & (x >> 2);
    x %= 65536;
    return x;
}

int G(int &x) {
    x ^= x & (x << 2);
    x ^= x & (x >> 3);
    x %= 65536;
    return x;
}

int main (){
	string s;
	int n ;
	cin >> s >>n;
	for(int i = 0; i <s.size() ; i++){
		if(s[i] == 'F') {
			n = F(n);
		}	
		if(s[i] == 'G') {
			n =G(n);
		}
		
	}
	cout << n; 
	return 0;
} 
