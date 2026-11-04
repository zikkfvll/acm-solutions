#include <iostream>
using namespace std;
int f( int n)
{
    if (n <= 9) {
    	cout << n;
	} 
	else{
    	int m = 0;
		m = n % 10;
    	n = n / 10;
    	if (n > 9) {
			f(n) ;
    	}
		else {
			cout<<n<<endl;
		}
    	cout << m << endl;
    }

}
int main()
{
    int n;
    cin >> n;     
    f(n);    
    return 0;
}
