/*
问题描述
时间飞逝，转眼间来到了5025年，蓝桥杯大赛已经成为全球瞩目的盛事，吸引了来自世界各地的顶尖选手。每个国家和地区都派出了自己的精英队伍，准备在这场科技盛宴中大显身手。

本次大赛共有 N 位参赛者，第 i 位参赛者的编号位 i，来自编号为 Ai 的国家。比赛机房的电脑从左到右依次编号为 1 到 N，每位参赛者将在与自己编号相同的电脑上进行比赛。
为了确保比赛的公平性，蓝桥杯官方决定对部分参赛者的电脑进行抽样监控。然而，监控方式必须满足以下条件：

监控的电脑数量不能为零。
同一个国家或地区的参赛者最多只能有两台电脑被监控，不能过多集中监控某个国家的选手。
如果同一个国家或地区的两台电脑被监控，它们之间的距离不能超过 D。这里的距离定义为两台电脑编号之差的绝对值。
由于可能的监控方式实在太多，官方一时难以计算，于是他们向你求助，希望你能帮忙计算出所有合法的监控方式数量。

由于结果可能非常庞大，请将答案对 10^9+7 取模后输出。

输入格式
第一行输入两个整数 N,D(1≤D<N≤10^5) 表示参赛者数量以及选取的距离要求。

第二行输入 N 个整数 A1,A2,A3,⋯,AN(1≤Ai≤10^9) 表示每位参赛者的国家编号。

输出格式
输出一个整数表示答案，由于答案可能很大，你需要对 10^9+7 取模后输出。

样例输入
5 2
1 2 1 2 2 

样例输出
23

说明
对于样例，可能的监控方案有 [1,2,3,4],[1,2,4]，但 [1,2,3,5] 不合法，因为 2 号参赛者与 5 号参赛者来自同一国家且两人电脑距离为 3，不符合要求。*/
#include <iostream>
#include <map>
#include <vector>
using namespace std;
using ll = long long;
const int mood = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, d;
    ll ans = 1;
    cin >> n >> d;
    vector<int> sz(n + 1);
    map<int, vector<int>> mp1;
    map<int, ll> mp2;
    for (int i = 1; i <= n; i++)
    {
        cin >> sz[i];
        mp1[sz[i]].push_back(i);
        mp2[sz[i]] += 1;//¼à¿Ø1ÈË
    }
    for (const auto& pair : mp1)
    {
        ll key = pair.first;
        mp2[key]++;//¼à¿Ø0ÈË
        const vector<int>& values = pair.second;
        for (int i = 0; i < values.size(); i++)
        {
            mp2[key] += upper_bound(values.begin(), values.end(), values[i] + d) - values.begin() - i - 1;
        }
    }
    for (const auto& pair : mp2)
    {
        ans = ans * pair.second % mood;
    }
    ans--;//²»ÄÜ²»Ñ¡
    cout << ans << '\n';
    return 0;
}
