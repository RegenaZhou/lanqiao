/*
问题描述
小蓝正在数轴上挖矿，数轴上一共有 n 个矿洞，第 i 个矿洞的坐标为 ai 。 小蓝从 0 出发，每次可以向左或向右移动 1 的距离，当
路过一个矿洞时，就会进行挖矿作业，获得 1 单位矿石，但一个矿洞不能被多次挖掘。小蓝想知道在移动距离不超过 m 的前提下，最多能获得多少单位矿石?

输入格式
输入的第一行包含两个正整数 n,m，用一个空格分隔。

第二行包含 n 个整数 a1,a2,⋯,an ，相邻整数之间使用一个空格分隔。

输出格式
输出一行包含一个整数表示答案。

样例输入
5 4
0 -3 -1 1 2

样例输出
4

样例说明
路径：0→−1→0→1→2，可以对 0,−1,1,2 四个矿洞挖掘并获得最多 4 块矿石。

评测用例规模与约定
对于 20% 的评测用例，1≤n≤10^3 ；

对于所有评测用例，1≤n≤10^5 ,−10^6≤ai≤10^6 ,1≤m≤2×10^6 。*/
#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int sum[N * 2];
int get_sum(int l, int r)
{
    return sum[r + N] - sum[l - 1 + N];
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        sum[a + N]++;
    }
    for (int i = 1; i < N * 2; i++)
    {
        sum[i] += sum[i - 1];
    }
    int ans = max(get_sum(0, m), get_sum(-m, 0));

    for (int i = 1; i <= m; i++)
    {
        int r = i;
        int l = i - (m - i);
        l = min(0, l);
        ans = max(ans, get_sum(l, r));
    }
    for (int i = -1; i >= -m; --i)
    {
        int l = i;
        int r = i + (m + i);
        r = max(0, r);
        ans = max(ans, get_sum(l, r));
    }
    cout << ans << '\n';
    return 0;
}