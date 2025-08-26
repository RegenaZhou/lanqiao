/*
问题描述
蓝桥学院的算法开学考核正在进行中。小蓝和小桥被班主任分配了一个任务：为班级购置 N 种学习用品（编号从 1 到 N）。
有两家商店可供选择：商店 A 和商店 B，每种学习用品 i 在商店 A 的价格为 Ai 卢比，在商店 B 的价格为 Bi 卢比。

小蓝和小桥每人需要恰好购买 N 种学习用品各一件（即每种用品只买一件）。
他们都希望在购置时满足条件：从商店 A 购买的用品种类数不得少于从商店 B 购买的种类数。
小蓝是个挥霍的学生，他希望以尽可能高的总价购买 N 件用品；
而小桥非常节俭，他希望以尽可能低的总价购买 N 件用品。

请计算小蓝支付的金额与小桥支付的金额分别为多少。

输入格式
输入的第一行包含一个正整数 N(1≤N≤10^5)，表示学习用品的种类数。

第二行包含 N 个正整数A1,A2,…,AN(1≤Ai≤10^9)，相邻整数之间使用一个空格分隔，表示每种学习用品在商店 A 的价格。

第三行包含 N 个正整数B1,B2,…,BN(1≤Bi≤10^9)，相邻整数之间使用一个空格分隔，表示每种学习用品在商店 B 的价格。

输出格式
输出一行包含两个整数，分别表示小蓝支付的金额和小桥支付的金额，用一个空格分隔。

样例输入
3
5 2 3
1 4 2

样例输出
12 6

样例说明
小蓝：选择商店 A 购买用品 1 和 3（价格 5 和 3），商店 B 购买用品 2（价格 4），总价 5+3+4=12。
商店 A 买了 2 种， B 买了 1 种，满足 A 不少于 B。
小桥：选择商店 B 购买用品 1（价格 1），商店 B 购买用品 2 和 （价格 2 和 3），总价 5+4+2=8。
商店 A 买了 2 种， B 买了 1 种，满足 A 不少于 B。*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, jl, minsl;
    ll num, dt, zh = 0, xl = 0, xq = 0;
    cin >> n;
    minsl = (n + 1) / 2;
    vector<ll> sz, cz;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        sz.push_back(num);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        dt = sz[i] - num;
        cz.push_back(dt);
        zh += num;
    }

    sort(cz.begin(), cz.end());

    for (int i = 0; i < n; i++)
    {
        if (cz[i] <= 0) jl = i;
    }

    if (jl + 1 >= minsl)
    {
        for (int i = 0; i <= jl; i++)
        {
            xq += cz[i];
        }
        for (int i = n - minsl; i < n; i++)
        {
            xl += cz[i];
        }
    }
    else
    {
        for (int i = 0; i < minsl; i++)
        {
            xq += cz[i];
        }
        for (int i = jl + 1; i < n; i++)
        {
            xl += cz[i];
        }
    }
    xl += zh, xq += zh;
    cout << xl << " " << xq << '\n';
    return 0;
}