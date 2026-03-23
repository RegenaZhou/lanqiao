/*
题目描述
有一个糊涂人，写了 n 封信和 n 个信封，到了邮寄的时候，把所有的信都装错了信封。求装错信封可能的种类数。

输入描述
有多行读入，每行输入一个正整数 n，表示一种情况。(n≤20)

输出描述
输出相应的答案。

输入输出样例
示例
输入
1
3
4

输出
0
2
9*/
#include <iostream>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    ll a[21] = { 0,0,1,2,9 };
    for (int i = 5; i <= 20; i++)
    {
        a[i] = (i - 1) * (a[i - 1] + a[i - 2]);
    }
    while (cin >> n)
    {
        cout << a[n] << '\n';
    }
    return 0;
}