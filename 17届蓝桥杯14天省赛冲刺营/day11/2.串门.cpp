/*
问题描述
过年了，小蓝想要回家串门。

蓝桥村可以抽象为 n 个节点，n−1 条边的一棵树，每条边有边权长度 wi。

小蓝可以选择任意一个点作为起点，然后选择一条路径，可以访问每个节点至少一次。他想知道最短的路径长度是多少。

输入格式
第一行输入一个整数 n，表示节点数量。

接下来 n−1 行，每行三个整数 vi,ui,wi，表示 (vi,ui) 存在一条 wi 的边。

输出格式
输出一个整数，表示最短路径。

样例输入
4
1 2 3
1 3 4
1 4 5

样例输出
15

说明
路径为：4→51→32→31→43，路径和值为 15。

评测数据范围 1≤n≤10^5,1≤vi,ui≤n,1≤wi≤10^9。

保证输入数据是一棵树。*/
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int n;
vector<vector<pair<int, ll>>> graph;
vector<ll> dist;
void dfs(int cur, int fa, int& farNode, ll& maxDis)
{
    for (auto& edge : graph[cur])
    {
        int nex = edge.first;
        ll w = edge.second;
        if (nex == fa) continue;
        dist[nex] = dist[cur] + w;
        if (dist[nex] > maxDis)
        {
            maxDis = dist[nex];
            farNode = nex;
        }
        dfs(nex, cur, farNode, maxDis);
    }

}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int v, u, w;
    ll ans = 0;
    cin >> n;
    graph.resize(n);
    dist.resize(n);
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> v >> u >> w;
        graph[v - 1].push_back({ u - 1,w });
        graph[u - 1].push_back({ v - 1,w });
        ans += w;
    }

    int p = 0;
    ll res = 0;
    fill(dist.begin(), dist.end(), 0);
    dfs(0, -1, p, res);
    ll zj = 0;
    fill(dist.begin(), dist.end(), 0);
    dfs(p, -1, p, zj);
    ans = 2 * ans - zj;
    cout << ans << '\n';

    return 0;
}