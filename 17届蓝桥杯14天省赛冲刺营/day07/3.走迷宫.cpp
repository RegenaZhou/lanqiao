/*
题目描述
给定一个 N×M 的网格迷宫 G。G 的每个格子要么是道路，要么是障碍物（道路用 1 表示，障碍物用 0 表示）。

已知迷宫的入口位置为 (x1,y1)，出口位置为 (x2,y2)。问从入口走到出口，最少要走多少个格子。

输入描述
输入第 1 行包含两个正整数 N,M，分别表示迷宫的大小。

接下来输入一个 N×M 的矩阵。若 Gi,j =1 表示其为道路，否则表示其为障碍物。

最后一行输入四个整数 x1,y1,x2,y2，表示入口的位置和出口的位置。

1≤N,M≤10^2，0≤Gi,j≤1，1≤x1,x2≤N，1≤y1,y2≤M。

输出描述
输出仅一行，包含一个整数表示答案。

若无法从入口到出口，则输出−1。

输入输出样例
示例 1
输入
5 5
1 0 1 1 0
1 1 0 1 1
0 1 0 1 1
1 1 1 1 1
1 0 0 0 1
1 1 5 5

输出
8*/
#include <iostream>
#include <queue>
using namespace std;
const int dirs[4][2] = { {0,1},{0,-1}, {1, 0},{-1,0} };
const int N = 110;
int n, m, sr, sc, dr, dc;
int grid[N][N], d[N][N];
queue<pair<int, int>> q;
int bfs() {
    q.emplace(sr, sc);
    memset(d, -1, sizeof d);
    d[sr][sc] = 0;
    while (!q.empty()) {
        pair<int, int> t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = t.first + dirs[i][0], y = t.second + dirs[i][1];
            if (x > 0 && x <= n && y > 0 && y <= m && grid[x][y] == 1 && d[x][y] == -1) {
                d[x][y] = d[t.first][t.second] + 1;
                q.emplace(x, y);
                if (x == dr && y == dc)
                    return d[x][y];
            }
        }
    }
    return -1;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> grid[i][j];
    cin >> sr >> sc >> dr >> dc;
    cout << bfs() << endl;
    return 0;
}