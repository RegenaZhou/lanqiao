/*
问题描述
航天工程师小蓝正在为月球探测器设计最佳航线。地球到月球的航程被分为 N 个阶段，
地球位于第 1 阶段，月球位于第 N 阶段。在第 i 个阶段（1≤i<N），
探测器可以进行一次“空间跳跃”，跳跃到 i+1,i+2,…,Ai 中的任意一个阶段。

为了节省燃料，小蓝希望用最少的跳跃次数抵达月球。
现在，请你帮助小蓝计算出探测器从地球（阶段1）到月球（阶段N）所需的最少跳跃次数。

输入格式
第一行包含一个整数N（2≤N≤10^5），表示航程的阶段数。

第二行包含 N−1 个整数A1,A2,…,AN−1（i<Ai≤N），
其中 Ai 表示在第 i 个阶段，探测器最多可以跳跃到的阶段。

输出格式
输出一个整数，表示探测器从地球到月球所需的最少跳跃次数。

样例输入
6
5 6 6 6 6

样例输出
2*/
#include <iostream>
using namespace std;
const int N = 1e5 + 9;
int a[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int l = 1, r = 1;
    int mx = r;
    int ans = 0;
    while (mx < n)
    {
        mx = r;
        for (int i = l; i <= r; i++)
        {
            mx = max(mx, a[i]);
        }
        l = r + 1;
        r = mx;
        ans++;
    }
    cout << ans << '\n';
    return 0;
}