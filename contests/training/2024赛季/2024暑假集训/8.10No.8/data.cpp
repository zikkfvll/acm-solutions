#include <iostream> 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <algorithm>
#include <windows.h>
using namespace std;
//ofstream cout("data.in");
int main()
{
	srand(time(0));
//	srand( (unsigned)time( NULL ) );
	//freopen("input.txt","w",stdout); 
	int n,m,b[550][550];
	n=rand()%100+1, m=rand()%100+1;
    for(int i = 1; i <= n;++i)for(int j = 1; j <= m;++j) b[i][j] = rand()%10000000+100;
	cout << n << " " << m << endl;
    for(int i = 1; i <= n;++i)for(int j = 1; j <= m;++j) cout << b[i][j] << " ";
	return 0;
}