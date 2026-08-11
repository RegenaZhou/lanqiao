/*
问题描述
蓝桥学院正在筹备一场暑期程序设计竞赛集训，并计划联合其他多所学院共同参与。为此，院长提前对机房进行了座位规划：机房共设有 n 列座位，其中第 i 列提供 ai 个机位。

集训报名结束后，全部机位恰好被集训人员坐满，也就是说，机房中每一个存在的机位最终都会有人使用。

在安排座位时，为避免同校学员相互交流、影响集训效果，蓝桥学院自己的集训人员需遵守以下限制：

不能安排在同一列。
如果两人被安排在同一行，那么他们之间必须至少存在一个空位，否则不能安排在同一行。
其中，空位指的是：若某一列在这一行本身不存在机位（即该列的机位数量不足以延伸到这一行），则该位置被视为空位。

已知蓝桥学院共有 K 名集训人员参与本次集训，请你帮院长计算：仅为这 K 名蓝桥学院集训人员安排座位，共有多少种不同的合法方案？

由于答案可能很大，请将结果对 10^9+7 取模后输出。

输入格式
第一行输入两个整数 n,K(1≤K≤n≤400)，分别表示机房的列数与蓝桥学院的集训人数。

第二行输入 n 个整数 a1,a2,…,an(1≤ai≤10^6)，表示每一列的机位数量。

输出格式
输出一个整数，表示蓝桥学院集训人员合法座位安排方案的总数（对 10^9+7 取模）。

样例输入
3 2
2 1 2

样例输出
5

样例说明
对于样例而言，合法的 5 种方案如下图：*/
/*
问题描述
蓝桥学院正在筹备一场暑期程序设计竞赛集训，并计划联合其他多所学院共同参与。为此，院长提前对机房进行了座位规划：机房共设有 n 列座位，其中第 i 列提供 ai 个机位。

集训报名结束后，全部机位恰好被集训人员坐满，也就是说，机房中每一个存在的机位最终都会有人使用。

在安排座位时，为避免同校学员相互交流、影响集训效果，蓝桥学院自己的集训人员需遵守以下限制：

不能安排在同一列。
如果两人被安排在同一行，那么他们之间必须至少存在一个空位，否则不能安排在同一行。
其中，空位指的是：若某一列在这一行本身不存在机位（即该列的机位数量不足以延伸到这一行），则该位置被视为空位。

已知蓝桥学院共有 K 名集训人员参与本次集训，请你帮院长计算：仅为这 K 名蓝桥学院集训人员安排座位，共有多少种不同的合法方案？

由于答案可能很大，请将结果对 10^9+7 取模后输出。

输入格式
第一行输入两个整数 n,K(1≤K≤n≤400)，分别表示机房的列数与蓝桥学院的集训人数。

第二行输入 n 个整数 a1,a2,…,an(1≤ai≤10^6)，表示每一列的机位数量。

输出格式
输出一个整数，表示蓝桥学院集训人员合法座位安排方案的总数（对 10^9+7 取模）。

样例输入
3 2
2 1 2

样例输出
5

样例说明
对于样例而言，合法的 5 种方案如下图：*/
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
static const long long MOD = 1000000007;
int N, K;
vector<int> a;
vector<long long> fact, inv_fact;

long long qpow(long long b, long long e, long long m)
{
    long long r = 1; b %= m;
    while (e > 0)
    {
        if (e & 1) r = r * b % m;
        b = b * b % m;
        e >>= 1;
    }
    return r;
}

void prepFact(int n)
{
    fact.assign(n + 1, 1);
    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
    inv_fact.assign(n + 1, 1);
    inv_fact[n] = qpow(fact[n], MOD - 2, MOD);
    for (int i = n; i >= 1; i--) inv_fact[i - 1] = inv_fact[i] * i % MOD;
}

long long C(long long n, long long c)
{
    if (c < 0 || n < 0 || c > n) return 0;
    return fact[n] * inv_fact[c] % MOD * inv_fact[n - c] % MOD;
}

long long P(long long w, long long c)
{
    if (c < 0 || c > w) return 0;
    return fact[w] * inv_fact[w - c] % MOD;
}

vector<long long> build(int l, int r, int floor_h)
{
    if (l > r) return { 1 };

    int pos = l;
    for (int i = l + 1; i <= r; i++) if (a[i] < a[pos]) pos = i;
    int m = a[pos];

    vector<long long> left = build(l, pos - 1, m);
    vector<long long> right = build(pos + 1, r, m);

    int lenL = pos - l, lenR = r - pos;
    int maxs = min(K, lenL + lenR);
    vector<long long> dpMid(maxs + 1, 0);

    for (int x = 0; x <= min((int)left.size() - 1, maxs); x++)
    {
        if (left[x] == 0) continue;
        for (int y = 0; y <= min((int)right.size() - 1, maxs - x); y++)
        {
            if (right[y] == 0) continue;
            dpMid[x + y] = (dpMid[x + y] + left[x] * right[y]) % MOD;
        }
    }

    long long w = m - floor_h;
    int length = r - l + 1;
    int maxj = min(K, length);
    vector<long long> dpNode(maxj + 1, 0);

    for (int s = 0; s <= min((int)dpMid.size() - 1, maxj); s++)
    {
        if (dpMid[s] == 0) continue;
        int cMax = min({ maxj - s, (int)w, length - s });
        for (int c = 0; c <= cMax; c++)
        {
            int j = s + c;
            long long add = dpMid[s] * C(length - s, c) % MOD * P(w, c) % MOD;
            dpNode[j] = (dpNode[j] + add) % MOD;
        }
    }
    return dpNode;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> N >> K;
    a.assign(N, 0);
    int maxA = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        maxA = max(maxA, a[i]);
    }

    int factSize = max(maxA, N);
    prepFact(factSize);

    vector<long long> dp = build(0, N - 1, 0);
    long long ans = (K < (int)dp.size()) ? dp[K] : 0;
    cout << ans << '\n';
    return 0;
}
