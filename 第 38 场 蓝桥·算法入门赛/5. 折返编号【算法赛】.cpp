/*
问题描述
对于正整数 x，定义 v2(x) 为 x 能被 2 连续整除的次数。

例如：

v2(12)=2，因为 12÷2÷2=3，之后不能再被 2 整除；
v2(40)=3，因为 40÷2÷2÷2=5。
现在只考虑那些不是 2 的幂的正整数 n。

设 t=v2(n)。也就是说，2^t 是 n 中能整除出来的最大 2 的幂。

我们把 n 变成：n−2^t


如果这个新数的 v2 值恰好等于 k，就称 n 是一个好数。

给定 N 和 k，请你求出 1 到 N 中有多少个好数。

注意：如果 n 本身是 2 的幂，则它不算好数。

输入格式
输入一行，包含两个正整数 N,k（1≤N≤10^18，1≤k≤60）。

输出格式
输出一行，包含一个整数，表示答案。

样例输入
20 1

样例输出
5

样例说明
对于样例，N=20,k=1。

满足条件的数为：3,7,11,15,19

以 n=11 为例，v2(11)=0，所以要计算：11−2^0 = 10
而 v2(10)=1，所以 11 是一个好数。*/
#include <iostream>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, k, ans = 0, p;
    cin >> n >> k;

    p = 1LL << k;
    for (int i = 0; i < k; i++)
    {
        ll low = 1LL << i;
        if (low + p > n) continue;

        ll m = (n - low) / p;
        ans += (m + 1) / 2;
    }

    cout << ans << '\n';

    return 0;
}
