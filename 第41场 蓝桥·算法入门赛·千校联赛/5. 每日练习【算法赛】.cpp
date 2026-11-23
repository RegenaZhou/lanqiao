/*
问题描述
小蓝正在为 AI 安排连续 N 天的解题测试。第一天至少安排一道题，具体数量由小蓝决定。

为了逐步增加测试数量，从第二天开始，小蓝每天安排的题数必须比前一天多 1 道或多 K 道，其中 K≥2。

小蓝提出了 Q 个总题数要求。对于每个给定的 S，他想知道有多少种安排，能够使这 N 天的题数之和恰好为 S。

现在，请你帮助小蓝计算每个要求对应的安排数量。两种安排只要有一天的题数不同，就视为不同的安排。答案对 998244353 取模。

输入格式
第一行包含三个整数 N,K,Q（1≤N≤400，2≤K≤10^9，1≤Q≤10^5），分别表示测试天数、允许的较大增加量和总题数要求的数量。

接下来 Q 行，每行包含一个整数 S（1≤S≤10^18），表示这 N 天需要安排的题目总数。

输出格式
输出 Q 行，每行一个整数，表示满足对应要求的安排数量对 998244353 取模后的结果。

样例输入
3 3 6
6
7
8
10
12
18

样例输出
1
0
1
1
2
2

样例说明
测试共进行三天，每天比前一天多一道或三道题。

总题数为 6 时，只有 1,2,3 这一种安排；总题数为 7 时，没有符合要求的安排。


总题数为 12 时，可以安排为 1,4,7 或 3,4,5，因此对应答案为 2。*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;
const int MAXN = 401;
const int MAXSUM = 400 * 400 / 2 + 10; // 79800

int n, K, Q;
ll base;
int w[MAXN];
ll tot[MAXSUM]; // tot[s]：子集和为s的方案数
vector<ll> vec[MAXN];
vector<ll> pre[MAXN];

// 扩展欧几里得
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) { x = 1; y = 0; return a; }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

// 解 a*s ≡ b (mod m)，返回所有满足条件的余数rem（0<=rem<m）
vector<int> solve(ll a, ll b, ll m) {
    vector<int> res;
    ll x, y;
    ll g = exgcd(a, m, x, y);
    if (b % g != 0) return res;
    ll a1 = a / g;
    ll b1 = b / g;
    ll m1 = m / g;
    exgcd(a1, m1, x, y);
    x = (x % m1 + m1) % m1;
    ll s0 = (b1 * x) % m1;
    for (ll t = 0; t < g; t++) {
        ll cur = (s0 + t * m1) % m;
        res.push_back((int)cur);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> K >> Q;
    if (n == 1) {
        // 特判 n=1：没有增量，只有x>=1，总和S=x，方案永远是1（只要S>=1）
        while (Q--) {
            ll S; cin >> S;
            cout << 1 % MOD << '\n';
        }
        return 0;
    }
    base = 1LL * n * (n - 1) / 2;
    int m = n; // 同余模数是n
    for (int i = 1; i <= n - 1; i++) {
        w[i] = n - i;
    }
    // dp 求 tot[s]
    memset(tot, 0, sizeof tot);
    tot[0] = 1;
    int maxs = base;
    for (int i = 1; i <= n - 1; i++) {
        int wi = w[i];
        for (int s = maxs; s >= wi; s--) {
            tot[s] = (tot[s] + tot[s - wi]) % MOD;
        }
    }
    // 按余数分组 + 前缀和
    for (int s = 0; s <= maxs; s++) {
        if (tot[s] == 0) continue;
        int rem = s % m;
        vec[rem].push_back(s);
    }
    for (int r = 0; r < m; r++) {
        auto &v = vec[r];
        sort(v.begin(), v.end());
        pre[r].resize(v.size() + 1, 0);
        for (int i = 0; i < v.size(); i++) {
            pre[r][i + 1] = (pre[r][i] + tot[v[i]]) % MOD;
        }
    }
    // 处理查询
    while (Q--) {
        ll S;
        cin >> S;
        ll R = S - base;
        if (R <= 0) {
            cout << "0\n";
            continue;
        }
        ll A = (1LL * (K - 1)) % m;
        ll B = R % m;
        auto rems = solve(A, B, m);
        ll ans = 0;
        ll C = K - 1;
        for (int rem : rems) {
            auto &v = vec[rem];
            if (v.empty()) continue;
            // 找最大 s 满足 C * s < R
            int l = 0, r = (int)v.size() - 1, pos = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                ll sval = v[mid];
                // 防溢出：C可以1e9，sval 8e4，乘积 8e13 <9e18，ll装得下
                if (C * sval < R) {
                    pos = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            if (pos != -1) {
                ans = (ans + pre[rem][pos + 1]) % MOD;
            }
        }
        cout << ans % MOD << '\n';
    }
    return 0;
}
