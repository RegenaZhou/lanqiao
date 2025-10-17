/*
问题描述
给定一个 N×N 的矩阵，请找出主对角线和副对角线上所有数字中的最大值和最小值。

主对角线：从左上角延伸到右下角。
副对角线：从右上角延伸到左下角。
现在，请你找出这个最大值和最小值。

输入格式
输入的第一行包含一个整数 N (2≤N≤100)，表示矩阵的大小。

接下来 N 行，每行包含 N 个整数，每个整数的取值范围在 [1,10^4] 之间，表示矩阵中的元素。

输出格式
输出一行，包含两个整数，分别是主对角线和副对角线上所有元素中的最大值和最小值，两个整数之间用一个空格分隔。

样例输入
3
2 2 2
1 3 3
2 5 5

样例输出
5 2

运行限制*/
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, x = 1e4, d = 0, num;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> num;
            if (i == j || j + i == n + 1)
            {
                x = min(x, num), d = max(d, num);
            }
        }
    }
    cout << d << " " << x << '\n';
    return 0;
}