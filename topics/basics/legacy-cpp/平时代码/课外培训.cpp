#include<iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n=0,max=0,min = 100;
	float sum = 0;
    int a[100];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    if(a[i]>max) max=a[i];
    if(a[i]<min) min=a[i];
    sum +=a[i];
    }
    cout << max << " " << min << " " << setiosflags(ios::fixed) << setprecision(2) << sum / n << endl;
    return 0;
}

