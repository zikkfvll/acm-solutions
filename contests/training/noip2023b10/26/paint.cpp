//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
struct point
{
    int x;
    int y;
    // int xx;
    // int yy;
};
bool vis[1 << 20][25];
int n, pre[20], stain[20], mapp[1100000][25], res = 30;
int x[20], y[20], xx[20], yy[20];

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

// inline bool check(int x ){
//     int qy = a[x].y - 1;
//     for(int i = a[x].x;i<=a[x].xx;++i)
//         if(!mapp[qy][i]) return false;
//     return true;
// }

// inline void stain(int step) {
//     for(int i =a[step].x;i<=a[step].xx;++i){
//         for(int j = a[step].y;j<=a[step].yy;++j)
//             mapp[j][i] = 1;
//     }
// }

// inline void dfs(int qx , int cnt , int step) {
//     if(cnt >= res) return;
//     if(cnt == n) {
//         res = min(res , step);
//         return;
//     }
//     for(int i = 1;i<=n;++i) {
//         if(!vis[i] && check(i)) {
//             vis[i] = 1;
//             stain(i);
//             dfs(i , cnt+1 , step+1);
//             vis[i] = 0;
//             stain(i);
//         }
//         else{
//             continue;
//             qx=min(qx , i);
//         }
//     }
// }

queue<point> q;
inline void init() {
    read(n);
    for (int i = 1; i <= n; ++i) read(x[i] , y[i] , xx[i] , yy[i] , stain[i]);
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) if (i != j && x[i] == xx[j] && y[i] < yy[j] && yy[i] > y[j]) pre[i] |= 1 << (j - 1);
    memset(vis, 0, sizeof(vis));
    memset(mapp, 10, sizeof(mapp));
}

int main() {
    // a[i].x++;
    // a[i].y++;
    // a[i].xx++;
    // a[i].yy++;
    // for(int i=1;i<=n;++i) {
    //     memset(mapp , 0 , sizeof(mapp));
    //     memset(vis , 0 , sizeof(vis));
    //     for(int j =0;j<= n+1;++j)
    //         mapp[0][i] = true;
    //     if(check(i)) {
    //         stain(i);
    //         vis[i] = true;
    //         dfs(i , 0 , 1);
    //     }
    // }

    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    init();
    for (int i = 1; i <= n; ++i)
    {
        if (pre[i] == 0)
        {
            point p;
            p.x = 1 << (i - 1);
            p.y = stain[i];
            mapp[p.x][p.y] = 1;
            vis[p.x][p.y] = true;
            q.push(p);
        }
    }
    while (!q.empty())
    {
        /* code */
        point p = q.front();
        q.pop();
        for (int j = 1; j <= n; ++j)
        {
            if ((p.x & (1 << (j - 1))) == 0 && (p.x & pre[j]) == pre[j])
            {
                point p1;
                p1.x = p.x | (1 << (j - 1));
                p1.y = stain[j];
                mapp[p1.x][p1.y] = min(mapp[p1.x][p1.y], mapp[p.x][p.y] + (p.y != p1.y));
                if (!vis[p1.x][p1.y])
                {
                    q.push(p1);
                    vis[p1.x][p1.y] = true;
                }
            }
        }
    }
    for(int i=1;i<=20;++i)	res=min(res,mapp[(1<<n)-1][i]);
    print(res ,1);
    return 0;
}
