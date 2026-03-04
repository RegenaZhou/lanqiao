/*
问题描述
新的学期开始了，蓝桥学院的各科陆续开始开学考核，体育老师也不例外。

小蓝的班级共有 N 位同学，当前从左到右站成一排，第 i 位同学的编号为 Pi ，即队伍的编号序列为 P1,P2,…,PN 。其中 P 是 1 到 N 的一个排列（每个编号恰好出现一次）。

体育老师对队伍的排列顺序不满意，当且仅当存在某个下标 j（满足 1≤j≤N−1），使得前 j 个位置上的编号集合恰好是 1 到 j 的排列。

小蓝每次操作可以交换相邻两位同学的位置，请问小蓝至少需要多少次相邻交换，才能使体育老师对队伍满意？

输入格式
第一行一个整数 N(1≤N≤10^5)，表示班级人数。

第二行 N 个整数 P1,P2,…,PN ，表示当前队伍的编号序列，保证 P 是 1 到 N 的一个排列。

输出格式
输出一个整数，表示最少需要的相邻交换次数，使得体育老师对队伍满意。

样例输入
3
1 2 3

样例输出
2

样例说明
其中一种使得体育老师满意的排列方式为 [3,1,2]，这需要小蓝交换 2 次。*/
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int cnt = 0, sum = 0, cur = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
        cur += a[i];
        if (cur == sum)
        {
            cnt++;
        }
    }
    cout << (cnt ? cnt - 1 : cnt) << '\n';
    return 0;
}