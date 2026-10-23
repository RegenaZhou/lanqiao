/*
问题描述
暑假集训期间，教练要安排连续若干天的训练。

每天都会给当天的训练题目设置一个难度分数，且这个分数必须是 1 到 N 之间的整数。

为了让训练安排更合理，教练提出了一个特殊要求：

任意选出三天，这三天的难度分数都不能组成一个合法三角形。

教练希望在满足这个条件的前提下，尽可能多地安排训练天数。

请你输出最多可以安排多少天。

输入格式
输入一个整数 N(1≤N≤10^18)，表示每天难度分数的上界。

输出格式
输出一个整数，表示最多可以安排的训练天数。

样例输入
12

样例输出
6

样例说明
一种可能的满足条件的安排方式是：[1,12,4,1,2,6]，即最多可以安排 6 天。*/
#include <iostream>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, pre1, pre2, cur, ans;
    cin >> n;
    if (n == 1) ans = 2;
    else if (n == 2) ans = 3;
    else
    {
        pre1 = 1, pre2 = 1, ans = 2;
        cur = pre1 + pre2;
        while (cur < n)
        {
            ans++;
            pre1 = pre2, pre2 = cur;
            cur = pre1 + pre2;
        }
    }
    cout << ans << '\n';
    return 0;
}