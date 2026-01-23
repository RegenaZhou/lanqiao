/*
问题描述
圣诞节即将来临，蓝桥广场上点缀着 n 盏绚丽的花灯，以庆祝这个欢乐的节日。起初，每盏花灯都处于关闭状态。

为了增添互动乐趣，主办方随机挑选了 k 位幸运游客，每位游客可以选择花灯序列的一个前缀（从第 1 盏到第 p 盏），并将这些花灯的状态全部反转：原本关闭的灯会亮起，亮起的灯则会熄灭。
如果游客们通过这些操作，最终使所有花灯的状态与主办方预设的图案 S 完全匹配，那么他们就能集体获得一份精美的圣诞礼品。

当然，游客们可以任意调整操作的执行顺序，以找到最佳组合。聪明的小蓝作为游客中的智囊，被大家邀请来帮忙判断：给定主办方指定的最终图案 S 和游客们各自选择的 p 值，
是否存在一种操作排列顺序，能够让花灯效果最终达到图案 S，若可以则输出 Yes，否则输出 NO。

输入格式
第一行输入两个整数 n,k(1≤n,k≤10^5) 表示花灯数量和幸运游客数量。

第二行输入一个长度为 n 的 01 字符串 S 表示主办方的目标图案，若 Si 为 1 则表示第 i 盏灯亮起，否则为关闭。

第三行输入一个长度为 k 的数组 p1,p2,p3⋯pk(1≤pi≤n) 表示每位游客选择的前缀。

输出格式
若存在某种操作顺序使得花灯效果最终达到图案 S 则输出 Yes，否则输出 No。

样例输入
5 3
10010
4 3 1

样例输出
Yes

说明
对于样例来说，无需调整，按照初始游客的操作顺序即可使得花灯效果达到图案 S。*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int n, k;
    string mbs, ns = "";
    bool flag;
    cin >> n >> k;
    vector<int> arr(k);
    flag = (k % 2 == 1 ? true : false);
    cin >> mbs;
    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < k; i++)
    {
        if (i == 0)
        {
            ns = ns + string(arr[i], (flag ? '1' : '0'));
        }
        else
        {
            flag = !flag;
            ns = ns + string(arr[i] - arr[i - 1], (flag ? '1' : '0'));
        }
    }
    flag = !flag;
    ns = ns + string(n - arr[k - 1], (flag ? '1' : '0'));
    if (ns == mbs)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}