
#include<iostream>
#include<windows.h>
using namespace std;
int main()
{
	int t=2000;
    while(1)
    {
   	    t--;
        system("data.exe > data.txt");
        system("a.exe < data.txt > a.txt");
        system("css.exe < data.txt > css.txt");
        if(system("fc css.txt a.txt"))   break;
    }
    if(t==0) cout<<"no error"<<endl;
    else cout<<"error"<<endl;
    //system("pause");
    return 0;
}