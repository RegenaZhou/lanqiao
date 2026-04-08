/*
问题描述
小蓝看学弟们备战省赛实在太辛苦了，决定在训练间隙组织一场“耐力闯关”小游戏，帮大家换换脑子。

一共有 n 个挑战关卡，第 i 个关卡需要消耗 ai 点体力。不过，每个关卡都有一定的门槛：只有当你在开始这个关卡之前，已经累计消耗的体力不超过 bi 时，才能顺利完成它。

你可以自由决定挑战关卡的顺序，也可以只选择其中一部分关卡参加，并且每个关卡最多只能挑战一次。

小蓝想知道，在安排最优的情况下，最多能够完成多少个关卡。

输入格式
第一行包含一个整数 n(1≤n≤10^5)，表示关卡的数量。

接下来 n 行，每行包含两个整数 ai,bi(1≤ai≤10^5,1≤bi≤10^9)，分别表示完成第 i 个关卡需要消耗的体力，以及开始该关卡前允许的最大累计体力消耗。

输出格式
输出一个整数，表示最多能够完成的关卡数量。

样例输入
4
3 3
2 2
1 1
10 1

样例输出
3

样例说明
先完成第 3 个关卡，此时开始前累计消耗为 0，不超过限制 1，完成后累计消耗变为 1。

再完成第 2 个关卡，此时开始前累计消耗为 1，不超过限制 2，完成后累计消耗变为 3。

最后完成第 1 个关卡，此时开始前累计消耗为 3，恰好不超过限制 3，完成后累计消耗变为 6。

因此可以按第 3,2,1 个关卡的顺序完成 3 个关卡。*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct Node
{
    int a, b;
};
bool cmp(Node x, Node y)
{
    return x.a + x.b < y.a + y.b;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, a, b, cur = 0, ans = 0;
    cin >> n;

    vector<Node> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].a >> arr[i].b;
    }
    sort(arr.begin(), arr.end(), cmp);

    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        if (cur <= arr[i].b)
        {
            cur += arr[i].a;
            pq.push(arr[i].a);
        }
        else
        {
            if (!pq.empty() && arr[i].a < pq.top())//反悔贪心
            {
                cur -= pq.top();
                cur += arr[i].a;
                pq.pop();
                pq.push(arr[i].a);
            }
        }
    }

    cout << pq.size() << '\n';
    return 0;
}