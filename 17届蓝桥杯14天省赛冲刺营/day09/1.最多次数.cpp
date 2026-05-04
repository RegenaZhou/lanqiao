/*
问题描述
小蓝有一个字符串 s，他特别喜欢由以下三个字符组成的单词：l,q,b，任意顺序都可以，一共有 6 种可能：lqb、lbq、qlb、qbl、blq、bql。

现在他想从 s 中，尽可能切割出多个他喜欢的单词，请问最多能切割出多少个？单词指的是由若干个连续的字符组成的子字符串。

输入格式
输入一行包含一个字符串 s。

输出格式
输出一行包含一个整数表示答案。

样例输入
lqbblqblqlxqb

样例输出
3

评测用例规模与约定
对于 20% 的评测用例，1≤∣s∣≤10；

对于 40% 的评测用例，1≤∣s∣≤20；

对于 60% 的评测用例，1≤∣s∣≤100；

对于 70% 的评测用例，1≤∣s∣≤10^3；

对于 80% 的评测用例，1≤∣s∣≤10^4；

对于所有评测用例，1≤∣s∣≤10^5，s 中只包含小写字母。*/
#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int len = s.size(), id = 0, ans = 0;
    while (id <= len - 3)
    {
        string s1 = s.substr(id, 3);
        if (s1 == "lqb" || s1 == "lbq" || s1 == "qlb" || s1 == "qbl" || s1 == "blq" || s1 == "bql")
        {
            ans++;
            id += 3;
        }
        else
        {
            id++;
        }
    }
    cout << ans << '\n';
    return 0;
}