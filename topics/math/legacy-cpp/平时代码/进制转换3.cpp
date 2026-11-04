#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,r,i;

    
        if(n<0)
        {
            printf("-");n=-n;
        }
        if(n==0){printf("0\n");}
        int c=0,a[100];
        while(n)
        {
            a[c]=(n%r);
            c++;
            n/=r;
        }
        for(i=c-1;i>=0;i--)
        {
            if(a[i]>=10)
            {
                printf("%c",'A'+a[i]-10);
            }
            else printf("%d",a[i]);
        }
        printf("\n");
    
}
