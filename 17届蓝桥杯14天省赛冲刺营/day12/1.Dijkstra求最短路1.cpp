/*
问题描述
给定一张 n 个点 m 条边的有向图，该图可以有自环与重边。

你需要输出 1 号点到 n 号点的最短路，若不存在此最短路，输出 -1。

输入格式
第一行输入二个正整数 n,m。

接下来 m 行，每行输入 3 个正整数 a,b,c。表示点 a 到点 b 存在一条有向边，权值为 c。

2≤n≤500,1≤m≤10^5,1≤a,b≤n,1≤c≤10^4。

输出格式
输出 1 号点到 n 号点的最短路，若不存在此最短路，输出 -1。

样例输入
5 8
1 4 5
2 4 7
3 5 8
1 3 8
5 1 12
4 2 7
4 5 10
2 5 3

样例输出
15

说明
图片描述

看图可知最短路为 [1,4,2,5]。*/
#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using ll = long long;
using namespace std;

vector<int> dijkstra(int n, vector<vector<pair<int, int>>>& graph, int start)
{
	vector<int> dist(n + 1, INT_MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty())
	{
		int u = pq.top().second;
		int current_dist = pq.top().first;
		pq.pop();

		if (current_dist > dist[u]) continue;

		for (auto& edge : graph[u])
		{
			int v = edge.first;
			int weight = edge.second;

			if (dist[u] + weight < dist[v])
			{
				dist[v] = dist[u] + weight;
				pq.push({ dist[v], v });
			}
		}
	}

	return dist;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> graph(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
	}

	vector<int> dist = dijkstra(n, graph, 1);
	if (dist[n] == INT_MAX)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << dist[n] << endl;
	}
	return 0;
}
