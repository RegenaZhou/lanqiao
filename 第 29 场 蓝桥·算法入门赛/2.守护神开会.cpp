/*
问题描述
白羊座、金牛座和双子座的守护神正在一条直线上开会。
起初，他们分别位于坐标A、B和C三个不同的位置上。
由于他们说话声音都很小，为了能彼此听得更清楚，
每次，最外侧（位置坐标最大或最小）的一位守护神要移动到另外两位守护神之间的空隙处，以便他们三靠得更近。

对此，请你算算，他们最多可以进行多少次这样的移动？注意，他们的位置需始终保持不同。

样例输入
第一行包含一个整数T（1≤T≤10^5），表示测试用例的个数。

接下来T行，每行包含三个整数A、B和C（1≤A<B<C≤10^9），表示三位守护神初始的位置坐标。

样例输出
输出T行，每行一个整数，表示他们最多可以进行多少次移动。

样例输入
3
1 2 3
1 3 5
1 4 6

样例输出
0
1
2*/
#include <iostream>
#include<algorithm>
using namespace std;
using ll = long long;
void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << max(b - a, c - b) - 1;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        if (t != 0) cout << '\n';
    }
    return 0;
}