/*
问题描述
过年啦！小蓝家里热热闹闹，一大家子准备吃年夜饭。小蓝忙着在厨房张罗大餐，桌上摆好了 n 个鼓鼓囊囊的红包，第 i 个红包里放了 ai 元钱，准备等吃完饭再发给来拜年的小朋友们。

趁着小蓝在厨房忙碌的功夫，m 位小朋友悄悄溜进客厅，动起了歪心思。他们决定按顺序一个一个地 "提前领取" 压岁钱。
每个小朋友都有自己的 "胆量值" bj —— 当第 j 位小朋友看到桌上的红包时，他会从每一个当前金额 ≥bj 元的红包里偷偷抽走 1 元钱。

年夜饭做好了，小蓝端着热腾腾的菜肴回到客厅，看到小朋友们一脸无辜地坐在沙发上，突然觉得红包好像瘦了一圈 ⋯ 他好奇地数了数剩下的钱，想知道：

"这些小家伙到底每个偷了多少钱？"

请你帮小蓝算清楚每位小朋友偷走的钱数。

输入格式
第一行两个整数 n,m(1≤n,m≤10^5) —— 红包数量和小朋友数量。

第二行n 个整数 a1,a2,…,an(1≤ai≤10^5) —— 每个红包初始金额。

第三行m 个整数 b1,b2,…,bm(1≤bi≤10^5) —— 每个小朋友的胆量值。

输出格式
输出 m 行，第 i 行一个整数，表示第 i 位小朋友偷走的钱数。

样例输入
3 2
3 1 1
1 1

样例输出
3
1

样例解释
初始红包金额分别为 3 元、 1 元、 1 元。

第一位小朋友胆量 1，三个红包均 ≥1，偷走 3 元，红包变为 2 元、 0 元、 0 元。

第二位小朋友胆量 1，仅第一个红包 ≥1，偷走 1 元。*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

template <typename T> struct Fenwick
{
    int n;
    std::vector<T> a;

    Fenwick(int n = 0)
    {
        init(n);
    }

    void init(int n)
    {
        this->n = n;
        a.assign(n + 1, T());
    }

    void add(int x, T v)
    {
        for (; x <= n; x += x & (-x))
        {
            a[x] += v;
        }
    }

    T sum(int x)
    {
        auto ans = T();
        for (; x; x -= x & (-x))
        {
            ans += a[x];
        }
        return ans;
    }

    T rangeSum(int l, int r)
    {
        return sum(r) - sum(l);
    }
};

int main() {
    std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    Fenwick<int> fw(n + 1);
    auto check = [&](int x, int i)
        {
        int v = fw.sum(i);
        return a[i] - v >= x;
        };
    for (int i = 1; i <= m; ++i)
    {
        int x;
        cin >> x;
        int l = 1, r = n;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (check(x, mid))
            {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        if (check(x, r))
        {
            fw.add(r, 1);
            cout << n - r + 1 << '\n';
        }
        else
        {
            cout << 0 << '\n';
        }
    }

    return 0;
}