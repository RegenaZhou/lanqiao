/*
问题描述
蓝桥学院的算法开学考核正在进行中。作为专门考察算法基本功的测试题，导师给小蓝被分配了一个任务：
学院有 N 本课本（编号从 1 到 N），每本课本 i 包含的知识量为 Vi 。
同时，有 M 名同学（编号从 1 到 M），每名同学 j 的知识接受上限为 Sj 。

小明需要将课本分配给同学，每名同学最多分配一本课本，且分配的课本知识量不能超过该同学的接受上限（即Vi≤Sj ）。
目标是使所有同学吸取的总知识量最大化。请帮助小明计算这个最大总知识量。

输入格式
输入的第一行包含两个正整数 N,M(1≤N,M≤10^5)，用一个空格分隔，表示课本数量和同学数量。

第二行包含 N 个正整数V1,V2,…,VN(1≤Vi≤10^5)，相邻整数之间使用一个空格分隔，表示每本课本的知识量。

第三行包含 M 个正整数S1,S2,…,SM(1≤Si≤10^5)，相邻整数之间使用一个空格分隔，表示每名同学的知识接受上限。

输出格式
输出一行包含一个整数，表示所有同学能吸取的最大总知识量。

样例输入
3 2
5 3 4
4 6

样例输出
9

样例说明

例如，将知识量为 5 的课本分配给接受上限为 6 的同学，将知识量为 4 的课本分配给接受上限为 4 的同学，总知识量为 9。*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v, s;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        s.push_back(num);
    }
    sort(v.begin(), v.end());
    sort(s.begin(), s.end());
    int j = n - 1;
    long long sum = 0;
    for (int i = m - 1; i >= 0 && j >= 0; i--)
    {
        while (v[j] > s[i] && j >= 0)
        {
            j--;
        }
        if (j >= 0)
        {
            sum += v[j];
            j--;
        }
    }
    cout << sum << '\n';
    return 0;
}
