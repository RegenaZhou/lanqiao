/*
问题描述
小蓝有一个 n 行 m 列的白色棋盘, 棋盘的每一个方格都可以被染成彩色。

每个方格有一个染色时间 tij, 不同方格的染色时间可能不同。如果一个方 格被触发了染色, 这个方格就会在 tij 秒之后变成彩色, 然后将自己上下左右四 个方向相邻的方格触发染色。
每个方格只能被触发染色一次, 第一次触发之后 的触发为无效触发。

给定每个方格的染色时间, 在时刻 0 触发第一行第一列的方格染色, 请问 多长时间后整个棋盘完成染色。

输入格式
输入的第一行包含两个整数 n,m, 分别表示棋盘的行数和列数。

接下来 n 行, 每行 m 个正整数, 相邻的整数之间用一个空格分隔, 表示每 个方格的染色时间。该部分的第 i 行第 j 个整数表示 tij , 即第 i 行第 j 列的方 格的染色时间。

输出格式
输出一行包含一个整数, 表示整个棋盘完成染色的时间。

样例输入

2 3

1 2 3

4 5 6

样例输出

12

评测用例规模与约定
对于 30 的评测用例, 1≤n,m≤10 。

对于 60 的评测用例, 1≤n,m≤50 。

对于所有评测用例, 1≤n,m≤500,1≤tij≤1000 。*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int ans = 0;
int arr[510][510];
bool vis[510][510];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

struct Node
{
    int x, y, ti;
};

struct cmp
{
    bool operator()(const Node& a, const Node& b) const
    {
        return a.ti > b.ti;
    }
};

void bfs()
{
    priority_queue<Node, vector<Node>, cmp> pq;
    vis[0][0] = true;
    pq.push({ 0,0,arr[0][0] });
    while (!pq.empty())
    {
        Node tmp = pq.top();
        pq.pop();
        ans = max(ans, tmp.ti);
        for (int i = 0; i < 4; i++)
        {
            int nx = tmp.x + dx[i], ny = tmp.y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny]) continue;
            vis[nx][ny] = true;
            pq.push({ nx,ny,tmp.ti + arr[nx][ny] });
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    bfs();
    cout << ans << '\n';

    return 0;
}
