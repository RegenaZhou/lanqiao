﻿/*
问题描述
射手星座正遭受来自外星系的攻击！星座中有N户居民排成一条直线，
第i户居民有Ai人。只有当某户居民人数不少于M时，
该户才能形成防护罩抵御攻击。

国王可以进行迁移操作：每次选择某一户的所有居民，
将他们整体迁移到相邻的左边或右边住户。
由于每次迁移都会消耗大量资源，请计算最少需要多少次迁移，
才能使所有住户都形成防御罩低于攻击。

如果无论如何都无法实现，输出−1。

注意：两户居民合并后为一户，不会存在一个空的户。

输入格式
第一行两个整数N,M(1≤N≤10^5,1≤M≤10^9) 表示射手星座居民数量以及开始防御罩的需要人数。

第二行N 个整数A1,A2,⋯,AN(1≤Ai≤10^4)表示每户居民的数量。

输出格式
输出一个整数表示答案。

样例输入
6 3
1 1 2 3 2 1

样例输出
3

说明
将1,2,3 户居民合并为1户，需要迁移2次。
将5,6户居民合并为1户，需要迁移1次。
最终居民分布为[4,3,3]，可以抵御住攻击，总共需要迁移3次。*/
#include <iostream>
#include<vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, js = 0, sum = 0;
    cin >> n >> m;
    vector<int> sz(n);
    for (int i = 0; i < n; i++)
    {
        cin >> sz[i];
    }

    for (int i = 0; i < n; i++)
    {
        sum += sz[i];
        if (sum >= m)
        {
            sum = 0;
            js++;
        }
    }
    if (js) cout << n - js << '\n';
    else cout << "-1" << '\n';
    return 0;
}