/*
问题描述
清晨的高铁车厢内，窗外雪原连绵，小蓝摊开手中的行程单 —— 这份行程单由 N 格组成，每一格标记为 L 或 Q。其中，L 代表“必打卡景点”，而 Q 代表“普通景点”。

小蓝希望按照原有顺序对整张行程单进行划分，使所有划分出来的部分加起来正好覆盖整份行程单，每一部分至少包含一个格子。
划分后的每一部分被称作一个“日程块”，每个日程块中必须至少有一个“必打卡景点”。也就是说，每个日程块中至少有一个 L，不能出现单纯由 Q 构成的日程块。

现在，请你统计在满足上述条件下的划分方法总数。答案可能非常大，请对 10^9+7 取模后输出。

输入格式
第一行包含一个整数 N（1≤N≤10^5）。

第二行包含一个长度为 N、仅由大写字母 L 和 Q 组成的字符串 S。

输出格式
输出一个整数，表示将行程单划分为若干连续部分（每部分至少包含一个格子，且每部分中至少有一个 L）的方案总数，对 10^9+7 取模后的结果。

样例输入
3
LQL

样例输出
3*/
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    s = ' ' + s;
    vector<int> pos;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'L') pos.push_back(i);
    }

    ll ans = 1, mood = 1000000007;
    int m = pos.size();
    if (!m)
    {
        cout << "0\n";
        return 0;
    }
    for (int i = 1; i < m; i++)
    {
        ans = ans * (pos[i] - pos[i - 1] + 1) % mood;
    }
    cout << ans << "\n";

    return 0;
}
