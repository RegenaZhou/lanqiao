/*
问题描述
小蓝手里有 N 张号码牌，第 i 张牌上的数字是 Ai 。这些数字两两不同，且都在 1 到 10^9 之间。

他想把这 N 张号码牌上的数字整理成 1,2,…,N，并且每个数字恰好出现一次。

不过，他不能随意改号。每次操作时，他只能按下面的规则改一张号码牌：

选择一张当前数字为 x 的号码牌；
在所有小于 x、且当前没有出现在任何号码牌上的正整数中，找到最大的一个数；
将这张号码牌上的数字改成这个数。
如果不存在这样的数，那么这张号码牌当前不能被操作。

每改一次记为 1 次操作。

现在，请你帮小蓝计算，把所有号码牌上的数字整理成 1,2,…,N 所需的最少操作次数。

输入格式
第一行包含一个整数 N（1≤N≤2×10^5），表示号码牌的数量。

第二行包含 N 个整数 A1,A2,…,AN（1≤Ai≤10^9，A1,A2,…,AN 互不相同），表示每张号码牌上的初始数字。

输出格式
输出一个整数，表示所需的最少操作次数。

样例输入 1
3
1 2 3

样例输出 1
0

样例输入 2
3
1 2 5

样例输出 2
2*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, ans = 0;
    cin >> n;
    vector<int> arr(n + 1);
    arr[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for (int i = 1; i <= n; i++)
    {
        ans = ans + arr[i] - arr[i - 1] - 1;
    }
    cout << ans << '\n';
    return 0;
}

//以下为理解本质后更优的解法
#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, num, maxn = 0, ans;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        maxn = max(maxn, num);
    }
    ans = maxn - n;
    cout << ans << '\n';
    return 0;
}
