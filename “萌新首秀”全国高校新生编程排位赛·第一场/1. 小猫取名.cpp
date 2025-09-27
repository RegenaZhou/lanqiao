/*
问题描述
小蓝最近喜添一只可爱的小猫，正为给它取一个长度恰好为 6 的名字而绞尽脑汁。
为了集思广益，他邀请了 6 位朋友帮忙，每位朋友各自想一个单词。
小蓝计划将这 6 个单词的首字母按顺序拼接起来，组成小猫的名字。

朋友们提供的单词分别记为W1,W2,W3,W4,W5,W6。例如，朋友们提供的单词依次是 agile，brave，cute，delightful，energetic，fluffy，那么小猫的名字将是 "abcdef"。

现在，请你编写一个程序，根据朋友们提供的单词，生成小猫的名字。

输入格式
输入共 6 行，每行包含一个长度不超过 10、仅由小写字母构成的字符串，表示朋友提供的单词。

输出格式
输出一个长度为 6 的字符串，表示小猫的名字。

样例输入
agile
brave
cute
delightful
energetic
fluffy

样例输出
abcdef*/
#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    for (int i = 0; i < 6; i++)
    {
        string s;
        cin >> s;
        cout << s[0];
    }
    return 0;
}