/*
本题为填空题，只需要算出结果后，在代码中使用输出语句将所填结果输出即可。

问题描述
小蓝每周六、周日都晨跑，每月的 1、11、21、31 日也晨跑。其它时间不晨跑。

已知 2022 年 1 月 1 日是周六，请问小蓝整个 2022 年晨跑多少天？*/
#include <iostream>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }, ans = 0;
    for (int i = 1; i <= 365; i++)
    {
        int cpi = i;
        bool flag = false;
        if (cpi % 7 == 1 || cpi % 7 == 2) flag = true;
        int b = 0;
        while (1)
        {
            if (cpi <= month[b] || b > 11) break;
            cpi -= month[b];
            b++;
        }
        if (cpi == 1 || cpi == 11 || cpi == 21 || cpi == 31) flag = true;
        if (flag)
        {
            ans++;
        }
    }
    cout << ans << '\n';//138
    return 0;
}
