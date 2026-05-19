/*
问题描述
有一根长度为 len 的横向的管道，该管道按照单位长度分为 len 段，每一段的中央有一个可开关的阀门和一个检测水流的传感器。

一开始管道是空的，位于 Li 的阀门会在 Si 时刻打开，并不断让水流入管道。

对于位于 Li 的阀门，它流入的水在 Ti (Ti≥Si​) 时刻会使得从第 Li−(Ti−Si) 段到第 Li+(Ti−Si) 段的传感器检测到水流。

求管道中每一段中间的传感器都检测到有水流的最早时间。

输入格式
输入的第一行包含两个整数 n,len，用一个空格分隔，分别表示会打开的阀门数和管道长度。

接下来 n 行每行包含两个整数 Li,Si ，用一个空格分隔，表示位于第 Li 段管道中央的阀门会在 Si 时刻打开。

输出格式
输出一行包含一个整数表示答案。

样例输入
3 10
1 1
6 5
10 2

样例输出
5

评测用例规模与约定
对于 30% 的评测用例，n≤200，Si,len≤3000；

对于70% 的评测用例，n≤5000，Si ,len≤10^5；

对于所有评测用例，1≤n≤10^5​，1≤Si,len≤10^9​，1≤Li≤len​​，Li−1<Li。*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

ll n, len;
ll L[100010] = { 0 };
ll S[100010] = { 0 };

bool solve(ll mid)
{
    vector<pair<ll, ll>> arr;
    for (int i = 1; i <= n; i++)
    {
        if (S[i] <= mid)
        {
            ll left = max(ll(1), L[i] - (mid - S[i]));
            ll right = min(ll(len), L[i] + (mid - S[i]));
            arr.push_back({ left,right });
        }
    }

    sort(arr.begin(), arr.end());

    ll lp = arr[0].first, rp = arr[0].second;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i].first <= rp + 1)
        {
            rp = max(rp, arr[i].second);
        }
        else
        {
            return false;
        }
    }

    return rp >= len;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> len;
    for (int i = 1; i <= n; i++)
    {
        cin >> L[i] >> S[i];
    }

    ll l = -1, r = 2e9;
    while (l + 1 < r)
    {
        ll mid = l + (r - l) / 2;
        if (solve(mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    cout << r << '\n';
    return 0;
}