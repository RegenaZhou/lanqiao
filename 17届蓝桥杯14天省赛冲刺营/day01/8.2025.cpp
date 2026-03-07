/*
问题描述
求 1∼20250412 中，有多少个数可以通过改变其数字顺序后含有 2025。

例如，5220、21520 可以，而 205、225、2200、222555111 则不行。

提示：要求的数就是含有至少 1 个 0、2 个 2、1 个 5 的数。

输入格式
无输入。

输出格式
输出一个整数，表示满足条件的数的数量。

样例输入
无

样例输出
无

答案提交
这是一道结果填空题，只需提交一个整数。填写多余内容将无法得分。*/
#include <iostream>
using namespace std;
using ll = long long;
bool solve(int n)
{
    int num[10] = { 0 };
    while (n)
    {
        num[n % 10]++;
        n /= 10;
    }
    if (num[0] >= 1 && num[2] >= 2 && num[5] >= 1) return true;
    else return false;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int ans = 0;
    for (int i = 2025; i <= 20250412; i++)
    {
        ans += solve(i);
    }
    cout << ans << '\n';//506754
    return 0;
}