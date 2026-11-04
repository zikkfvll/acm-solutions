#include <iostream>
using namespace std;
string f(string a,string b){
	if(a.size() < b.size() || a.size() == b.size() && a < b) {
		return a;
	}
	else {
		return b;
	}
}

int main() {
	int  n;
	string a , b;
	cin >> n ;
	for(int i = 1; i <= n; i++ ){
		cin >> a >> b;
		cout << f(a , b) <<endl; 
	}
	return 0;
}
