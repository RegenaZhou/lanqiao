/*
问题描述
小蓝面临一个数学问题：定义一个函数 f(x) 如下：
f(x)={	2×x×f(x−6)(x>10)
		x×(x−1)(x≤10)
​


现在给定一个整数 n，小蓝想知道 f(n) 对 998244353 取模的结果。

输入格式
输入包含一个整数 n，表示函数 f 的参数。

输出格式
输出一个整数，表示 f(n) 对 998244353 取模的结果。

样例输入
15

样例输出
2160

评测数据范围
1≤n≤10^5 。*/
#include <iostream>
using namespace std;
using ll = long long;
const ll mood = 998244353;
ll func(ll x)
{
	if (x > 10) return (2 * x * func(x - 6)) % mood;
	else return (x * (x - 1)) % mood;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n;
	cin >> n;
	ll ans = func(n);
	cout << ans << '\n';
	return 0;
}
