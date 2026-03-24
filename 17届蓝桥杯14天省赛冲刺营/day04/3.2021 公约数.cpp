/*
题目描述
本题为填空题，只需要算出结果后，在代码中使用输出语句将所填结果输出即可。

如果一个整数 g 能同时整除整数 A 和 B，则称 g 是 A 和 B 的公约数。例如：43 是 86 和 2021 的公约数。

请问在 1（含） 到 2021（含） 中，有多少个数与 2021 存在大于 1 的公约数。请注意 2021 和 2021 有大于 1 的公约数，因此在计算的时候要算一个。*/
#include <iostream>
using namespace std;
int func(int x, int y)
{
    while (x % y)
    {
        int temp = x % y;
        x = y, y = temp;
    }
    return (y > 1 ? 1 : 0);
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int ans = 0;
    for (int i = 2; i <= 2021; i++)
    {
        ans += func(2021, i);
    }
    cout << ans << '\n';
    return 0;
}