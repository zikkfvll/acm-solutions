// VS Code C/C++ 测试代码 "Hello World"
// 由 VSCodeConfigHelper v4.0.8 生成

// 您可以在当前文件夹（工作文件夹）下新建 .cpp 源文件编写代码。

// 按下 F6 编译运行。
// 按下 F5 编译调试。
// 按下 Ctrl + Shift + B 编译。

#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &ans)
{
    char ch = getchar();
    int f = 1;
    ans = 0;
    for (; !isdigit(ch); ch = getchar())
        ch == '-' ? f = -1 : f = 1;
    for (; isdigit(ch); ch = getchar())
        ans = (ans << 3) + (ans << 1) + (ch & 15);
    ans *= f;
    return;
}
template <typename T, typename... Args>
inline void read(T &tmp, Args &...tmps)
{
    read(tmp);
    read(tmps...);
}

template <class T>
inline void print(T ret, int flg = 0)
{
    static int sta[35];
    T x = ret;
    int top = 0;
    bool f = (ret < 0);
    if (ret < 0)
        x = -x;
    do
    {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    if (f)
        putchar('-');
    while (top)
        putchar(sta[--top] + 48);
    if (flg == 0)
        putchar(' ');
    else if (flg == 1)
        putchar('\n');
}
// template <class T, class... Args>
// inline void print(T &ret, Args& ... tmps)
// {
//     print(ret);
//     print(tmps...);
// }

int main()
{
    // 在标准输出中打印 "Hello, world!"
    int a, b;
    read(a, b);
    print(a + b, 1);
}

// 此文件编译运行将输出 "Hello, world!"。
// 按下 F6 后，你将在弹出的终端窗口中看到这一行字。
// !! 重要提示：请您在编写代码前，确认文件名不含中文或特殊字符。 !!
// 若遇到问题，请联系开发者 guyutongxue@163.com。