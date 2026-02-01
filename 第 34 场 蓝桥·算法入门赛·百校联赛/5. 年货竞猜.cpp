/*
问题描述
春节将至，蓝桥学院组织了一场热闹的 "年货智力竞猜" 活动！活动现场摆放了一份超级年货大礼包，谁能最快答对下面的数学谜题，就能把这份装满各种年货的大礼包抱回家！

小蓝作为主持人，每次竞猜会给出一个正整数 n，并定义了 f(n,k) 为：f(n,k)=i=1∑n (imodk)
其中 imodk 表示 i 除以 k 的余数。

小蓝的问题是：在所有可能的正整数 k 中，有多少个 k 能让 f(n,k) 恰好被 k 整除？

最快答对的同学就能赢得这份诱人的年货大礼包，请你来尝试回答小蓝的每次询问吧。

输入格式
第一行一个整数 T（1≤T≤10^3），表示测试用例数量。

接下来 T 行，每行一个整数 n（1≤n≤10^9）。

输出格式
对于每个测试用例，输出一行一个整数，表示满足条件的 k 的个数。

样例输入
4
26
2
10
5

样例输出
8
2
4
4
copy
说明
对于 n=2 的情况，满足条件的 k 有 1,3。*/
#include <iostream>
using namespace std;
using ll = long long;
ll ys(ll x)
{
    int ans = 1;
    for (ll i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            int cnt = 0;
            while (x % i == 0)
            {
                cnt++;
                x /= i;
            }
            ans *= (cnt + 1);
        }
    }
    if (x > 1)
    {
        ans *= 2;
    }
    return ans;
}
void solve()
{
    ll n, a, b, ans1 = 1, ans2 = 1;
    cin >> n;
    a = n, b = n + 1;
    if (a % 2 == 0)
    {
        a /= 2;
    }
    else
    {
        b /= 2;
    }
    ans1 = ys(a), ans2 = ys(b);
    cout << ans1 * ans2 << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}