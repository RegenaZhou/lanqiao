/*
问题描述
你是一名自动化生产线数据监控员。此刻，一条生产线上刚刚产出了N 个标准组件。每个组件i 上都标有一个唯一的正整数 Ai ，代表其加工等级。

你的核心任务是计算一个总和，这个总和由所有满足以下条件的组件的加工等级 Ai 组成：

对于任何一个组件 i，它的加工等级 Ai 能够被计入总和，当且仅当在整个生产线上的 N 个组件的加工等级集合 {A1,A2,…,AN} 中，
不存在任何一个组件的加工等级恰好是 Ai−1 。
现在，请你编写程序，准确计算出这条自动化流水线上，这批组件的总加工等级和。

输入格式
第一行包含一个整数 N (1≤N≤10^4)，表示组件的总数量。

第二行包含 N 个整数 A1,A2,…,AN (1≤Ai≤10^5)，由空格隔开，代表每个组件的加工等级。

输出格式
输出一个整数，表示满足条件的组件的加工等级之和。

样例输入
5
1 2 3 5 5

样例输出
11*/
#include <iostream>
#include <map>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, num, sum = 0, pre = -1;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        mp[num]++;
    }
    for (const auto& item : mp)
    {
        if (item.first - 1 != pre)
        {
            sum += item.first * item.second;
        }
        pre = item.first;
    }
    cout << sum << '\n';
    return 0;
}