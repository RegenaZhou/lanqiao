/*
最大数字

问题描述
给定一个正整数 N 。你可以对 N 的任意一位数字执行任意次以下 2 种操 作：

将该位数字加 1 。如果该位数字已经是 9 , 加 1 之后变成 0 。

将该位数字减 1 。如果该位数字已经是 0 , 减 1 之后变成 9 。

你现在总共可以执行 1 号操作不超过 A 次, 2 号操作不超过 B 次。 请问你最大可以将 N 变成多少?

输入格式
第一行包含 3 个整数: N,A,B 。

输出格式
一个整数代表答案。

样例输入
123 1 2

样例输出
933

样例说明
对百位数字执行 2 次 2 号操作, 对十位数字执行 1 次 1 号操作。

评测用例规模与约定
对于 30% 的数据, 1≤N≤100;0≤A,B≤10。

对于 100% 的数据, 1≤N≤10^17;0≤A,B≤100*/
#include <iostream>
using namespace std;
using ll = long long;
string n;
int a, b;
ll ans = 0;
void dfs(int id, ll value)
{
    if (id == n.length())
    {
        ans = max(ans, value);
        return;
    }
    int num = n[id] - '0';
    int jia = min(9 - num, a), jian = min(num + 1, b);
    if (jia <= a)
    {
        a -= jia;
        dfs(id + 1, value * 10 + num + jia);
        a += jia;
    }

    if (jian <= b)
    {
        b -= jian;
        dfs(id + 1, value * 10 + (num - jian + 10) % 10);
        b += jian;
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> a >> b;
    dfs(0, 0);
    cout << ans << '\n';
    return 0;
}