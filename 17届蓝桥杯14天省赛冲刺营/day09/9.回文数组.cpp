/*
问题描述
小蓝在无聊时随机生成了一个长度为 n 的整数数组，数组中的第 i 个数为 ai ，他觉得随机生成的数组不太美观，想把它变成回文数组，也是就对于任意 i∈[1,n] 满足 ai=an−i+1 。
小蓝一次操作可以指定相邻的两个数，将它们一起加 1 或减 1；也可以只指定一个数加 1 或减 1，请问他最少需要操作多少次能把这个数组变成回文数组？

输入格式
输入的第一行包含一个正整数 n 。

第二行包含 n 个整数 a1,a2,⋯,an ，相邻整数之间使用一个空格分隔。

输出格式
输出一行包含一个整数表示答案。

样例输入
4
1 2 3 4

样例输出
3

样例说明
第一次操作将 a1,a2 加 1，变为 2,3,3,4 ;

后面两次操作将 a1 加 1，变为 4,3,3,4 。

评测用例规模与约定
对于 20% 的评测用例, 1≤n≤10；

对于所有评测用例, 1≤n≤10^5,−10^6≤ai≤10^6 。*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;

    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    ll ans = 0, en = n / 2;
    for (int i = 1; i <= en; i++)
    {
        ll num = arr[i] - arr[n - i + 1];
        ans += abs(num);
        arr[i] = num;
    }

    for (int i = 2; i <= en; i++)
    {
        if (arr[i - 1] >= 0 && arr[i] >= 0)
        {
            ll mi = min(arr[i - 1], arr[i]);
            ans -= mi;
            arr[i] -= mi;
        }
        else if (arr[i - 1] <= 0 && arr[i] <= 0)
        {
            ll ma = abs(max(arr[i - 1], arr[i]));
            ans -= ma;
            arr[i] += ma;
        }
    }

    cout << ans << '\n';

    return 0;
}