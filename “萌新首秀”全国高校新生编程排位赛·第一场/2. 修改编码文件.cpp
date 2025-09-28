/*
问题描述
小蓝得到了一份编码文件，文件内容是一个由小写字母 a∼z 和数字 0∼9 组成的字符串。他计划将字母替换为 L，数字替换为 Q，生成一份新的输出文件，请你帮帮他。

输入格式
输入仅一行，包含一个仅由小写字母 a∼z 和数字 0∼9 组成字符串，长度不超过 10^5。

输出格式
输出一行，为替换后的字符串。

样例输入
lanqiao2025

样例输出
LLLLLLLQQQQ*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z') cout << "L";
        else if (s[i] >= '0' && s[i] <= '9') cout << "Q";
    }
    return 0;
}