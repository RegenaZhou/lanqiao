/*
问题描述
为庆祝 1024 程序员节，蓝桥公司举办了一场庆功宴。小蓝作为庆功宴的策划，需要为 n 名员工安排座位。第 i 名员工有一个权重值 ai。

小蓝可以先将所有员工按 任意顺序 排成一队，再将队伍划分为若干个连续的分组，每组员工安排在同一桌。分桌方案需要满足以下条件：

每桌至少有 2 名员工。
每桌员工按照队伍中的先后顺序，权重值非递减，即后一名员工的权重值不小于前一名员工。
对于一种已经确定的排队顺序，小蓝必须在满足上述两个条件的前提下，让使用的桌数尽可能少。如果某种排队顺序无法合法分桌，则不能采用这种顺序。

每桌的权重值定义为该桌员工权重值的最大值，整场庆功宴的总权重值为所有桌的权重值之和。

请你帮助小蓝安排员工的排队顺序，使按照上述规则分桌后，整场庆功宴的总权重值最大。你只需要输出这个最大值。

输入格式
第一行包含一个整数 n（2≤n≤10^5），表示员工人数。

第二行包含 n 个整数 a1,a2,…,an（1≤ai≤10^5），表示每名员工的权重值。

输出格式
输出一行，包含一个整数，表示整场庆功宴的最大总权重值。

样例输入
5
1 2 2 3 4

样例输出
7

样例说明
小蓝可以将员工按照权重值排列为：[1,2,3][2,4]
分为两桌：
第一桌的员工权重值依次为 1,2,3，该桌的权重值为 3。
第二桌的员工权重值依次为 2,4，该桌的权重值为 4。
整场庆功宴的 总权重值为 3+4=7。*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
ll n;
vector<ll>arr(1e5 + 1);
//分x桌 前一桌最大值arr[n-x+1+i]>这一桌最小值arr[i]
bool check(ll x)
{

    for (int i = 0; i < x - 1; i++)
    {
        if (arr[i] >= arr[n - x + i + 1])
            return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.begin() + n);

    ll l = 1, r = n / 2;
    while (l < r)
    {
        int mid = l + (r - l + 1) / 2;
        if (check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    sort(arr.begin(), arr.begin() + n, greater<ll>());

    ll ans = 0;
    for (int i = 0; i < l; i++)
    {
        ans += arr[i];
    }
    cout << ans << '\n';

    return 0;
}