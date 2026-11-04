#include<iostream>
using namespace std;
int main(){
    int a;
    bool first = true;
    string b;
    cin>> a >> b;
    for(int i = 0 ; i < b.size() ; i++){
        if(b[i] != '0'){
            if(first != true) {
            	cout << "+";
			}
            cout << b[i] << "*" << a << "^" << b.size()-i-1;
            first = false;
        }
    }
    return 0;
}
