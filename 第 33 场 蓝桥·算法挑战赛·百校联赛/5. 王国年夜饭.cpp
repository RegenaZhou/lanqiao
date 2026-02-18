/*
问题描述
蓝桥王国即将迎来新年，国王为感谢国民过去一年的贡献，决定邀请部分国民到王宫共进跨年年夜饭。

王国共有 k 户家庭，每户家庭恰好由一对夫妻组成，因此全国共有 2k 位国民。

由于王宫宴会厅容量限制，国王决定恰好邀请 n 位国民参加年夜饭。

国王认为：只要两种邀请方案中，至少存在一户家庭被邀请的人数不同，即视为不同的方案。

他想知道总共有多少种不同的邀请方案，由于答案可能很大，你需要对 10^9+7 进行取模。

输入格式
输入仅一行，包含两个整数 k,n(1≤k≤5×10^5 ,1≤n≤2⋅k) 表示王国家庭数量和国王打算邀请的人数。

输出格式
输出一个整数表示方案数，由于答案可能很大，你需要对10^9+7 取模。

样例输入
3 2

样例输出
6

说明
对于样例，假设三户家庭分别为 (A1,B1),(A2,B2),(A3,B3)，其中 A 表示男人， B 表示女人，国王有以下不同邀请方案：

(A1,A2),(A1,A3),(A2,B3),(A1,B1),(A2,B2),(A3,B3)。

请注意，对于 (B2,A3) 来说，其与 (A2,B3) 被国王视为同一种方案，因为两种方案每家每户被邀请的人数一致。*/
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int MOD = 1000000007;

ll mod_pow(ll a, ll b, int mod)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

vector<ll> fact, inv_fact;
void precompute_factorials(int n)
{
    fact.resize(n + 1);
    inv_fact.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv_fact[n] = mod_pow(fact[n], MOD - 2, MOD);
    for (int i = n - 1; i >= 0; i--)
    {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }
}

ll comb(int n, int r)
{
    if (r < 0 || r > n)
        return 0;
    return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int k, n;
    cin >> k >> n;

    precompute_factorials(k);

    ll ans = 0;
    int max_a = min(k, n / 2);
    for (int a = 0; a <= max_a; a++)
    {
        int b = n - 2 * a;
        if (b < 0)
            continue;
        if (a + b > k)
            continue;
        ans = (ans + comb(k, a) * comb(k - a, b) % MOD) % MOD;
    }

    cout << ans << endl;

    return 0;
}