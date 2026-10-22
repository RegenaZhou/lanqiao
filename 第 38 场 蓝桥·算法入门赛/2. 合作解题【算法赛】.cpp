/*
问题描述
暑假集训期间，老师准备了 n 道编程题，并给了小蓝 m 分钟的总训练时间。

小蓝独立解决一道题需要花费 x 分钟。如果小蓝和小桥一起合作解决一道题，则需要花费 y 分钟。

但小桥认为男女授受不亲，于是最多只愿意和小蓝一起合作解决 z 道题。

请问，在不超过总训练时间的前提下，小蓝最多可以解决多少道题。

输入格式
一行四个整数 n,m,x,y,z(1≤y≤x≤1000,1≤n,m,z,≤1000)，分别表示题目总数、总时间、独立解题时间、合作解题时间和小桥最多愿意合作的题数。

输出格式
输出一个整数，表示小蓝最多可以解决的题目数量。

样例输入
10 100 15 8 3

样例输出
8*/
#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, x, y, z, num, ans;
	cin >> n >> m >> x >> y >> z;
	num = m / y;
	if (num > z) num = z;
	if (num > n) num = n;
	if ((m - y * num) / x + num > n) ans = n;
	else ans = (m - y * num) / x + num;
	cout << ans << '\n';
	return 0;
}