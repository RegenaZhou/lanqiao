/*
问题描述
输入一个数组 a，包含有 n 个元素 a1,a2,⋯,an 。对这个数组进行 m 次变换，每次变换会将数组 a 中的每个元素 ai 转换为 ai⋅bitCount(ai)。
其中 bitCount(x) 表示数字 x 的二进制表示中 1 出现的次数，例如 bitCount(3)=2，因为 3 的二进制表示为 11，其中 1 出现了两次。

请输出变换之后的数组内容。

输入格式
输入的第一行包含一个正整数 n，表示数组 a 中的元素个数。

第二行包含 n 个整数 a1,a2,⋯,an ，相邻整数之间使用一个空格分隔。

第三行包含一个整数 m，表示变换次数。

输出格式
输出一行，包含 n 个整数，相邻整数之间使用一个空格分隔，表示变换之后得到的数组 a。

样例输入
2
5 7
2

样例输出
20 63

样例说明
5=(101)2，7=(111)2，第一次变化后 a=[10,21]。

10=(1010)2，21=(10101)2，第二次变换后 a=[20,63]。

评测用例规模与约定
对于 30% 的评测用例，1≤n≤10；

对于 60% 的评测用例，1≤n≤100；

对于所有评测用例，1≤n≤10^3，0≤m≤5，0≤ai≤1000。*/
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int m;
int solve(int n)
{
    for (int i = 1; i <= m; i++)
    {
        ll cpn = n, cnt = 0;
        while (n)
        {
            cnt += n % 2;
            n /= 2;
        }
        n = cpn * cnt;
    }
    return n;
}
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
    cin >> m;
    for (int i = 0; i < n; i++)
    {
        a[i] = solve(a[i]);
        if (i != 0) cout << " ";
        cout << a[i];
    }
    return 0;
}
