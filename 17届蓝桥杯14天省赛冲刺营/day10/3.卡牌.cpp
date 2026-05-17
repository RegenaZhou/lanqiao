/*
问题描述
这天, 小明在整理他的卡牌。

他一共有 n 种卡牌, 第 i 种卡牌上印有正整数数 i(i∈[1,n]), 且第 i 种卡牌 现有 ai 张。

而如果有 n 张卡牌, 其中每种卡牌各一张, 那么这 n 张卡牌可以被称为一 套牌。小明为了凑出尽可能多套牌, 拿出了 m 张空白牌, 他可以在上面写上数 i, 将其当做第 i 种牌来凑出套牌。
然而小明觉得手写的牌不太美观, 决定第 i 种牌最多手写 bi 张。

请问小明最多能凑出多少套牌?

输入格式
输入共 3 行, 第一行为两个正整数 n,m 。

第二行为 n 个正整数 a1,a2,…,an。

第三行为 n 个正整数 b1,b2,…,bn。

输出格式
一行, 一个整数表示答案。

样例输入
4 5
1 2 3 4
5 5 5 5

样例输出
3

样例说明
这 5 张空白牌中, 拿 2 张写 1 , 拿 1 张写 2 , 这样每种牌的牌数就变为了 3,3,3,4, 可以凑出 3 套牌, 剩下 2 张空白牌不能再帮助小明凑出一套。

评测用例规模与约定
对于 30% 的数据, 保证 n≤2000;

对于 100% 的数据, 保证 n≤2×10^5; ai,bi≤2n; m≤n^2。*/
#include <iostream>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
ll a[N], b[N];

bool solve(ll mid, ll n, ll m)//mid几副牌，m空白max 
{
    for (ll i = 1; i <= n; i++)
    {
        if (a[i] < mid)
        {
            ll diff = mid - a[i];
            if (diff > b[i] || diff > m) return false;
            else m -= diff;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, m;
    ll r = 0, l = -1;
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        cin >> b[i];
        r = max(r, a[i] + b[i]);
    }

    r++;
    while (l + 1 < r)
    {
        ll mid = (l + r) / 2;
        if (solve(mid, n, m))
        {
            l = mid;
        }
        else r = mid;
    }
    cout << l << '\n';
    return 0;
}
