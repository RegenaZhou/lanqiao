/*
问题描述
蓝桥学院最近收到了一批数量为 n 的年货，其中第 i 份年货的重量为 Ai 。

小蓝收到任务，需要将其搬运至学院的仓库内。小蓝每一趟最多只能同时拿两件年货（因为只有两只手），
并且每次搬运的年货总重量不能超过 k，否则无法抬起。

请计算将所有年货搬至仓库最少需要多少趟？如果无法完成任务，则输出 −1。

输入格式
第一行两个整数 n,k（1≤n≤10^5，1≤k≤10^9）。

第二行 n 个整数 A1,A2,…,An（1≤Ai≤10^9），表示每件年货的重量。

输出格式
输出一个整数，表示最少需要的趟数。如果无法完成任务，输出 −1。

样例输入 1
4 4
1 2 3 3

样例输出 1
3*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k, ans = 0;
    bool flag = true;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int l = 0, r = n - 1;
    while (l <= r)
    {
        if (a[r] > k)
        {
            flag = false;
            break;
        }
        else
        {
            if (a[l] + a[r] <= k)
            {
                ans++;
                l++, r--;
            }
            else
            {
                ans++;
                r--;
            }
        }
    }
    if (!flag) cout << "-1\n";
    else cout << ans << '\n';
    return 0;
}