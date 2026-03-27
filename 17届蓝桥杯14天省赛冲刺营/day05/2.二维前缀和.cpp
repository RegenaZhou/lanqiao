/*
问题描述
给定一个 n×m 大小的矩阵 A。

给定 q 组查询，每次查询为给定 4 个正整数 x1,y1,x2,y2 ，你需要输出 ∑i=x1x2∑j=y1y2 Ai,j 的值。

输入格式
第一行输入 3 个正整数 n,m,q。（1≤n,m≤10^3 ,1≤q≤10^5）

接下来 n 行每行输入 m 个整数，表示 Ai,j 。(−10^3≤Ai,j≤10^3 ,1≤i≤n,1≤j≤m)

接下来 q 行，每行输入 4 个正整数 x1,y1,x2,y2。(1≤x1≤x2≤n,1≤y1≤y2≤m)

输出格式
对于每次查询，输出一个整数，表示查询的子矩阵的和。

样例输入
3 4 3
1 7 2 4
3 6 2 8
2 1 2 3
1 1 2 2
2 1 3 4
1 3 3 4

样例输出
17
27
21*/
#include <iostream>
using namespace std;
const int N = 1005;
int a[N][N], s[N][N];

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    //构造
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + a[i][j];
        }
    }
    //求和
    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        long long ans = s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1];
        cout << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
/*#include<iostream>
using namespace std;

const int MAXN = 1005;
int a[MAXN][MAXN], sum[MAXN][MAXN];

int main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        }
    }
    while(q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1] << endl;
    }
    return 0;
}*/