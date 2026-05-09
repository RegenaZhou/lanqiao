/*
问题描述
肖恩认为一般的乘法表不够美观，因为它是三角形的所以肖恩认为不够整齐。肖恩自己制作了一张矩形乘法表，对于一张 n×m 的矩形乘法表，
肖恩会把 i×j 填充到矩形的第 i 行第 j 列的位置。现在，肖恩向你提问：在这张乘法表中，第 k 大的元素是多少？

矩形乘法表中第 k 大元素是指将矩形乘法表中所有元素从小到大排列后的第 k 个元素。

输入描述
输入三个数字 n,m,k ，每个数字的意义和问题描述中相同。

输入保证 1≤n,m≤5×10^5 ,1≤k≤n×m 。

输出描述
输出一个数字表示第 k 大的元素。

样例输入
2 4 5

样例输出
4

说明
对于样例输入，有一张 2×4 的乘法表：

1	2	3	4
2	4	6	8
将这些元素从小到大排列后的数组为 1,2,2,3,4,4,6,8 ，第 5 个数字为 4 。*/
#include <iostream>
using namespace std;
using ll = long long;
ll n, m, k;

ll rnk(ll mid)
{
    ll res = 0;
    for (int i = 1; i <= n; i++) res += min(m, mid / i);
    return res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    ll l = 0, r = 1e14;
    while (l + 1 != r)
    {
        ll mid = (l + r) / 2;
        if (rnk(mid) >= k) r = mid;
        else l = mid;
    }
    cout << r << '\n';
    return 0;
}