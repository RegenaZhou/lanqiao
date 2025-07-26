/*
问题描述
小蓝和朋友们正为一场沿海公路旅行精心准备。他们计划驾车游览海滨小镇，感受每一处风景。
为此，他们制定了一份旅行攻略，用符号记录每天的计划：
探险游玩的日子标记为 L，悠闲休息的日子标记为 Q，
于是，这份攻略形成了一个由 L 和 Q 组成的字符串 S。

为了让旅程更舒适，旅行团的领队决定在攻略中选择连续的两天，将这两天的计划都改为休息日 Q，
以便大家在旅途中稍作休整，恢复精力。这个调整必须恰好进行一次，且只能针对连续的两天。

现在，小蓝想知道，通过这样的调整，字符串 S 最终有多少种不同的可能？

输入格式
输入一行，包含一个仅由字符 L 和 Q 组成的字符串 S（2≤∣S∣≤10^5 ，∣S∣ 表示 S 的长度），表示初始的旅行攻略。

输出格式
输出一个整数，表示通过恰好一次调整后，字符串 S 不同可能的数量。

样例输入
LQQQ
copy
样例输出
2

样例说明
经过一次调整后，
S 可能变为 LQQQ 或 QQQQ。*/
#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    getline(cin, s);
    set<pair<int, int>> t;
    for (int i = 0; i < (int)s.size() - 1; i++)
    {
        if (s[i] == 'L' && s[i + 1] == 'L') t.insert({ i,i + 1 });
        else if (s[i] == 'L' && s[i + 1] == 'Q') t.insert({ i,0 });
        else if (s[i] == 'Q' && s[i + 1] == 'L') t.insert({ i + 1,0 });
        else t.insert({ -1,-1 });
    }
    cout << t.size() << endl;
    return 0;
}