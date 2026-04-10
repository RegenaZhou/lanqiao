/*
题目描述
斐波那契数列（Fibonacci sequence），又称黄金分割数列，因数学家莱昂纳多·斐波那契（Leonardoda Fibonacci）以兔子繁殖为例子而引入，故又称为“兔子数列”，其指的是这样一个数列：
0、1、1、2、3、5、8、13、21、34、⋯

在数学上，斐波那契数列以如下被以递推的方法定义： F(0)=0，F(1)=1,F(n)=F(n−1)+F(n−2)（n≥2，n∈N∗）

现给定一个正整数 n，请求出该数列中第 n 项的值是多少。

输入描述
输入仅 1 行，包含一个整数 N。

0≤N≤25。

输出描述
输出一个整数，表示答案。

输入输出样例
示例
输入
3

输出
2*/
#include <iostream>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    if (n <= 1)
    {
        cout << n << '\n';
    }
    else
    {
        ll a = 0, b = 1;
        for (int i = 1; i <= n - 1; i++)
        {
            ll temp = a;
            a = b;
            b += temp;
        }
        cout << b << '\n';
    }
    return 0;
}
