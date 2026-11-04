#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>



template<class T>
inline void print(T ret,int flg=0){
    static int sta[35];
    T x=ret;int top=0;
    bool f=(ret<0);
    if(ret<0) x=-x;
    do{sta[top++]=x%10,x/=10;}while(x);
    if(f) putchar('-');
    while(top) putchar(sta[--top]+48);
    if(flg==0)putchar(' ');
    else if(flg==1)putchar('\n');
}

template<typename T>
inline void read(T &ans){
    char ch=getchar();int f=1;ans=0;
    for(;!isdigit(ch);ch=getchar()) ch=='-'?f=-1:f=1;
    for(;isdigit(ch);ch=getchar()) ans=(ans<<3)+(ans<<1)+(ch&15);
    ans*=f;
    return;
}
template<typename T,typename ...Args>
inline void read(T &tmp,Args &...tmps){read(tmp);read(tmps...);}

using namespace std;
double f(double x , double a , double b , double c)
{
    return (a* x * x + b * x - c);
}
int main()
{
    double x1 , x2 , xx , a , b , c;//x1,x2代表区间左右边界，xx代表方程的值
    cin >> a >> b >> c; 
    do
    {
        cin >> x1 >> x2;
    }
    while(f(x1 , a , b , c)*f(x2 , a , b , c) > 0);//保证f(x1)和f(x2)是异号，这样才可以进行下一步的精准区间，否则，重新输入x1，x2的值
   /* do
    {
      xx = (x1 + x2) / 2;
        if(f(xx , a , b , c)*f(x1 , a , b , c)>0)
            x1 = xx;
        else
            x2 = xx;
    }
    while(fabs(f(xx , a , b , c))>=1e-7);//le-6代表1*10的-6次方，它的值将影响到跟的准确度的问题
    printf("%.2lf\n",xx);*/
    return 0;
}
