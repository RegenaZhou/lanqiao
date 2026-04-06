/*
问题描述
给定一个长度为 N 的整数数列：A1,A2,…,AN 。你要重复以下操作 K 次：

每次选择数列中最小的整数（如果最小值不止一个，选择最靠前的），将其删除。并把与它相邻的整数加上被删除的数值。

输出 K 次操作后的序列。

输入格式
第一行包含两个整数 N 和 K。

第二行包含 N 个整数，A1,A2,…,AN 。

输出格式
输出 N−K 个整数，中间用一个空格隔开，代表 K 次操作后的序列。

样例输入
5 3
1 4 2 8 7

样例输出
17 7
样例说明
数列变化如下，中括号里的数是当次操作中被选择的数：
[1] 4 2 8 7

5 [2] 8 7

[7] 10 7

17 7

评测用例规模与约定
对于 20 的数据，1≤K<N≤10000。

对于 100 的数据，1≤K<N≤5×10^5 ，0≤Ai≤10^8 。*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<ll> num(n);
    vector<int> pre(n), next(n);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        pre[i] = i - 1, next[i] = i + 1;
        pq.push({ num[i],i });
    }

    while (k > 0)
    {
        pair<ll, int> temp = pq.top();
        pq.pop();
        ll val = temp.first, id = temp.second;
        if (num[id] != val)
        {
            pq.push({ num[id],id });
            continue;
        }
        num[id] = -1;
        int l = pre[id], r = next[id];
        if (l >= 0)
        {
            num[l] += val;
            next[l] = r;
        }
        if (r < n)
        {
            num[r] += val;
            pre[r] = l;
        }
        k--;
    }
    for (int i = 0; i < n; i++)
    {
        if (num[i] != -1)
        {
            cout << num[i] << ' ';
        }
    }
    return 0;
}