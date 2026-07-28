/*
问题描述
暑假集训期间，教练给同学们安排了每天的训练强度，强度组成一个长度为 n 的数组 a。第 i 个位置的数表示第 i 天的训练难度。

为了让训练安排统一，教练可以进行若干次操作。

每次操作中，教练可以选择一段连续区间 [l,r]，并把这段区间内的所有数都改成任意正整数，这次操作的代价，定义为该区间在修改前的最大值。

教练可以进行任意多次操作，也可以一次都不做。

请你计算，最少需要花费多少总代价，才能让整个数组中的所有数都变成相同的值。

输入格式
第一行输入一个整数 n(1≤n≤10^5)，表示数组长度。

第二行输入 n 个整数 a1,a2,…,an(1≤ai≤10^9)，表示每天初始的训练难度。

输出格式
输出一个整数，表示把整个数组变成相同数所需的最小总代价。

样例输入
5
3 1 4 1 4

样例输出
4*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    ll mnum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mnum = max(mnum, a[i]);
    }

    ll ans = 0;
    ll mcur = 0;
    for (ll x : a)
    {
        if (x == mnum)
        {
            if (mcur != 0)
            {
                ans += mcur;
                mcur = 0;
            }
        }
        else
        {
            mcur = max(mcur, x);
        }
    }
    if (mcur != 0)
        ans += mcur;

    ans = min(mnum, ans);

    cout << ans << '\n';

    return 0;
}