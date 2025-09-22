/*
问题描述
国庆假期即将到来，蓝桥学院的程序设计班计划采购 N 件礼品，用于举办一场精彩的国庆竞赛。

小蓝是班里公认的“大菜狗”，于是采购任务自然落在了他的肩上。商店老板是小蓝的好友，得知此事后，便想借此机会考验一下小蓝的程序设计水平是否有所进步。

这 N 件礼品中，第 i 件的价格为 Ai。小蓝可以按任意顺序购买，每次购买一件礼品后，剩余所有礼品的价格都会降低 X 元，
当商品价格变为负数时将会变回 0 元（老板总不能倒亏钱）。请问，小蓝最少需要花费多少钱才能买齐所有礼品？

输入格式
第一行包含两个整数 N,X(1≤N≤10^5,1≤X≤10^9)，分别表示礼品数量和每次降价金额。

第二行包含 N 个整数A1,A2,…,AN(1≤Ai≤10^9)，表示每件礼品的初始价格。

输出格式
输出一个整数，表示小蓝购买所有礼品的最少花费。

样例输入
3 3
7 3 4

样例输出
5*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, x, ans = 0;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        ans += max(0ll, a[i] - i * x);
    }
    cout << ans << '\n';
    return 0;
}