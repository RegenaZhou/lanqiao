/*
问题描述
国庆假期即将来临，小蓝所在的蓝桥程序设计班举办了一场热闹的礼品任选活动，总共有 N 件商品可供挑选，其中第 i 件商品的价值为 Ai。

小蓝运气不错，通过抽签获得了优先挑选资格，但他最多只能选择 X 件商品，且这些商品的价值必须完全相同。请问，小蓝能选出的商品总价值最大是多少？

输入格式
第一行包含两个整数 N,X(1≤X≤N≤10^5)，分别表示商品数量和最多可选件数。

第二行包含 N 个整数 A1,A2,…,AN(1≤Ai≤N)，表示每件商品的价值。

输出格式
输出一个整数，表示小蓝能选出的商品总价值的最大值。

样例输入
5 2
1 2 2 3 4

样例输出
4*/
#include <iostream>
#include <map>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, x;
    ll ans = 0;
    cin >> n >> x;
    map<int, int> sz;
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        sz[a]++;
    }
    for (auto const& pair : sz)
    {
        ll yx = 0;
        if (pair.second >= x) yx = pair.first * x;
        else yx = pair.first * pair.second;
        ans = max(ans, yx);
    }
    cout << ans << '\n';
    return 0;
}