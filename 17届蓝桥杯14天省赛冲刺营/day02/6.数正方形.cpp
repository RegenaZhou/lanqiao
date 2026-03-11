/*
题目描述
在一个 N×N 的点阵上，取其中 4 个点恰好组成一个正方形的 4 个顶点，一共有多少种不同的取法？

由于结果可能非常大，你只需要输出模 10^9+7 的余数。

如上图所示的正方形都是合法的。

输入描述
输入包含一个整数 N (2≤N≤10^6)。

输出描述
输出一个整数代表答案。

输入输出样例
示例
输入
4

输出
20*/
#include <iostream>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, ans = 0, mood = 1e9 + 7;
    cin >> n;
    n--;
    for (ll i = 1; i <= n; i++)
    {
        ll temp;
        temp = (((n - i + 1) * (n - i + 1)) % mood * i) % mood;
        ans = (ans + temp) % mood;
    }
    cout << ans << '\n';
    return 0;
}