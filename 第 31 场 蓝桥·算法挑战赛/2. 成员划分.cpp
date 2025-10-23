/*
问题描述
蓝桥学院正在组织一场程序设计交流活动，总共有 n 名学生参加，每名学生有一个编号 ai。

为了促进交流，学院决定将这些学生按顺序划分成若干个连续的小组（即子区间），
每个小组内必须满足奇数编号的学生个数等于偶数编号的学生个数，你必须保证每位学生都属于某一个小组。

现在，请你计算出最多能划分出多少个这样的小组。如果无法将所有学生划分成满足条件的小组，则输出 −1。

输入格式
第一行包含一个整数 n（1≤n≤10^5），表示学生总数。

第二行包含 n 个整数 a1,a2,…,an（1≤ai≤10^9），表示每名学生的编号。

输出格式
输出一个整数，表示最多能划分的小组数量。如果无法完整划分所有学生，则输出 −1。*/
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, js = 0, ys = 0, ans = 0;
    cin >> n;
    vector<ll> sz(n);
    for (int i = 0; i < n; i++)
    {
        cin >> sz[i];
        if (sz[i] % 2 == 0) ys++, sz[i] = -1;
        else js++, sz[i] = 1;
    }
    if (js != ys)
    {
        cout << "-1\n";
        return 0;
    }
    js = 0, ys = 0;
    for (int i = 1; i < n; i++)
    {
        sz[i] = sz[i] + sz[i - 1];
        if (sz[i] == 0)
        {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}