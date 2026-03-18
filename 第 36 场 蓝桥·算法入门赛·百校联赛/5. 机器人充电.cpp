/*
问题描述
小蓝的导师提供了 n 台机器人，第 i 台机器人需要充电 ai 小时才能充满电。机器人一旦充满电，就会立刻开始工作，并连续工作 bi 小时，之后停止工作。

小蓝一次最多只能为一台机器人充电，并且每台机器人只能被充电一次。小蓝可以自行决定这些机器人的充电顺序。
请你帮助小蓝规划一种充电顺序，使得所有机器人同时处于工作状态的时间尽可能长。

如果不存在任何时刻使得所有机器人同时工作，则答案为 0。

输入格式
第一行包含一个整数 n(1≤n≤10^5)，表示机器人的数量。

第二行包含 n 个整数 a1,a2,…,an(1≤ai≤10^9)，表示每台机器人充满电所需的时间。

第三行包含 n 个整数 b1,b2,…,bn(1≤bi≤10^9)，表示每台机器人充满电后可以持续工作的时间。

输出格式
输出一个整数，表示在最优充电顺序下，所有机器人同时工作的最长时间。

如果不存在所有机器人同时工作的时刻，则输出 0。

样例输入
2
1 10
10 20

样例输出
10

样例说明
若先给第一台机器人充电，1 小时后它开始工作，但再给第二台机器人充电需要 10 小时，在这段时间里第一台机器人只能工作 10 小时，
因此会在第二台机器人充满前停止工作，无法形成重叠工作时间。

若先给第二台机器人充电，10 小时后它开始工作，并还能持续工作 20 小时；接着再花 1 小时给第一台机器人充电。
这样在第 11 小时起，两台机器人会同时工作，第 1 台还能工作到第 21 小时，第 2 台还能工作到第 30 小时，因此同时工作的时间为 10 小时。*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.first + a.second == b.first + b.second)
    {
        return a.first < b.first;
    }
    return a.first + a.second > b.first + b.second;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    ll sum = 0;
    cin >> n;
    vector<pair<ll, ll>> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        sum += arr[i].first;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].second;
    }
    sort(arr.begin(), arr.end(), cmp);

    ll end = arr[0].first + arr[0].second, pre = arr[0].first, ans = 0;
    for (int i = 1; i < n; i++)
    {
        pre += arr[i].first;
        ll num = pre + arr[i].second;
        end = min(end, num);
    }
    if (sum < end)
    {
        ans = end - sum;
    }
    cout << ans << '\n';

    return 0;
}