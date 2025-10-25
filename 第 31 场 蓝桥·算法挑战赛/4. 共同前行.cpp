/*
问题描述
在一次校际学术交流活动中，两个学院的代表：小蓝与小桥，被安排一同前往主会场。

主会场与校门口之间有一条笔直的林荫大道。两人从校门口同时出发，沿着这条路向前行进。

为了体现两院之间“并肩同行、友好互助”的精神，组织方设定了两项特别的规定：

每次，他们中只能有一人向前迈出 1 米，另一人则在原地等待，保持协调与平衡。
两人之间的距离始终不得超过2 米。
从校门口到主会场，总共有 N 米。当两人都抵达主会场时，行程即告结束。
现在，请你计算在满足上述条件的前提下，小蓝与小桥共有多少种不同的行进方式？
由于答案可能很大，你只需给出其对 10^9+7 取余后的结果即可。

输入格式
第一行包含一个整数 T（1≤T≤10^3 ），表示测试数据的组数。

接下来 T 行，每行包含一个整数 N（1≤N≤10^9），表示从校门口到主会场的距离（单位为米）。

输出格式
输出 T 行，每行一个整数，表示满足条件的不同行进方式数量对 10^9+7 取余后的结果。

样例输入
1 
2

样例输出
6*/
#include <iostream>
using namespace std;
using ll = long long;
const ll mood = 1e9 + 7;

ll ksm(ll x, ll n)
{
    ll res = 1;
    while (n)
    {
        if (n & 1) res = res * x % mood;
        x = x * x % mood;
        n >>= 1;
    }
    return res;
}

void solve()
{
    ll n;
    cin >> n;
    if (n == 1)
    {
        cout << 2 << '\n';
        return;
    }
    ll ans = 2 * ksm(3, n - 1) % mood;
    cout << ans << '\n';
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