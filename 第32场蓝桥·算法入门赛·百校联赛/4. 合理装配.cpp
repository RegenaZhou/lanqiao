/*
问题描述
列车穿过雪地，行李箱被打开的一瞬间，小蓝发现袋子搞混了——他带来了 A 件“雪地用品”和 B 件“温泉用品”，却收到 A 个印着“温泉图案”的袋子，以及 B 个印着“雪山图案”的袋子。

若“雪地用品”装进“雪山袋”，或“温泉用品”装进“温泉袋”，称为合理装配；反之称为幽默装配。

现在小蓝要重新装袋，使“合理装配”与“幽默装配”的差的绝对值尽可能小。

请帮小蓝计算这个最小可能值。

输入格式
输入一行，包含两个整数 A,B（1≤A,B≤10^5），分别表示雪地用品（温泉袋）数与温泉用品（雪山袋）数。

输出格式
输出一个整数，表示“合理装配”和“幽默装配”的差的最小可能值。

样例输入
1 2

样例输出
1*/
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b, n, m;
    cin >> a >> b;
    if (b > a)
    {
        swap(a, b);
    }
    n = abs(3 * b - a) / 4;
    m = n + 1;
    int ans = abs(a - 3 * b);
    ans = min(ans, abs(3 * b - a - 4 * n));
    ans = min(ans, abs(3 * b - a - 4 * m));
    cout << ans << '\n';
    return 0;
}