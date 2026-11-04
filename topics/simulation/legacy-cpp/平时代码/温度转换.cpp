#include<bits/stdc++.h>
using namespace std;

double tem (double a , double t){
	if(t == 1) {
		return 9.0 / 5 * a + 32;
	}
	else {
		return (a - 32) * 5.0 / 9;
	}
} 
int main (){
	int q , type;
	double A;
	cin >> q;

	
	while(q--) {
		cin >> A >>type;
		cout<< fixed << setprecision(3);
		cout << tem(A , type) << endl;
	}
		return 0;
} 
