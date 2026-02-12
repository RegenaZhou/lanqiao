/*
问题描述
新春将至，蓝桥王国的国王给小蓝和小桥下达了一项新春巡游任务。

蓝桥王国共有 N 个城市，编号为 1 到 N，城市之间由 N−1 条道路连接，整个王国形成一棵树（即任意两个城市之间有且仅有一条路径）。

小蓝和小桥需要将这 N 个城市划分成两组：小蓝主导的组和小桥主导的组，并满足以下条件：

小蓝主导的所有城市构成的子图是连通的。
小桥主导的所有城市构成的子图也是连通的。
对于一种合法的划分方案，定义：

a = 小蓝组内任意两个城市之间的最远距离。
b = 小桥组内任意两个城市之间的最远距离。
该划分方案的代价为 max(a,b)。

对于所有合法的划分方案，你需要帮小蓝和小桥计算最小的划分代价是多少？

输入格式
第一行包含一个整数 N（2≤N≤10^5），表示城市数量。

接下来 N−1 行，每行两个整数 u v（1≤u,v≤N,u≠v），表示城市 u 和 v 之间有一条道路。

输出格式
输出一行一个整数，表示所有合法划分方案中最小的代价。

样例输入
7
1 2
2 3
3 4
2 5
3 6
4 7

样例输出
3

样例说明
对于样例，一种可能的最优划分方式如下图，其中小蓝主导城市 1,2,5，小桥主导城市 3,4,6,7，其中 a=2,b=3。*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto bfs = [&](int start)->pair<int, int>
        {
            vector<int> dist(n + 1, -1);
            queue<int> q;
            q.push(start);
            dist[start] = 0;
            int far = start;

            while (!q.empty())
            {
                int u = q.front();
                q.pop();

                for (int v : g[u])
                {
                    if (dist[v] == -1)
                    {
                        dist[v] = dist[u] + 1;
                        if (dist[v] > dist[far])
                        {
                            far = v;
                        }
                        q.push(v);
                    }
                }
            }
            return { far,dist[far] };
        };

    int a = bfs(1).first;
    int b = bfs(a).first;

    vector<int> dist(n + 1, -1);
    vector<int> prev(n + 1, -1);
    queue<int> q;
    q.push(a);
    dist[a] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : g[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                prev[v] = u;
                q.push(v);
            }
        }
    }

    int diam = dist[b];

    vector<int> path;
    for (int u = b; u != -1; u = prev[u])
    {
        path.push_back(u);
    }
    reverse(path.begin(), path.end());

    int mid = diam / 2;
    int x = path[mid];
    int y = path[mid + 1];

    g[x].erase(remove(g[x].begin(), g[x].end(), y), g[x].end());
    g[y].erase(remove(g[y].begin(), g[y].end(), x), g[y].end());

    auto get = [&](int start)->int
        {
            int p1 = bfs(start).first;
            int d = bfs(p1).second;
            return d;
        };

    int d1 = get(x);
    int d2 = get(y);

    cout << max(d1, d2) << '\n';

    return 0;
}