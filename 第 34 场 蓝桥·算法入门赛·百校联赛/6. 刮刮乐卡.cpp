/*
问题描述
新年倒计时进入尾声，小蓝手中握着一张特殊的“刮刮乐卡”，卡面上印着一行由 L（礼）与 Q（券）两种符号组成的字符串 S。

根据活动规则，小蓝可以反复执行以下“成对刮除”操作：

在当前字符串中任选一个连续子串 LQ；
将该子串对应的涂层一并刮掉，并将剩余的左右两段按原顺序拼接成新的字符串。
年货兑换系统会根据卡片最终显现出来的字符串按字典序来确定奖品面值。为了赢取更丰厚的年货奖励，小蓝希望通过巧妙地选择每一步要刮除的 LQ 位置，使得最终剩下的字符串在字典序上尽可能最大。

现在，请你帮小蓝计算：在所有可能的刮除操作序列中，能够得到的字典序最大的字符串是什么？

输入格式
输入一个字符串 S（1≤∣S∣≤2×10^5），仅包含字符 L 和 Q。

输出格式
输出一个字符串，表示在所有可能的删除操作序列后能得到的字典序最大的结果。

样例输入 1
LQL

样例输出 1
LQL

样例输入 2
LQQ

样例输出 2
Q*/
#include <iostream>
#include <stack>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    stack<char> st;
    cin >> s;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (st.size() < 2)
            st.push(s[i]);
        else if (s[i] == 'Q')
            st.push('Q');
        else
        {
            char c1 = st.top();
            if (c1 == 'Q')
            {
                st.pop();
                if (!st.empty())
                {
                    char c2 = st.top();
                    if (c2 == 'L')
                    {
                        st.push('Q');
                        st.push(s[i]);
                    }
                }
                else
                {
                    st.push('Q');
                    st.push(s[i]);
                }
            }
            else
            {
                st.push(s[i]);
            }
        }
    }
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    return 0;
}