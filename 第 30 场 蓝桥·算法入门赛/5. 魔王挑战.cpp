/*
问题描述
蓝桥学院组织了一场暑期出游，前往游乐园，共有 N 名学生参加，
每位学生有一个能力值，其中第 i 位学生的能力值为 vi 。
在游乐园中，学生们需要挑战一个血量为 K 的大魔王。
小蓝作为班长，负责为每位学生分配队伍，每名学生必须有且仅有一支队伍。

每支队伍将与大魔王进行一次挑战。队伍的能力值定义为队伍中学生数量乘以队伍中最小能力值的学生的能力值。
如果队伍的能力值大于或等 K ，则该队伍能击败大魔王。

小蓝希望尽可能组建更多的队伍击败大魔王，请你帮小蓝计算一下最多能分出多少支队伍击败大魔王？

输入格式
第一行包含两个正整数 N,K(1≤N≤10^5 ,1≤K≤10^9 )，分别表示学生数量和大魔王的血量。

第二行包含 N 个整数v1,v2,…,vN(1≤vi≤10^9)，表示每位学生的能力值。

输出格式
输出一个整数，表示最多能分出的击败大魔王的队伍数量。

样例输入
5 5
3 1 2 4 5

样例输出
2*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<ll> sz(n);
    for (int i = 0; i < n; i++)
    {
        cin >> sz[i];
    }
    sort(sz.begin(), sz.end());
    ll js = 0, gs = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        gs++;
        if (sz[i] * gs >= k)
        {
            gs = 0;
            js++;
        }
    }
    cout << js << '\n';
    return 0;
}