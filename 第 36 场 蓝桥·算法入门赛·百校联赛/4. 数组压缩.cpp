/*
问题描述
在蓝桥学院的一次算法考核中，小蓝拿到了一个长度为 n 的数组。现在他需要通过不超过两次操作，尽可能缩短数组的长度。

每次操作中，小蓝可以选择一个所有元素都相等的连续子数组，并将其删除。删除后，原数组中该子数组左侧和右侧的部分会自动拼接起来，且原有的相对顺序保持不变。

形式化地说，对于数组 a1,a2,…,an ，任意满足 1≤l≤r≤n 的连续区间 al,al+1,…,ar 都称为一个子数组。如果该子数组中的所有元素都相等，那么小蓝可以将它整段删除。

请你帮助小蓝计算：在最多执行两次操作后，数组的最小可能长度是多少。

输入格式
第一行包含一个整数 n(1≤n≤10^5)，表示数组的长度。

第二行包含 n 个整数 a1,a2,…,an(1≤ai≤n)，表示数组中的元素。

输出格式
输出一个整数，表示在最多执行两次删除操作后，数组的最小可能长度。

样例输入
5
2 1 1 2 1

样例输出
1

样例说明
数组初始为 [2,1,1,2,1]，第一次删除后为 [2,1,1,1]，第二次删除后为 [2]，最终长度为 1。*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<pair<int, int>> p;
    int num = a[0], cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] != num)
        {
            p.push_back({ num,cnt });
            num = a[i];
            cnt = 1;
        }
        else
        {
            cnt++;
        }
    }
    p.push_back({ num,cnt });

    int ans, max1 = 0, max2 = 0;
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i].second > max1)
        {
            max2 = max1;
            max1 = p[i].second;
        }
        else if (p[i].second > max2)
        {
            max2 = p[i].second;
        }
    }
    ans = n - max1 - max2;
    for (int i = 1; i < p.size() - 1; i++)
    {
        if (p[i - 1].first == p[i + 1].first)
        {
            ans = min(ans, n - (p[i - 1].second + p[i].second + p[i + 1].second));
        }
    }
    cout << ans << '\n';
    return 0;
}