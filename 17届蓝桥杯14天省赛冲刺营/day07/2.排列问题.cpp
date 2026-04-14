/*
问题描述
小婷很生气，因为她不会做下面这道题，给定一个数组，现在需要你回答这个数组有多少个子序列是一个排列。

注意：子序列指的是原数组删除若干个数形成的新序列。

输入格式
第一行含有一个数字 n ，代表数组长度。

第二行含有 n 个数字，代表给定数组 a。

输出格式
输出一行一个数字，表示子序列个数。

样例输入
5
1 2 1 3 4

样例输出
8

说明
1≤n≤10^5 ，1≤ai≤10^9 。

满足题意的子序列为:
[1],[1],[1,2],[2,1],[1,2,3],[2,1,3],[1,2,3,4],[2,1,3,4]。*/
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n + 1, 0);
    ll maxn = 1, num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        a[num]++;
        maxn = max(maxn, num);
    }
    ll temp = 1, ans = 0;
    for (int i = 1; i < maxn; i++)
    {
        temp *= a[i];
        ans += temp;
    }
    cout << ans << '\n';
    return 0;
}