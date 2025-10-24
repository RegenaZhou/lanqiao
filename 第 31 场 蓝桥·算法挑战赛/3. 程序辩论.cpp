/*
问题描述
蓝桥学院与瓦罗兰特学院正在开展程序设计交流活动。小蓝作为蓝桥学院的代表，将轮流与瓦罗兰特学院的 N 位同学进行程序设计辩论。
每位瓦罗兰特学院同学拥有一个程序设计能力值 Ai。

每轮辩论，小蓝可以随意选择一位尚未辩论过的对手。如果小蓝的当前程序设计能力小于对手的能力值，则辩论失败，整个活动结束，小蓝落败。
否则，小蓝获胜，该对手被击败，小蓝的程序设计能力将增加对手能力值的一半（向下取整，即⌊Ai/2⌋）。
若小蓝成功击败所有 N 位对手，则蓝桥学院赢得整场比赛。

请确定小蓝最小的正整数初始程序设计能力值，使得蓝桥学院能够获胜。

输入格式
第一行包含一个整数 N（1≤N≤10^5），表示瓦罗兰特学院同学的数量。

第二行包含 N 个整数 A1,A2,…,AN（1≤Ai≤10^9），表示每位同学的程序设计能力值。

输出格式
输出一个整数表示答案。

样例输入
3
1 2 4

样例输出
3*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    ll ans = 0;
    cin >> n;
    vector<ll> sz(n);
    for (int i = 0; i < n; i++)
    {
        cin >> sz[i];
    }
    sort(sz.begin(), sz.end(), greater<ll>());
    ans = sz[0];
    for (int i = 1; i < n; i++)
    {
        ans = max(ans - sz[i] / 2, sz[i]);
    }
    cout << ans << '\n';
    return 0;
}