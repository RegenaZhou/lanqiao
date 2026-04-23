/*
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

对于 100% 的数据, 1≤N≤10^17 ;0≤A,B≤100*/
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

char c[20];
ll ans = 0;
//n:1号操作剩余次数 m:2号操作剩余次数
int n, m;
void dfs(int i, ll v)
{
    int x = c[i] - '0';
    if (c[i]) {
        //应该使用的操作次数
        int t = min(n, 9 - x);
        n -= t;
        dfs(i + 1, v * 10 + x + t);
        //回溯
        n += t;
        //考虑操作2是否能够使用
        if (m > x) {
            m -= x + 1;
            dfs(i + 1, v * 10 + 9);
            //回溯
            m += x + 1;
        }
    }
    else {
        //答案取max
        ans = max(ans, v);
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> c >> n >> m;
    dfs(0, 0);//第一个参数是目前操作第几位，第二个参数是目前累加的值
    cout << ans << '\n';
    return 0;
}