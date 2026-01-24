/*
问题描述
圣诞晚会开始前最后一次清点礼物，小蓝盯着桌上两种规格的礼品袋犯了难：

一种是“标准礼包”，每袋有 A 份小礼物；
另一种是“豪华礼包”，每袋有 B 份小礼物；
已知 A 和 B 都是正整数，并且满足 A≤B。为了方便后续统一打包，小蓝决定对两种礼包做不同比例的加塞，做法是：

选择一个非负整数 X；
每个标准礼包额外放入 X 份礼物，总数变为 A+X；
每个豪华礼包额外放入 2X 份礼物，总数变为 B+2X。
小蓝希望，经过这样的调整之后，每个豪华礼包中的礼物数量可以被每个标准礼包中的礼物数量整除。

也就是说，他想知道是否存在一个非负整数 X，使得：

B+2X 是 A+X 的倍数。
作为小蓝的助手，请你回答：能否找到这样的 X，若能，则输出最小的 X。若不能，则输出 −1。

输入格式
输入一行，包含两个整数 A 和 B，含义如下：

A：每个标准礼包初始的礼物数量；
B：每个豪华礼包初始的礼物数量；
保证 1≤A≤B≤10^9。

输出格式
输出一行，包含一个整数：

若存在非负整数 X 使得 (B+2X)mod(A+X)=0，则输出满足条件的最小 X；
若不存在这样的 X，则输出 −1。
样例输入
2 7

样例输出
1*/
#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b, diff;
    cin >> a >> b;
    diff = b - 2 * a;
    if (diff == 0)
    {
        cout << "0\n";
    }
    else if (diff < 0)
    {
        cout << (a < b ? "-1" : "0") << '\n';
    }
    else
    {
        bool flag = false;
        int d1, d2;
        int bestd = -1;
        for (int i = 1; i * i <= diff; i++)
        {
            if (diff % i == 0)
            {
                d1 = i, d2 = diff / i;
                if (d1 >= a)
                {
                    cout << d1 - a << '\n';
                    break;
                }
                if (d2 >= a)
                {
                    if (!flag || d2 < bestd)
                    {
                        bestd = d2;
                        flag = true;
                    }
                }
            }
        }
        cout << (flag ? bestd - a : -1) << '\n';
    }
    return 0;
}