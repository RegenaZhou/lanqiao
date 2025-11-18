/*
问题描述
双十一到来，蓝桥商场为了提升人流量推出了烤肠免费试吃活动。每根烤肠的烤制时间均为 d 分钟（切换烤肠时不需要花费额外时间）。

根据人流量预估，预计会有 n 名顾客参与试吃活动，其中第 i 位顾客将在活动开启后的第 ai 分钟到达。只有当顾客到达后，才能开始为其烤制烤肠。

已知烤架最多能同时烤制 k 根烤肠。请问从活动开始后，让所有顾客都拿到烤肠的最短时间是多少？

输入格式
第一行包含三个整数 n，k 和 d（1≤k≤n≤10^5，1≤d≤10^9），分别表示顾客数量、每根烤肠的烤制时间和烤架的最大同时烤制容量。

第二行包含 n 个整数 a1,a2,…,an（1≤ai≤10^9），表示每位顾客的到达时间。

输出格式
输出一行一个整数，表示从活动开始后让所有顾客拿到烤肠的最短时间。

样例输入
4 2 3
1 2 3 5

样例输出
8

说明
对于样例：n=4，k=2，d=3，到达时间 [1,2,3,5]。
活动开始时间为0。
顾客 1 在 1 到达，可从 1 开始烤，完成于 1+3=4。
顾客 2 在 2 到达，可从 2 开始烤，完成于 5。
顾客 3 在 3 到达，可从 4（前一个烤架空闲）开始烤，完成于 7。
顾客 4 在 5 到达，可从 5 开始烤，完成于 8。
最晚完成时间为 8，即总时间 8。*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
using ll = long long;
int main()
{
    ll n, k, d;
    multiset<ll> se;
    cin >> n >> k >> d;
    vector<ll> arr(n, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for (ll i = 0; i < k; i++)
    {
        se.insert(0);
    }
    //for(auto x:se) cout<<x<<" ";
    for (int i = 0; i < n; i++)
    {
        auto it = se.begin();
        ll oldnum = *it, tj = 0;
        se.erase(it);
        tj = max(oldnum, arr[i]) + d;
        se.insert(tj);
    }
    //for(auto x:se) cout<<x<<" ";
    cout << *se.rbegin();
    return 0;
}