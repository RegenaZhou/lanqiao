/*
问题描述
小蓝养了三只鸡，它们身上分别长了 x、y、z 根羽毛。小蓝想让这三只鸡身上的羽毛数量一样多，这样它们看起来才更默契。

小蓝可以进行以下两种操作：

选择任意两只鸡，给它们各贴上一根羽毛。
选择任意一只鸡，给它贴上两根羽毛。
请你计算，小蓝最少需要进行多少次操作，才能让三只鸡身上的羽毛数量相同。题目保证解必然存在。

输入格式
输入一行，包含三个整数 x、y 和 z(1≤x,y,z≤10^5)，分别表示三只鸡身上的羽毛数量。

输出格式
输出一个整数，表示达到三只鸡羽毛数量相等所需的最少操作次数。

样例输入
3 2 1

样例输出
3*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int ans = 0;
    vector<int> a(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < 3; i++)
    {
        a[i] = abs(a[i] - a[2]);
    }
    if ((a[0] % 2 == 0 && a[1] % 2 == 0) || (a[0] % 2 == 1 && a[1] % 2 == 1)) ans = (a[0] + a[1]) / 2;
    else
    {
        ans = (a[0] + a[1]) / 2 + 2;
    }
    cout << ans << '\n';
    return 0;
}