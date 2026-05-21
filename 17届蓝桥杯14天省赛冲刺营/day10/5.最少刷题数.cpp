/*
问题描述
小蓝老师教的编程课有 N 名学生, 编号依次是 1…N 。第 i 号学生这学期 刷题的数量是 Ai 。

对于每一名学生, 请你计算他至少还要再刷多少道题, 才能使得全班刷题 比他多的学生数不超过刷题比他少的学生数。

输入格式
第一行包含一个正整数 N 。

第二行包含 N 个整数: A1,A2,A3,…,AN.

输出格式
输出 N 个整数, 依次表示第 1…N 号学生分别至少还要再刷多少道题。

样例输入
5
12 10 15 20 6

样例输出
0 3 0 0 7

评测用例规模与约定
对于 30% 的数据, 1≤N≤1000,0≤Ai≤1000.

对于 100% 的数据, 1≤N≤100000,0≤Ai≤100000.*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node
{
    int id;
    int num;
};
bool cmp1(Node a, Node b)
{
    return a.num < b.num;
}
bool cmp2(Node a, Node b)
{
    return a.id < b.id;
}

int n;
vector<Node> arr;

bool solve(int mid)
{
    int daid = mid, xiaoid = mid;
    for (int i = mid + 1; i < n; i++)
    {
        if (arr[i].num != arr[mid].num)
        {
            daid = i;
            break;
        }
    }
    for (int i = mid - 1; i >= 0; i--)
    {
        if (arr[i].num != arr[mid].num)
        {
            xiaoid = i;
            break;
        }
    }
    return (n - 1 - daid) <= xiaoid;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    arr.resize(n);

    for (int i = 0; i < n; i++)
    {
        arr[i].id = i;
        cin >> arr[i].num;
    }

    sort(arr.begin(), arr.end(), cmp1);

    int l = 0, r = n - 1;
    while (l + 1 != r)
    {
        int mid = (l + r) / 2;
        if (solve(mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }

    int xiaoid = r, daid = r;
    int ans = arr[r].num;
    for (int i = r; i >= 0; i--)
    {
        if (arr[i].num != ans)
        {
            xiaoid = i;
            break;
        }
    }
    for (int i = r; i < n; i++)
    {
        if (arr[i].num != ans)
        {
            daid = i;
            break;
        }
    }

    int less = xiaoid + 1, more = n - daid;

    sort(arr.begin(), arr.end(), cmp2);
    for (int i = 0; i < n; i++)
    {
        if (i != 0) cout << " ";
        if (arr[i].num < ans)
        {
            if (less - 1 >= more)
            {
                cout << ans - arr[i].num;
            }
            else
            {
                cout << ans - arr[i].num + 1;
            }
        }
        else
        {
            cout << "0";
        }
    }

    return 0;
}
