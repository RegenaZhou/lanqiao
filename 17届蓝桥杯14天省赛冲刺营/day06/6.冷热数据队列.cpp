/*
问题描述
小蓝是一名计算机专业的学生，最近他学习了《操作系统》、《数据结构》等课程，设计了一种名为“冷热数据队列”的数据结构来管理数据页。

冷热数据队列 q 由两个子队列组成：长度为 n1 的热数据队列 q1 和长度为 n2 的冷数据队列 q2 。当需要访问某个数据页 p 时：

1）若 p 不在队列 q 中（即既不在 q1 中，也不在 q2 中），则加载数据页 p，并插入到 q2 的首部。

2）若 p 已经在队列 q 中，则将 p 移动至 q1 首部。

3）当 q1 或 q2 队列容量不足时，会将其尾部的数据页淘汰出去。

4）当 q1 已满但 q2 未满时，从 q1 中淘汰出的数据页会移动到 q2 首部。

输入格式
输入的第一行包含两个正整数 n1,n2 ，用一个空格分隔。

第二行包含一个整数 m，表示操作次数。

第三行包含 m 个正整数 v1,v2,…,vm ，表示依次访问到的数据页的编号，相邻整数之间使用一个空格分隔。

输出格式
输出两行。

第一行包含若干个整数，相邻整数之间使用一个空格分隔，依次表示 q1 中的数据页。

第二行包含若干个整数，相邻整数之间使用一个空格分隔，依次表示 q2 中的数据页。

样例输入
3 3
10
1 2 3 4 3 2 2 1 3 4

样例输出
4 3 2
1

样例说明
i	vi	q1		q2
-	-	[]		[]
1	1	[]		[1]
2	2	[]		[2,1]
3	3	[]		[3,2,1]
4	4	[]		[4,3,2]
5	3	[3]		[4,2]
6	2	[2,3]	[4]
7	2	[2,3]	[4]
8	1	[2,3]	[1,4]
9	3	[3,2]	[1,4]
10	4	[4,3,2]	[1]
评测用例规模与约定
对于 20% 的评测用例， 1≤n1,n2≤10 , 1≤m≤10;

对于 40% 的评测用例， 1≤n1,n2≤20 , 1≤m≤100;

对于 60% 的评测用例， 1≤n1,n2≤100 , 1≤m≤1000;

对于 80% 的评测用例， 1≤n1,n2≤10^3 , 1≤m≤10^4;

对于所有评测用例， 1≤n1,n2≤10^4 , 1≤m≤10^5 , 0≤vi≤10^4 。*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n1, n2, m, num;
    cin >> n1 >> n2 >> m;
    vector<int> q1, q2;
    for (int i = 0; i < m; i++)
    {
        cin >> num;
        auto inq1 = find(q1.begin(), q1.end(), num);
        auto inq2 = find(q2.begin(), q2.end(), num);

        if (inq1 == q1.end() && inq2 == q2.end())
        {
            q2.insert(q2.begin(), num);
        }
        else
        {
            if (inq2 != q2.end())
            {
                q2.erase(inq2);
                q1.insert(q1.begin(), num);
            }
            else
            {
                q1.erase(inq1);
                q1.insert(q1.begin(), num);
            }
        }

        if (q1.size() > n1)
        {
            num = q1.back();
            q1.pop_back();
            if (q2.size() < n2)
            {
                q2.insert(q2.begin(), num);
            }
        }

        if (q2.size() > n2)
        {
            q2.pop_back();
        }
    }

    bool flag = false;
    for (auto const& num : q1)
    {
        if (flag) cout << " ";
        flag = true;
        cout << num;
    }
    cout << '\n';

    flag = false;
    for (auto const& num : q2)
    {
        if (flag) cout << " ";
        flag = true;
        cout << num;
    }

    return 0;
}