/*
问题描述
双十一零点倒计时只剩几分钟，小蓝的网店订单如潮水般涌来。为了吸引更多顾客，他决定推出一种灵活的分期支付方案：
顾客可以自由选择分期数 A（正整数），系统会计算订单总金额 N 除以 A 的余数。若余数正好为 K 元，那么顾客将额外获得一张面值为 K 元的优惠券。

作为小蓝的助理，你需要快速计算出，有多少个不同的分期数 A 能让订单金额除以后得到的余数恰好为 K。
换句话说，你需要统计出所有满足 NmodA=K 的正整数 A 的数量。

输入格式
输入两个整数 N 和 K（1≤N≤10^9，0≤K<N），其含义如上所述。

输出格式
输出一个整数，表示满足条件的正整数 A 的个数。

样例输入
8 2

样例输出
2*/
#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;
int main()
{
    ll n, k, ans = 0;
    cin >> n >> k;
    n -= k;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i > k) ans++;
            ll j = n / i;
            if (j != i && j > k) ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}