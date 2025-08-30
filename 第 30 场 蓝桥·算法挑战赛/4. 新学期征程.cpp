/*
问题描述
假期苦短，代码情长。你，作为校算法集训队的一员，揉着惺忪的睡眼，万般不情愿地踏入了训练室，准备迎接新学期的挑战。然而，教练早已等候多时，脸上挂着一丝令人不安的微笑。

“同学们，让我们从一个问题开启本学期的征程。”

给定一个正整数 n。请问，在 x,y 坐标均为 1 以上 n 以下范围内的中，不重复地选取 5 个点，满足以下条件的方法共有多少种？

在所选的 5 个格点中，任意选取两个不同点，使得这两个点的中点仍为格点的情况，恰好只有 1 种。
注：格点指的是 x,y 坐标均为整数的点。

现在，请你解决该问题。由于答案可能很大，请输出结果对 998244353 取模后的值。

输入格式
第一行包含一个整数 t（1≤t≤10^3），表示测试数据的组数。

接下来 t 行，每行包含一个正整数 n（3≤n≤10^5）。

输出格式
共 t 行，每行一个整数，表示满足条件的选法总数。由于答案可能很大，请输出结果对 998244353 取模后的值。*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mood = 998244353;
void solve()
{
    int n;
    cin >> n;
    ll j = (n + 1) / 2, o = n / 2;
    vector<ll> sz = { j * j,j * o,o * j,o * o };
    ll ans = 0;
    for (int i = 0; i < 4; i++)
    {
        ll c = sz[i] * (sz[i] - 1) / 2; //sz[i]个里面选两个，C 2 n=n*(n-1)/2
        c %= mood;
        for (int j = 0; j < 4; j++)
        {
            if (j == i) continue;
            c *= sz[j];
            c %= mood;
        }
        ans += c;
        ans %= mood;
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;

}
