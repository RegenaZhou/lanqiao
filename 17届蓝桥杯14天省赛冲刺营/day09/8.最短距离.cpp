/*
问题描述
在一条一维的直线上，存在 n 台显示器和 n 个电源插座。

老师给小蓝布置了一个任务：将每台显示器通过电源线与一个插座相连接（每个插座最多只能给一台显示器供电）。

同时，老师希望所消耗的电源线长度尽可能少。

请计算电源线的最小消耗长度（只需考虑直线距离）。

图片描述

输入格式
输入的第一行包含一个正整数 n.

接下来 n 行，每行包含一个整数 xi , 依次表示每台显示器的坐标。

接下来 n 行，每行包含一个整数 yi , 依次表示每个插座的坐标。

输出格式
输出一行包含一个整数，表示电源线的最小消耗长度。

样例输入
2
0
1
2
3

样例输出
4

评测用例规模与约定
对于 20% 的评测用例，1≤n≤10, 0≤xi,yi≤100;

对于 40% 的评测用例，1≤n≤100, 0≤xi,yi≤10^3;

对于 60% 的评测用例，1≤n≤1000, 0≤xi,yi≤10^5;

对于
80
%
80% 的评测用例，
1
≤
n
≤
10000
1≤n≤10000,
0
≤
x
i
,
y
i
≤
1
0
9
0≤x
i
​
 ,y
i
​
 ≤10
9
 ;

对于所有评测用例，
1
≤
n
≤
50000
1≤n≤50000,
0
≤
x
i
,
y
i
≤
1
0
9
0≤x
i
​
 ,y
i
​
 ≤10
9
 。*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> y[i];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += abs(x[i] - y[i]);
    }
    cout << ans << '\n';
    return 0;
}