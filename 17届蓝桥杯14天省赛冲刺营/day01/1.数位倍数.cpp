/*
问题描述
请问在 1 至 202504（含）中，有多少个数的各个数位之和是 5 的整数倍。

例如：5、19、8025 都是这样的数。

输入格式
无。

输出格式
这是一道结果填空题，你只需要算出结果后提交即可。本题的结果为一个整数，在提交答案时只填写这个整数，填写多余的内容将无法得分。

运行限制*/
#include <iostream>
using namespace std;
using ll = long long;
bool solve(int n)
{
    int su = 0;
    while (n)
    {
        su += n % 10;
        n /= 10;
    }
    if (su % 5 == 0) return true;
    else return false;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int ans = 0;
    for (int i = 5; i <= 202504; i++)
    {
        if (solve(i)) ans++;
    }
    cout << ans << '\n';//40500
    return 0;
}
