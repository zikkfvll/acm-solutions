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
	string a , b;
	cin >> a >> b;
	cout << f(a , b) <<endl; 
	return 0;
}
