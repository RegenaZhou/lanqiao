/*
问题描述
蓝桥学院正在进行算法集训。

竞赛老师准备了 n 堆积木，第 i 堆积木当前有 hi 块。

现在，小蓝想把这 n 堆积木的高度全部调整为相等。对于第 i 堆积木：

每增加 1 块积木，需要花费 ci 的代价；
每移除 1 块积木，也需要花费 ci 的代价。
也就是说，第 i 堆积木每改动 1 块，都会产生 ci 的费用。

请你计算，将所有积木堆调整为相同高度所需要的最小总代价。

输入格式
第一行输入一个整数 n(1≤n≤10^5)，表示积木堆的数量。

第二行输入 n 个整数 h1,h2,…,hn(0≤hi≤10^4)，表示每堆积木当前的高度。

第三行输入 n 个整数 c1,c2,…,cn(0≤ci≤10^4)，表示第 i 堆积木每增加或移除一块的代价。

输出格式
输出一个整数，表示将所有积木堆调整为相同高度的最小总代价。

样例输入
4
1 3 2 6
2 3 1 4

样例输出
17

样例说明
一种最优方案是将所有积木堆统一到高度 3。

此时代价为：

第 1 堆：从 1 增加到 3，需要增加 2 块，代价为 2×2=4；
第 2 堆：已经是 3，代价为 0；
第 3 堆：从 2 增加到 3，需要增加 1 块，代价为 1×1=1；
第 4 堆：从 6 减少到 3，需要移除 3 块，代价为 3×4=12。
总代价为：4+0+1+12=17
因此答案为 17。*/
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int n;
vector<int> h, c;
ll f(int x)
{
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += abs(h[i] - x) * c[i];
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int l = 1e4, r = 0;
    cin >> n;
    h.resize(n), c.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
        l = min(l, h[i]), r = max(r, h[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    while (l < r)
    {
        int x = l + (r - l) / 3, y = r - (r - l) / 3;//三分 f(x)凹函数 找极小值点
        if (f(x) <= f(y))
        {
            r = y - 1;
        }
        else
        {
            l = x + 1;
        }
    }

    cout << f(l) << '\n';
    return 0;
}