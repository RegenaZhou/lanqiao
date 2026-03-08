/*
问题描述
小蓝刚学习完二进制知识，所以现在他对任何数字的二进制都特别感兴趣。恰好即将迎来 2024 年，他想知道 2024 的二进制中有几个 1？

请你帮忙解决这个问题

输入格式
本题为填空题，无输入。

输出格式
输出一个整数表示答案。*/
#include <iostream>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int cnt = 0, n = 2024;
    while (n)
    {
        if (n % 2 == 1) cnt++;
        n /= 2;
    }
    cout << cnt << '\n';//7
    return 0;
}