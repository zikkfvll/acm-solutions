#include <bits/stdc++.h>
long long a, b, ans, res, t;
int main() {
    std::cin >> a >> b;
    if (a > b) std::swap(a, b);
    t = (a - 1) * b / a - 1;
    res = (res + (a - 1) * b) % a;
    std::cout << t * a + res;
    return 0;
}