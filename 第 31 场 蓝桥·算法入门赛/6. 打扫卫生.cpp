/*
问题描述
国庆节庆典即将拉开帷幕，整座城市都沉浸在欢乐的氛围中。作为一名志愿者，小蓝接到了一个重要任务：确保庆典主干道的卫生干净。

这条主干道可以看作一条无限长的数轴，小蓝位于中心位置 0。巡视后，他发现路面上散落着 N 处需要清理的垃圾，其位置分别由坐标 A1,A2,…,AN 表示。
根据庆典卫生标准，他至少要清理掉 M 处垃圾才算完成任务。

小蓝从位置 0 出发，他可以选择任意 M 处或更多的垃圾进行清理。时间紧迫，庆典马上就要开始。现在，请你帮助小蓝计算，为了收集至少 M 处垃圾，他需要行走的最小距离是多少？

输入格式
第一行包含两个整数 M 和 N（1≤M≤N≤2×10^5）。

第二行包含 N 个整数 A1,A2,…,AN（−10^9≤Ai≤10^9），表示一处垃圾的坐标位置。数据保证所有 Ai互不相同。

输出格式
输出一个整数，代表小蓝需要行走的最短距离。

样例输入
3 3
1 2 3

样例输出
3*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m, n;
    cin >> m >> n;
    vector<ll> zs, fs;
    zs.push_back(0);
    fs.push_back(0);
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        if (a >= 0) {
            zs.push_back(a);
        }
        else {
            fs.push_back(-a);
        }
    }
    sort(zs.begin(), zs.end());
    sort(fs.begin(), fs.end());
    int zs_size = zs.size() - 1;
    int fs_size = fs.size() - 1;
    ll ans = 1e18;
    for (int i = 0; i <= m; i++)
    {
        if (i > zs_size || m - i > fs_size) {
            continue;
        }
        ans = min(ans, 2 * zs[i] + fs[m - i]);
        ans = min(ans, zs[i] + 2 * fs[m - i]);
    }
    cout << ans << '\n';
    return 0;
}