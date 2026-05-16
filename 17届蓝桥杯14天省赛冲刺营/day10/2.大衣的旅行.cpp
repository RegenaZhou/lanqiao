/*
问题描述
大衣的学校计划为 K 个同学和 1 个老师安排一次旅行。

他们住宿旅馆的房间形如一个 N 行 M 列的矩阵，这里有 N×M 个房间，房间 (i,j) 可以容纳 A(i,j) 个人。

定义房间 (i1,j1) 和 (i2,j2) 的距离为 max(∣i1−i2∣,∣j1−j2∣)。

你的任务安排他们的房间，使老师的房间和距离他最远的学生的房间距离最小，如果旅馆无法容纳下这 K+1​ 个人输出 −1​。

输入格式
第一行输入一个正整数 T 表示测试数据的组数。

接下来 T​ 组测试数据每组输入：

第一行输入三个正整数 N,M,K 分别表示矩阵的大小和同学的数量。
接下来 N 行每行输入 M 个整数表示每个房间能容纳的人数。
输出格式
对于每组测试数据，输出一个整数表示老师的房间和距离他最远的学生的房间的最小距离，如果无法容纳下 K+1 个人输出 −1，并换行。

样例输入1
4
1 7 5
2 1 0 1 3 0 1
2 4 3
1 0 4 0
0 2 0 3
2 2 7
1 0
4 1
3 2 3
0 2
1 0
1 0

样例输出1
3
0
-1
1

说明
样例 1：老师住在房间 (1,2)，两个学生住在房间 (1,1)，一个学生住在房间 (1,4)，两个学生住在房间 (1,5)。
距离老师房间最远的学生的房间为 (1,5)，距离为 3，可以证明没有其他的安排方式能使最小距离小于 3。

样例 2：老师和 3 个学生可以都住在房间 (1,3)，因此距离为 0。

样例 3​：旅馆没有足够的人数容量。

评测数据规模
对于所有的评测数据，1≤T≤20，1≤N×M≤10^4，1≤K≤10^9，0≤Ai,j≤10^5。*/
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
ll k;
int n, m, t;
ll get_num(int l, int i, int j, vector<vector<int>>& sum);
void solve() {
    cin >> n >> m >> k;
    vector<vector<int>>arr(n + 1, vector<int>(m + 1));
    vector<vector<int>>sum(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            sum[i][j] = sum[i][j - 1] + arr[i][j];
        }
        for (int j = 1; j <= m; j++)
            sum[i][j] += sum[i - 1][j];
    }  //创建二维前缀和

    int x = 0, y = max(n, m);
    int flag = 1;
    while (x < y) {
        int mid = (x + y) / 2;
        if (sum[n][m] - sum[0][m] - sum[n][0] + sum[0][0] < k + 1) {   
        //如果房间总人数都＜k+1，可以直接跳过输出-1了
            flag = 0; break;
        }
        int ret = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (arr[i][j] == 0)continue;
                if (get_num(mid, i, j, sum) >= k + 1) {
                    ret = 1; 
                    break;   //可以的话就不用继续枚举了
                }
            }
            if (ret)break;
        }
        if (ret)y = mid;
        else x = mid + 1;
    }
    if (x == max(n, m) || flag == 0)cout << -1 << "\n";
    else cout << x << "\n";
}
ll get_num(int l,int i,int j,vector<vector<int>>&sum) {  
    //x1,x2,y1,y2为以 l（mid）一圈的数组范围内坐标，用来计算二维前缀和
    int x1 = max(i - l, 1), y1 = max(j - l, 1), x2 = min(i + l, n), y2 = min(j + l, m);
    return sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1 - 1][y1 - 1];
}
int main()
{
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
