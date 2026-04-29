/*
问题描述
小蓝最近学习了红黑树，红黑树是一种特殊的二叉树，树上的结点有两种类型：红色结点和黑色结点。

小蓝在脑海中构造出一棵红黑树，构造方式如下：

根结点是一个红色结点；
如果当前结点 curNode 是红色结点，那么左子结点 curNode.left 是红色结点，右子结点 curNode.right 是黑色结点；
如果当前结点 curNode 是黑色结点，那么左子结点 curNode.left 是黑色结点，右子结点 curNode.right 是红色结点。
此二叉树前几层的形态如图所示:

图片描述

小蓝会从树上随机挑选结点，请判断他选出的是红色结点还是黑色结点。

输入格式
输入的第一行包含一个正整数 m，表示小蓝挑选的结点数。

接下来 m 行，每行包含两个正整数 ni,ki ，用一个空格分隔，表示小蓝挑选的结点是第 ni 行（从上往下数）第 ki 个（从左往右数）结点。

输出格式
输出 m 行，每行包含一个字符串，依次表示小蓝每次挑选的结点的颜色。

RED 表示红色结点，
BLACK 表示黑色结点。

样例输入
2
1 1
2 2

样例输出
RED
BLACK

样例说明
根据红黑树的构造规则：

第一行第一个结点为根结点，是红色结点；
第二行第二个结点为黑色结点。
评测用例规模与约定 20% 的评测用例，1≤m≤5, 1≤ni≤5;

对于 40% 的评测用例，1≤m≤10, 1≤ni≤5;

对于 60% 的评测用例，1≤m≤5, 1≤ni≤10;

对于 80% 的评测用例，1≤m≤10, 1≤ni≤15;

对于所有评测用例，1≤m≤10, 1≤ni≤30, 1≤ki≤2^(ni−1) .*/
#include <iostream>
using namespace std;
void solve()
{
    int n, k, cnt = 0, fa;
    cin >> n >> k;
    while (k != 1)
    {
        if (k % 2 == 1)
        {
            fa = (k + 1) / 2;
        }
        else
        {
            fa = k / 2;
            cnt++;
        }
        k = fa;
    }

    if (cnt % 2 == 1)
    {
        cout << "BLACK\n";
    }
    else
    {
        cout << "RED\n";
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m;
    cin >> m;
    while (m--)
    {
        solve();
    }
    return 0;
}
/*
               1
       1               0
   1       0       0       1
 1   0   0   1   0   1   1   0
1 0 0 1 0 1 1 0 0 1 1 0 1 0 0 1
jj b
jo r
oj b
oo r
xj b
xo r*/