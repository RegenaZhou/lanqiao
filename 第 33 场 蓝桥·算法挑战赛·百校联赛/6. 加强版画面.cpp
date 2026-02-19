/*
问题描述
新年将至，灯光调试进入收尾阶段。

小蓝负责一项关键测试——在屏幕上以不同数量的小格拼出长方形图案。每个测试画面都会使用特定数量的小格，使这些小格拼成一个完整的矩形。

对于给定的小格总数 n，小蓝定义“拼接方案”为：n 个小格能够拼出的不同矩形数量。

若两个矩形行数或列数不同，则视为不同矩形。

例如，当 n=4 时，一共可拼出 3 种矩形：1 行 4 列，2 行 2 列，4 行 1 列。

节目组为这次测试准备了 N 个画面，第 i 个画面原定使用 Ai 个小格。现在，他们打算让每个画面都制作一个“加强版”，并规定如下条件：

加强版依然使用相同类型的小格；
加强版使用的小格总数必须是原设计使用量的整倍数；
在加强版中，小格数量对应的拼接方案数，需要恰好是原设计的两倍；
在满足以上条件的前提下，要求加强版使用的小格总数尽可能少。
节目组想知道：如果把所有画面的加强版都制作完成，一共需要多少个小格。现在，请你帮助小蓝完成这个计算。

输入格式
第一行输入一个整数 N（1≤N≤10^5），表示画面的数量。

第二行包含 N 个整数 A1,A2,…,AN（1≤Ai≤10^15），表示第 i 个画面原设计使用的小格数量。

输出格式
输出一个整数，表示所有画面的加强版所需小格数量的总和。

样例输入
3
1 2 3

样例输出
14*/
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <cstdint>
using namespace std;

using int64 = long long;
using i128 = __int128_t;

const int P = 14;
const int prime[P] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43 };
const int QMAX = 43;

vector<array<int, P>> vq(QMAX + 1);

int sol(long long A)
{
    array<int, P> cnt{};
    for (int i = 0; i < P; i++)
    {
        while (A % prime[i] == 0)
        {
            A /= prime[i];
            cnt[i]++;
        }
    }
    i128 now = 1;
    for (int i = 0; i < P; i++) now *= (i128)(cnt[i] + 1);
    for (int q = 1; q <= QMAX; q++)
    {
        i128 ret = now;
        auto& t = vq[q];
        for (int i = 0; i < P; i++)
        {
            if (t[i])
            {
                ret /= (i128)(cnt[i] + 1);
                ret *= (i128)(cnt[i] + t[i] + 1);
            }
        }
        if (ret == now * 2) return q;
    }
    return -1;
}

static void print_i128(i128 x)
{
    if (x == 0)
    {
        cout << 0;
        return;
    }
    if (x < 0)
    {
        cout << '-';
        x = -x;
    }
    string s;
    while (x)
    {
        int digit = (int)(x % 10);
        s.push_back('0' + digit);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    for (int q = 1; q <= QMAX; q++)
    {
        int x = q;
        array<int, P> e{};
        for (int i = 0; i < P; i++)
        {
            while (x % prime[i] == 0)
            {
                x /= prime[i];
                e[i]++;
            }
        }
        vq[q] = e;
    }

    int T;
    cin >> T;
    i128 sum = 0;
    while (T--)
    {
        int64 A;
        cin >> A;
        int q = sol(A);
        sum += (i128)q * (i128)A;
    }
    print_i128(sum);
    return 0;
}