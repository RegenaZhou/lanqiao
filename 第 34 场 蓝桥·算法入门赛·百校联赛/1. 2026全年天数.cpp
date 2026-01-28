/*
问题描述
你刚打开OJ，还没写两行代码，评测机就给你弹出对话框：

评测机：先别急着交题，先给你拜个年——2026 年新年快乐！
你：…
评测机：就一问：2026 年这一年有多少天？
请你输出一个整数，表示 2026 年全年的天数。

输入格式
无。

输出格式
输出一个整数，表示 2026 年全年的天数。*/
#include <iostream>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int ans = 0;
    int mon[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    for (int i = 0; i < 12; i++)
        ans += mon[i];
    cout << ans << '\n';
    return 0;
}