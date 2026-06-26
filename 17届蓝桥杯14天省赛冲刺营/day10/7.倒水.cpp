/*
问题描述
小蓝有 n 个装了水的瓶子，从左到右摆放，第 i 个瓶子里装有 ai 单位的水。为了美观，小蓝将水循环染成了 k 种颜色，也就是说，第 i 个瓶子和第 i+k 个瓶子里的水的颜色相同。

小蓝发现有的瓶子里的水太少了，因此他规定如果第 i 个瓶子和第 j 个瓶子中的水颜色相同并且满足 i<j，即可将任意整数单位的水从第 i 个水瓶倒出，倒入第 j 个水瓶中。

小蓝想知道任意次操作后所有瓶子中的水的最小值 min ai 最大可以是多少？

输入格式
输入的第一行包含两个正整数 n,k，用一个空格分隔。

第二行包含 n 个正整数 a1,a2,…,an ，相邻整数之间使用一个空格分隔。

输出格式
输出一行包含一个整数，表示所有瓶子中水的最小值 min ai 的最大可能值。

样例输入
7 3
8 5 5 2 2 3 4

样例输出
3

样例说明
其中一种方案：a1 往 a4  倒入 3 单位；a2 往 a5 倒入 2 单位；a3 往 a6 倒入 1 单位； 最终每个瓶子里的水：5,3,4,5,4,4,4，最小值为 3.

评测用例规模与约定
对于 40% 的评测用例，1≤n,ai≤100;

对于所有评测用例，1≤n,ai≤100000, 1≤k≤n。*/
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
ll n, k;
int arr[100009];
bool check(ll x)
{
    for (int i = 0; i < k; i++)
    {
        ll hou = 0;
        for (int j = i; j < n; j += k)
        {
            if (arr[j] + hou >= x) hou = arr[j] + hou - x;
            else return false;
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ll l = 0, r = 100001;
    while (l < r)
    {
        ll mid = (l + r + 1) / 2;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << '\n';
    return 0;
}
