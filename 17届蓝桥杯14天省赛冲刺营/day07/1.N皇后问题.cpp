/*
题目描述
在 N×N 的方格棋盘放置了 N 个皇后，使得它们不相互攻击（即任意 2 个皇后不允许处在同一排，同一列，也不允许处在与棋盘边框成 45 角的斜线上。
你的任务是，对于给定的 N，求出有多少种合法的放置方法。

输入描述
输入中有一个正整数 N≤10，表示棋盘和皇后的数量

输出描述
为一个正整数，表示对应输入行的皇后的不同放置数量。

输入输出样例
示例 1
输入
5

输出
10*/
#include<iostream>
using namespace std;
int a[11][11];
int ans = 0; int n;
bool check(int deep, int m) {
    for (int k = 0; k < n; ++k) {
        if (a[k][m]) return false;
    }

    for (int i = 1; i <= deep; i++) {
        if (a[deep - i][m]) return false;
        if (m - i >= 0 && a[deep - i][m - i]) return false;
        if (m + i < n && a[deep - i][m + i]) return false;
    }
    return true;
}
void dfs(int deep) {
    if (deep == n) {
        ans++;
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (check(deep, i)) {
            a[deep][i] = 1;
            dfs(deep + 1);
            a[deep][i] = 0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    dfs(0);
    cout << ans;
    return 0;
}