/*
问题描述
新的学期开始了，蓝桥学院的各科陆续开始开学考核，数论老师小蓝也给同学们布置了一道富有挑战性的题目。

在数论实验室中，小蓝发现了一组特殊的数字三元组 (a,b,c)。如果一个三元组满足 a<b<c 且其二进制表示下的按位异或值满足 a⊕b=c，则称其为 "和谐三元组"。

现在，小蓝给出了 t 组区间范围 [l,r]，请你计算在每个给定的闭区间内，有多少组不同的 "和谐三元组" 满足 l≤a,b,c≤r。

由于答案可能非常大，请将结果对 10^9+7 取模。

输入格式
第一行包含一个整数 t(1≤t≤10^3)，表示考核的轮数。

接下来的 t 行，每行包含两个整数 l 和 r(1≤l<r≤10^18)，表示每一轮考核中数字的取值范围。

输出格式
对于每一轮考核，输出一个整数，表示该范围内 "和谐三元组" 的数量模 10^9+7 后的结果。

样例输入
4
1 5
2 34324
1 10001
3 123456

样例输出
2
180134772
12817860
393063808

样例说明
对于询问区间 [1,5] 中，只有 (1,2,3),(1,4,5) 是 "和谐三元组" 。*/
#include <iostream>
#include <algorithm>
using namespace std;
using ull = unsigned long long;
const ull MOD = 1000000007;

// 计算在 [0, X] 范围内，第 p 位（从0开始）为 1 的数字个数
ull count_p_bit_set(ull X, int p)
{
    ull period = 1ULL << (p + 1);  // 周期长度，例如 p=0 时周期为 2 (0,1)
    ull blocks = (X + 1) / period; // 完整周期的个数
    ull rem = (X + 1) % period;    // 剩余数字的个数
    ull half = 1ULL << p;          // 半个周期长度，即每个周期内 1 的个数

    ull count = blocks * half;
    if (rem > half)
    {
        count += rem - half;
    }
    return count;
}

void solve()
{
    ull l, r;
    cin >> l >> r;
    ull ans = 0;

    // 枚举 a 的最高位 p
    // 因为 r <= 10^18, 2^60 > 10^18，所以 p 最大到 60 即可
    for (int p = 0; p <= 60; ++p)
    {
        // 1. 计算当前 p 下合法的 a 的数量
        ull low_a = max((ull)l, 1ULL << p);
        ull high_a = min((ull)r, (1ULL << (p + 1)) - 1);

        if (low_a > high_a) continue; // 没有满足条件的 a

        ull A_p = high_a - low_a + 1;

        // 2. 计算当前 p 下合法的 c 的数量
        // c 必须在 [2^(p+1), r] 范围内，且第 p 位为 1
        ull limit_c = (1ULL << (p + 1)) - 1;
        if (r > limit_c)
        {
            // [0, limit_c] 内第 p 位为 1 的数字恰好有 2^p 个
            ull C_p = count_p_bit_set(r, p) - (1ULL << p);

            // 3. 乘法原理累加到答案，注意随时取模
            ans = (ans + (A_p % MOD) * (C_p % MOD)) % MOD;
        }
    }
    cout << ans << "\n";
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