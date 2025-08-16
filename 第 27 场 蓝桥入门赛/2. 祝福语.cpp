/*
问题描述
三月八日国际劳动妇女节即将来临，小蓝和小桥都想为自己的母亲送上一份特别的节日祝福。

小蓝已经用心准备了一条充满深情的祝福语，用仅包含小写字母的字符串 S 表示。
小桥同样希望表达对母亲的爱意，但为了避免与小蓝的祝福语重复，她决定设计一条独特的祝福语 T，
要求 T 不能是 S 的一部分（即 T 不是 S 的子串）。
同时，T 也必须仅由小写字母构成。

为了让祝福语更具新意，小桥还希望在所有满足上述条件的祝福语中，T 的字典序是最小的。

输入格式
输入一行，包含一个仅由小写字母构成的字符串 S（1≤∣S∣≤10^5），表示小蓝的祝福语。

输出格式
输出一个仅由小写字母构成的字符串 T，表示小桥的祝福语。

样例输入
aab

样例输出
aaa*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    int i;
    cin >> s;
    /*for(i=0;i<s.size();i++)
    {
      if(s[i]=='a')cout<<s[i];
      else
      {
        cout<<char(s[i]-1);
        break;
      }
    }
    if(s[s.size()-1]=='a' && i==s.size()) cout<<'a';*/
    int js = 0;
    int ans = 0;
    for (auto a : s)
    {
        if (a == 'a')
        {
            js++;
            ans = max(ans, js);
        }
        else js = 0;
    }
    cout << string(ans + 1, 'a');
    return 0;
}