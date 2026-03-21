/*
题目描述
给定一个区间 [a,b]，请你求出该区间内有多少个素数。

输入描述
输入共一行，包含两个整数 a,b。

2≤a≤b≤2147483647，b−a≤1000000

输出描述
输出一个整数，表示答案。

输入输出样例
示例
输入
2 6

输出
3*/
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    ll a, b, ans = 0, n;
    cin >> a >> b;
    n = b - a + 1;
    vector<bool> arr(n, true);
    for (ll i = 2; i * i <= b; i++)
    {
        ll j = max(i * 2, (a + i - 1) / i * i);
        for (; j <= b; j += i)
        {
            arr[j - a] = false;
        }
    }
    for (ll i = 0; i < n; i++)
    {
        if (arr[i])
        {
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}