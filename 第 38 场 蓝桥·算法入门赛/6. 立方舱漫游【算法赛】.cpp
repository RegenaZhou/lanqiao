/*
问题描述
有 2^d 个房间。每个房间用一个长度为 d 的二进制串编号，例如当 d=3 时，房间编号可以是 000、001、010 等。

如果两个房间的编号恰好只有一位不同，那么这两个房间之间有一条通道。

小蓝一开始在编号为全 0 的房间。接下来他会移动 n 次。每次移动时，他会从当前房间相邻的 d 个房间中等概率选择一个走过去。

我们只统计“移动结束后”是否回到起点房间，不统计最开始就在起点的那一次。

令 R 表示这 n 次移动中，小蓝回到起点房间的次数。请你求出 R 的数学期望。

答案可能是分数。若答案为 p/q ，请输出：p×q^(−1)(mod998244353)
其中 q^(−1) 表示 q 在模 998244353 意义下的乘法逆元。

输入格式
输入共 T+1 行。

第一行包含一个正整数 T（1≤T≤5），表示询问次数。

接下来 T 行，每行包含两个正整数 d,n（1≤d≤500，1≤n≤2×10^5），且所有询问的 d×n 之和不超过 2×10^7。

输出格式
输出共 T 行，每行包含一个整数，表示对应询问的答案。

样例输入
4
1 5
2 4
3 2
3 4

样例输出
2
1
332748118
702468249

样例说明
对于第三个询问，d=3,n=2。

第一次移动一定会把某一位从0 变成1。第二次移动只有再次选择同一位，才能回到 000。这个概率是 1/3 ，因此输出 3 的逆元 332748118。*/
#include <iostream>
using namespace std;
using ll = long long;
const int mod = 998244353;
const int N = 505;
int C[N][N];

int qpow(int a, int b) {
    int ans = 1;
    a %= mod;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

void init() {
    for (int i = 0; i < N; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
}

void solve() {
    int d, n; 
    cin >> d >> n;
    int pow2d = qpow(2, d);
    int inv2d = qpow(pow2d, mod - 2);
    int invd = qpow(d, mod - 2);
    int S = 0;
    for (int i = 0; i <= d; i++) {
        int c = C[d][i];
        int a = (d - 2 * i) % mod;
        if (a < 0) a += mod;
        int r = a * invd % mod;
        int rn = qpow(r, n);
        int sum_r;
        if (r == 1) {
            sum_r = n % mod;
        }
        else {
            int numer = r * ((1 - rn + mod) % mod) % mod;
            int denom = (1 - r + mod) % mod;
            sum_r = numer * qpow(denom, mod - 2) % mod;
        }
        S = (S + c * sum_r) % mod;
    }
    int ans = S * inv2d % mod;
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
