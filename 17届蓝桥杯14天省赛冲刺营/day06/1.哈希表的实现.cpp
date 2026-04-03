/*
问题描述
给定一个集合与 q 次操作，每次操作具体如下：

I x：在集合中插入一个值为 x 的数。

Q x：查询 x 是否在集合中出现过。

输入格式
第一行输入一个正整数 q，表示查询次数。(1≤q≤10^5)

接下来 q 行，每行输入代表依次进行一个操作。(1≤x≤10^9)

输出格式
对于每组查询，如果 x 出现过， 则输出 Yes，否则输出 No。

样例输入
7
I 1
Q 5
I 2
Q 4
I 4
Q 4
Q 3

样例输出
No
No
Yes
No
*/
#include <iostream>
#include <set>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q;
    cin >> q;
    set<int> st;
    while (q--)
    {
        char c;
        int num;
        cin >> c >> num;
        if (c == 'I')
        {
            st.insert(num);
        }
        else
        {
            cout << (st.find(num) == st.end() ? "No" : "Yes") << '\n';
        }
    }
    return 0;
}