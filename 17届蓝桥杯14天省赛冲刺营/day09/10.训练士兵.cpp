/*
问题描述
在蓝桥王国中，有 n 名士兵，这些士兵需要接受一系列特殊的训练，以提升他们的战斗技能。对于第 i 名士兵来说，进行一次训练所需的成本为 pi 枚金币，而要想成为顶尖战士，他至少需要进行 ci 次训练。

为了确保训练的高效性，王国推出了一种组团训练的方案。该方案包含每位士兵所需的一次训练，且总共只需支付 S 枚金币（组团训练方案可以多次购买，即士兵可以进行多次组团训练）。

作为训练指挥官，请你计算出最少需要花费多少金币，才能使得所有的士兵都成为顶尖战士？

输入格式
第一行包含两个整数 n 和 S，表示士兵的数量和进行一次组团训练所需的金币数。

接下来的 n 行，每行包含两个整数 pi 和 ci ，表示第 i 名士兵进行一次训练的金币成本和要成为顶尖战士所需的训练次数。

输出格式
输出一个整数，表示使所有士兵成为顶尖战士所需的最少金币数。

样例输入
3 6
5 2
2 4
3 2

样例输出
16

样例说明
花费金币最少的训练方式为：进行 2 次组团训练，花费 2×6=12 枚金币，此时士兵 1,3 已成为顶尖战士；再花费 4 枚金币，让士兵 2 进行两次训练，成为顶尖战士。总花费为 12+4=16。

评测用例规模与约定
对于 40% 的评测用例，1≤n≤10^3，1≤pi,ci≤10^5，1≤S≤10^7。

对于所有评测用例，1≤n≤10^5，1≤pi,ci≤10^6，1≤S≤10^10。*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
struct Node
{
    ll c, p;
};

bool cmp(Node x, Node y)
{
    if (x.c != y.c) return x.c < y.c;
    else return x.p < y.p;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    ll n, s, ans = 0, sum = 0, id = 0;
    cin >> n >> s;
    id = n;
    vector<Node> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i].p >> arr[i].c;
    }

    sort(arr.begin() + 1, arr.end(), cmp);

    while (sum < s && id>0)
    {
        sum += arr[id].p;
        id--;
    }
    id++;

    ll jxxl = arr[id].c;
    ans += jxxl * s;
    for (int i = id + 1; i <= n; i++)
    {
        if (arr[i].c > jxxl) ans += (arr[i].c - jxxl) * arr[i].p;
    }

    cout << ans << '\n';

    return 0;
}
