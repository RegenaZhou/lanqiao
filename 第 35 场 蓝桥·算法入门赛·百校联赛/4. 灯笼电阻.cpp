/*
问题描述
除夕夜，小蓝正急得满头大汗——家里挂在门口迎新的电子灯笼突然坏了。

为了赶在零点前修好它，小蓝拆开了电路板。他发现问题出在一个关键的电阻元件上，这个元件的阻值是 X，它需要搭配一个新的电阻 Y 才能工作。

电路板的控制芯片有一条死规定：两个电阻搭配后，系统计算出的总阻值 X+Y/X×Y 必须是一个正整数，否则灯笼就会烧坏。

小蓝手里的备用零件很多，但他想用最小的代价修好它。请你帮他算算，他能选用的最小正整数 Y 是多少？

输入格式
第一行包含一个整数 T（1≤T≤10^3），表示测试数据的组数。

接下来 T 行，每行包含一个正整数 X（2≤X≤10^9），代表元件的阻值。

输出格式
对于每组数据，输出一个整数，表示满足条件的最小正整数 Y。

样例输入
2
2
3

样例输出
2
6*/
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
ll ans, target;
vector<pair<int, int>> v;
void dfs(int idx, ll val)
{
    if (val > ans)return;
    if (idx == v.size())
    {
        if (val > target)
        {
            ans = min(ans, val);
        }
        return;
    }
    ll p = v[idx].first;
    int c = v[idx].second;
    ll mul = 1;
    for (int i = 0; i <= c; i++)
    {
        dfs(idx + 1, val * mul);
        if (i < c)
        {
            mul *= p;
        }
    }
}
void solve()
{
    ll x;
    cin >> x;
    target = x;
    v.clear();
    ll tmp = x;
    for (ll i = 2; i * i <= tmp; i++)
    {
        if (tmp % i == 0)
        {
            int cnt = 0;
            while (tmp % i == 0)
            {
                tmp /= i;
                cnt++;
            }
            v.push_back({ i,cnt * 2 });
        }
    }
    if (tmp > 1)
    {
        v.push_back({ tmp,2 });
    }
    ans = x * x;
    dfs(0, 1);
    cout << ans - x << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}