/*
问题描述
蓝桥学院最近组织了一场冬季旅行，打算组织 N 名同学去冰雪奇缘大世界游玩。

为了方便出行，学院租了一辆座位数量恰好为N 的大巴，座位编号依次为 1,2,⋯,N，其中第 i(1≤i≤N) 个座位上的同学初始学号为 Ai。

大巴司机给同学们提了一个要求，希望每个座位上的同学学号都不小于座位编号。

大巴司机允许同学们互相交换位置任意次数。请你帮同学们判断能否通过交换位置满足大巴司机的要求，如果能则输出 YES，否则输出 NO。

输入格式
第一行包含一个整数 N（1≤N≤10^5），表示同学和座位的数量。

第二行包含 N 个整数 A1,A2,⋯,AN（1≤Ai≤N），表示初始座位上的同学学号。

输出格式
输出一行：如果能满足要求则输出 YES，否则输出 NO。

样例输入
3
1 2 3

样例输出
YES

样例输入2
3
1 3 2

样例输出2
YES

样例输入3
3
1 1 2

样例输出3
NO*/
#include <iostream>
#include <map>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, num;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        mp[num]++;
    }

    ll cur = 0, sum = 0;
    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        cur++;
        sum += mp[i];
        if (sum > cur)
        {
            flag = false;
            break;
        }
    }

    if (flag)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}