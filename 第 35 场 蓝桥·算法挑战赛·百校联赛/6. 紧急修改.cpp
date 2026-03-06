/*
问题描述
老师刚刚离开办公室去开会，小蓝知道，这是他唯一的机会。

为了应付学校的突击检查，同学们先向老师上报了一份“理想版”的作业提交名单，老师把它记成长度为 N 的序列 A，由 0 和 1 构成（0 表示未交，1 表示已交）。
然而，这份名单“美化”了事实——班级的真实提交情况，其实是另一份长度为 N 的序列 B 所描述的样子（B 同样由 0 和 1 构成）。

老师随时可能回来，并将两个名单进行核对。一旦对不上，全班同学都将面临严厉的批评。

对此，小蓝决定潜入办公室将 A 改成 B，但他担心改动太明显，因此只敢做一种“看起来像笔误”的安全修改：

选择一个位置 i（2≤i≤N−1），如果当前 Ai−1=Ai+1​ ，就可以把 Ai 的值修改为 1−Ai 。
每次操作后， A 会立刻更新，下一步操作基于更新后的 A。
小蓝可以进行任意多次操作。请你判断是否能把 A 变成 B；若能，求最少操作次数，否则输出 −1。

输入格式
第一行包含一个整数 N (3≤N≤10^5)，表示序列的长度。

第二行包含 N 个以空格分隔的整数，代表序列 A。每个整数均为 0 或 1。

第三行包含 N 个以空格分隔的整数，代表序列 B。每个整数均为 0 或 1。

输出格式
输出一个整数。如果能够将序列 A 变为序列 B，则输出所需的最少操作次数；否则，输出 −1。

样例输入
3
0 1 0
0 0 0

样例输出
1*/
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    if (a[0] != b[0] || a[n - 1] != b[n - 1])
    {
        cout << -1;
        return;
    }
    vector<int> v1, v2;
    for (int i = 0; i < n - 1; i++)
    {
        if ((a[i] != a[i + 1]) ^ (i & 1)) v1.push_back(i);
        if ((b[i] != b[i + 1]) ^ (i & 1)) v2.push_back(i);
    }
    if (v1.size() != v2.size())
    {
        cout << -1;
        return;
    }
    ll ans = 0;
    for (int i = 0; i < (int)v1.size(); i++)
    {
        ans += abs(v1[i] - v2[i]);
    }
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}