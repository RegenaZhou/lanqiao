/*
问题描述
小蓝是一名宇宙飞船的航行舰长，正执行从星球 X 飞往星球 Y 的任务。
根据预计的行程时间，他需要在 N 天内完成这次航行。飞船的动力来源于两种燃油：
A 和 B。然而，每一天的路况不同，导致燃油的消耗量也有所变化。

对于每一天 i，使用燃油 A 的消耗量为Ai ，而使用燃油 B 的消耗量则为 Bi 。
小蓝可以在旅程开始前随意选择一种燃油，并且在航行的某一天进行一次燃油替换。

现在，小蓝希望计算出在这趟旅程中，飞船最少需要消耗多少燃油。

注意：替换操作最多只能进行一次。

输入说明
第一行包含一个整数 N(1≤N≤10^5 )，表示航行的天数。

第二行包含 N 个整数A1,A2,…,AN(1≤Ai≤10^9)，表示使用燃油 A 的每日消耗量。

第三行包含 N 个整数B1,B2,…,BN(1≤Bi≤10^9) ，表示使用燃油 B 的每日消耗量。

输出格式
输出一个整数，表示飞船在这趟旅程中最少需要消耗的燃油量。

输入样例1
5
1 2 3 4 5
5 4 3 2 1

输出样例1
9

说明
在这个样例中，小蓝可以选择在第 1,2,3 天使用燃油 A，第 4,5 天使用燃油 B。
这样，燃油消耗量为 1+2+3+2+1=9，这是最少的消耗量。*/
#include <iostream>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
ll sa[N], sb[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    ll sc = 0x3f3f3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        cin >> sa[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> sb[i];
    }
    for (int i = 1; i <= n; i++)
    {
        sa[i] = sa[i] + sa[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        sb[i] = sb[i] + sb[i - 1];
    }
    for (int i = 0; i <= n; i++)
    {
        sc = min(sc, sa[i] + sb[n] - sb[i]);
        sc = min(sc, sb[i] + sa[n] - sa[i]);
    }
    cout << sc << '\n';
    return 0;
}