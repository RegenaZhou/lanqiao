/*
问题描述
冬季来临，蓝桥学院组织了一次冬季巡游活动。活动地点是一片由 n 棵魔法树组成的森林，这些树通过 n−1 条魔法小径相互连接，形成一棵树结构。
第 i 棵树上生长着一颗魔法晶体，蕴含 Ai 点积分。

巡游小队可以从任意一棵树开始，按照以下规则进行巡游：

每次可以沿着一条魔法小径移动到相邻的树（可重复到达某一棵树，但积分只能获取一次）。

可以在任意时刻选择结束巡游。

巡游结束后，小队获得的积分等于巡游过程中经过的所有树的积分之和。现在请你计算：有多少种不同的巡游方案，使得最终积分恰好等于 k。
由于答案可能很大，你需要将答案对 10^9+7 取模。。

注意：两种方案不同，当且仅当经过的树的集合不同。

输入格式
第一行包含两个整数 n,k(1≤n≤1000, 1≤k≤100)，分别表示树的节点数和目标积分。

第二行包含 n 个整数 A1,A2,…,An(0≤Ai≤1)，表示每棵树的积分。

接下来 n−1 行，每行两个整数 u v，表示第 u 棵树和第 v 棵树之间有一条魔法小径（保证是一棵树）。

输出格式
输出一行一个整数，表示方案数对 10^9+7 取模后的结果。

样例输入
3 1
1 0 1
1 2
1 3

样例输出
3*/
#include <iostream>
#include <vector>
#include <functional>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0LL));
    vector<ll> tot(n + 1, 0LL);

    function<void(int, int)> dfs = [&](int u, int par)
        {
        if (a[u] <= k)
        {
            dp[u][a[u]] = 1;
        }

        for (int v : adj[u])
        {
            if (v == par) continue;
            dfs(v, u);

            vector<ll> nw(k + 1, 0LL);
            for (int c = 0; c <= k; c++)
            {
                if (dp[u][c] == 0) continue;
                nw[c] = (nw[c] + dp[u][c]) % MOD;

                for (int s = 0; s <= k - c; s++)
                {
                    if (dp[v][s] == 0) continue;
                    nw[c + s] = (nw[c + s] + dp[u][c] * dp[v][s] % MOD) % MOD;
                }
            }
            dp[u] = std::move(nw);
        }

        tot[u] = (k >= a[u] ? dp[u][k] : 0LL);
        for (int v : adj[u])
        {
            if (v == par) continue;
            tot[u] = (tot[u] + tot[v]) % MOD;
        }
        };

    dfs(1, -1);
    cout << tot[1] << '\n';
    return 0;
}