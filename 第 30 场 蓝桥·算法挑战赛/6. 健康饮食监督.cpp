/*
问题描述
新学期，学校食堂推出了“健康饮食监督”计划。食堂设有 n×n 个供餐窗口，排列成一个 n 行 n 列的方阵。每个窗口提供一道菜肴，具体如下：

若窗口坐标为 x,y)，且 x×y 为奇数，则供应荤菜；
否则，供应素菜。
学生从食堂入口 (1,1) 出发，每次只能往右或往下移动一格，直到最终到达出口 (n,n)。
根据校医室规定：途中至少要吃到 n−1 份荤菜，否则将被判定为“饮食不均衡”。

现在请你计算：从入口 (1,1) 走到出口 n,n)，满足校医规定的不同路线共有多少条？由于答案可能很大，请输出结果对 998244353 取模后的值。

输入格式
第一行包含一个整数 t（1≤t≤10^3），表示测试数据的组数。

接下来 t 行，每行包含一个正整数 n（4≤n≤10^5），表示方阵的边长。

输出格式

输出共 t 行，每行一个整数，表示满足校医规定的路线总数。由于答案可能很大，请输出结果对 998244353 取模后的值。*/

//总共吃2n-1道菜
//荤菜：x*y=奇数，x为奇数且y也为奇数
//至少要吃到 n−1 份荤菜  至多吃 n 份素菜
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll mod = 998244353;

vector<ll> f, invf;

ll qmi(ll a, ll b)//qmi快速幂取模算法，a是底数，b是指数
{
    ll res = 1;
    while (b)
    {
        if (b & 1)//检查b是否为奇数，奇数时满足条件
        {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;//相当于b/=2
    }
    return res;
}

void init(int n)
{
    f.resize(n + 1);//阶乘数组f
    invf.resize(n + 1);//模逆元数组invf
    f[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        f[i] = f[i - 1] * i % mod;
    }
    invf[n] = qmi(f[n], mod - 2);
    for (int i = n - 1; i >= 0; i--)
    {
        invf[i] = invf[i + 1] * (i + 1) % mod;
    }
}

ll C(int a, int b)//计算组合数
{
    if (b<0 || b>a) return 0;
    return f[a] * invf[b] % mod * invf[a - b] % mod;
}

void solve()
{
    int n;
    cin >> n;
    if (n % 2 == 1)
    {
        int k = (n - 1) / 2;
        cout << n * C(n - 1, k) % mod << '\n';
    }
    else
    {
        int k = (n - 2) / 2;
        cout << 2 * C(n - 2, k) % mod << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    init(100000);
    while (t--)
    {
        solve();
    }
    return 0;
}
