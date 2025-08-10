/*
问题描述
在近期举办的蓝桥杯竞赛中，诞生了一场激动人心的双人破译挑战。
比赛的主办方准备了 N 块神秘的密码芯片，参赛队伍需要在这场智力竞赛中展示团队合作的默契与效率。
每个队伍需选出一位破译者与一位传输者，破译者的任务是解锁芯片中隐藏的密码，
而传输者则负责将解密后的密码准确无误地发送至主办方的电脑。

在这场比赛中，小蓝与小桥组队参赛，经过深入的讨论与协商，小蓝被任命为破译者，专注于解密每一块密码芯片；
而小桥则担任传输者，确保每一份信息能够迅速且顺畅地传递给裁判。比赛开始后，他们迅速评估了破译与传输每一块密码芯片所需的时间：
小蓝破译第 i 块芯片需要 Ai 时间，而小桥则需要 Bi 时间来传输第 i 块芯片。

此时，小蓝和小桥迫切想要计算出，在最佳的策略下，完成所有密码芯片破译与传输所需的最短时间，请你帮帮他们。

注意：只有一块芯片完成破译后才能开始传输。

输入格式
第一行输入一个整数N(1≤N≤1000) 表示芯片数量。

第二行输入 N 个整数 A1,A2,A3,⋯,AN(1≤Ai≤10^3) 表示小蓝破译每块芯片的时间。

第三行输入 N 个整数 B1,B2,B3,⋯,BN(1≤Bi≤10^3) 表示小桥传输每块芯片密码的时间。

输出格式
输出一个整数表示答案。

输入样例
4
1 3 5 7
6 5 1 4

输出样例
17

说明
两人可以按照 (1,2,4,3) 的芯片编号顺序进行破译传输，所需时间为 17。*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int a, b;
};

bool cmp(Node x, Node y) {
    return min(x.a, y.b) < min(y.a, x.b);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<Node> sz(n + 1); // 索引1~n存储数据

    for (int i = 1; i <= n; i++) cin >> sz[i].a;
    for (int i = 1; i <= n; i++) cin >> sz[i].b;

    sort(sz.begin() + 1, sz.end(), cmp); // 正确排序范围

    int suma = 0;
    int prev_trans_end = 0;

    for (int i = 1; i <= n; ++i) { // 只处理有效元素
        auto& num = sz[i];
        suma += num.a;
        int trans_start = max(prev_trans_end, suma);
        prev_trans_end = trans_start + num.b;
    }

    cout << prev_trans_end << '\n';
    return 0;
}