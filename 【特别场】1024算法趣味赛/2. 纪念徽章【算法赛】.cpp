/*
问题描述
1024 到了，小蓝负责发放公司程序员节活动的纪念徽章。徽章统一存放在一个储物柜中，柜中最初有 S 枚徽章，最多可以存放 M 枚。

活动期间，工作人员会从柜中取出徽章发放，也会向柜中放入徽章补充库存。小蓝按时间顺序记下了 N 条存取记录，第 i 条记录用整数 Di 表示：正数表示放入，负数表示取出。
例如，3 表示放入 3 枚，−2 表示取出2 枚。

整理记录时，小蓝怀疑自己多记了一条，因此想删去其中一条记录。删去后，他会从最初的 S 枚徽章开始，按剩余记录的顺序，依次加上放入的数量、减去取出的数量。
在这个过程中，柜中的徽章既不能少于 0 枚，也不能多于 M 枚。

现在，请你计算，有多少条记录在单独删去后，能够满足上述要求。

输入格式
第一行包含三个整数 N,M,S（1≤N≤2000，1≤M≤10^9，0≤S≤M），分别表示记录条数、储物柜最多能存放的徽章数量和柜中最初的徽章数量。

第二行包含 N 个整数 D1,D2,…,DN（−10^5≤Di≤10^5，Di≠0），按时间顺序表示每条存取记录。

输出格式
输出一个整数，表示可以单独删去的记录条数。如果没有符合要求的记录，输出 0。

样例输入
4 6 2
3 -4 5 -2

样例输出
1

样例说明
柜中最初有 2 枚徽章，最多存放 6 枚。分别尝试删去四条记录：

删去的记录	剩余记录	计算过程中的徽章数量	是否满足要求
第 1 条		−4,5,−2		2→−2→3→1				否，出现负数
第 2 条		3,5,−2		2→5→10→8				否，超过容量 6
第 3 条		3,−4,−2		2→5→1→−1				否，出现负数
第 4 条		3,−4,5		2→5→1→6				是
只有删去第 4 条记录后，柜中的徽章数量才始终在 0 到 6 之间，因此答案为 1。*/
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, m, s, cps, maxn, minn, ans = 0;
    cin >> n >> m >> s;
    cps = s;

    vector<ll> arr(n);
    vector<bool> hou(n, false);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cps += arr[i];
    }

    maxn = minn = cps;
    ll tmp1 = maxn, tmp2 = minn;
    for (int i = n - 1; i >= 0; i--)
    {
        tmp1 = maxn, tmp2 = minn;
        tmp1 -= arr[i], tmp2 -= arr[i];
        if (tmp1 <= m && tmp2 >= 0) hou[i] = true;
        cps -= arr[i];
        if (cps > maxn) maxn = cps;
        else if (cps < minn) minn = cps;
    }

    maxn = minn = cps = s;
    for (int i = 0; i < n; i++)
    {
        if (hou[i] && maxn <= m && minn >= 0) ans++;
        cps += arr[i];
        if (cps > maxn) maxn = cps;
        else if (cps < minn) minn = cps;
    }

    cout << ans << '\n';
    return 0;
}